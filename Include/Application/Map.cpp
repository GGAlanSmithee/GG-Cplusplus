#include <fstream>
#include "Map.h"
#include "Utility/Exception.h"

GG_Map::GG_Map(const unsigned int tilesetId,
               const unsigned int size,
               std::vector<std::vector<GG_Tile>> const& tiles) :
    tilesetId(tilesetId),
    size(size),
    tiles(tiles)
{
    boundary = { 0.0f, 0.0f, size, size };
}

GG_Map::~GG_Map()
{

}

GG_Rect const& GG_GetBoundary(GG_Map const& map)
{
    return map.boundary;
}

const int GG_GetTilesetId(GG_Map const& map)
{
    return map.tilesetId;
}

GG_Tile const& GG_GetTile(GG_Map const& map, const int x, const int y)
{
    if (y > GG_GetBoundary(map).h || x > GG_GetBoundary(map).w)
    {
        throw std::invalid_argument("cannot get a tile that is outside the maps boundary");
    }

    return map.tiles[y][x];
}

void GG_RenderMap(GG_Map const& map,
                  std::unique_ptr<GG_Renderer> const& renderer,
                  std::unique_ptr<GG_TextureManager> const& textureManager,
                  GG_Vec2f const& cameraPos,
                  GG_Rect const& cameraRect)
{
    auto boundary = GG_GetBoundary(map);

    if (!(cameraPos.x + cameraRect.w >= boundary.x && cameraPos.x <= boundary.x + boundary.w &&
          cameraPos.y + cameraRect.h >= boundary.y && cameraPos.y <= boundary.y + boundary.h))
    {
        return;
    }

    auto startX = cameraPos.x < 0 ? 0 : static_cast<int>(cameraPos.x);
    auto endX   = cameraPos.x + cameraRect.w + 2 > boundary.w ? boundary.w : static_cast<int>(cameraPos.x + cameraRect.w + 2);
    auto startY = cameraPos.y < 0 ? 0 : static_cast<int>(cameraPos.y);
    auto endY   = cameraPos.y + cameraRect.h + 2 > boundary.h ? boundary.h : static_cast<int>(cameraPos.y + cameraRect.h + 2);

    SDL_Rect src = { 1, 1, 1, 1 };

    auto texture = GG_GetTexture(textureManager, GG_GetTilesetId(map));

    for (auto y = startY; y < endY; ++y)
    {
        for (auto x = startX; x < endX; ++x)
        {
            auto tile = GG_GetTile(map, x, y);

            src.x = GG_GetTileNumber(tile);

            auto dest = GG_GetBoundary(GG_GetTile(map, x, y));

            dest.x -= cameraPos.x;
            dest.y -= cameraPos.y;

            GG_RenderTexture(renderer, texture, GG_ToView(renderer, src), GG_ToView(renderer, dest));
        }
    }
}

const GG_Map GG_LoadMap(std::unique_ptr<GG_TextureManager> const& textureManager, std::string const& filepath)
{
    if (!textureManager)
    {
        throw std::invalid_argument("texture manager cannot be null.");
    }

    std::ifstream map(filepath);

    if (map == nullptr)
    {
        throw file_not_found_error("Could not find map with path " + filepath);
    }

    std::string tilesetName;

    map >> tilesetName;

    if (map.fail())
    {
        throw std::runtime_error("Error loading map.");
    }

    int mapSize;

    map >> mapSize;

    if (map.fail())
    {
        throw std::runtime_error("Error loading map.");
    }

    int tileNumber;
    SDL_Rect tileBoundary;
    std::vector<std::vector<GG_Tile>> tiles;

    for (auto y = 0; y < mapSize; ++y)
    {
        std::vector<GG_Tile> tilesRow;

        for (auto x = 0; x < mapSize; ++x)
        {
            map >> tileNumber;

            tileBoundary = { x, y, 1, 1 };

            tilesRow.push_back(GG_Tile(tileBoundary, tileNumber, GG_TileType::Normal, GG_CollisionType::Box));
        }

        tiles.push_back(tilesRow);
    }

    return GG_Map(GG_GetTextureId(textureManager, tilesetName), mapSize, tiles);
}
