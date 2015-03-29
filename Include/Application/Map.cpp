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

void GG_Render(GG_Map const& map,
               std::unique_ptr<GG_Renderer> const& renderer,
               std::unique_ptr<GG_TextureManager> const& textureManager,
               GG_Vec2f const& cameraPos,
               GG_Rect const& cameraRect)
{
    auto boundary = GG_GetBoundary(map);

    auto startX = cameraPos.x - (cameraRect.w / 2);
    auto endX   = startX + cameraRect.w + 1;
    auto startY = cameraPos.y - (cameraRect.h / 2);
    auto endY   = startY + cameraRect.h + 1;

    if (!(endX >= boundary.x && startX <= boundary.x + boundary.w &&
          endY >= boundary.y && startY <= boundary.y + boundary.h))
    {
        return;
    }

    startX = startX >= 0 ? startX : 0;
    endX = endX < boundary.w ? endX : boundary.w;
    startY = startY >= 0 ? startY : 0;
    endY = endY < boundary.h ? endY : boundary.h;

    GG_Rect src = { 1, 1, 1, 1 };

    auto texture = GG_GetTexture(textureManager, GG_GetTilesetId(map));

    for (auto y = startY; y < endY; ++y)
    {
        for (auto x = startX; x < endX; ++x)
        {
            auto tile = GG_GetTile(map, x, y);

            src.x = GG_GetNumber(tile);

            auto dest = GG_GetBoundary(GG_GetTile(map, x, y));

            dest.x -= cameraPos.x - (cameraRect.w / 2);
            dest.y -= cameraPos.y - (cameraRect.h / 2);

            GG_RenderTexture(renderer, texture, src, dest);
        }
    }

    auto window = GG_GetWindowLogicalSize(renderer);

    GG_Rect cornerRect =
            {
                window.w - (window.w / 4.0f),
                0.0f,
                window.w / 4.0f,
                window.h / 4.0f
            };

    GG_SetViewPort(renderer, cornerRect);
    GG_RenderRect(renderer, window, { 0, 0, 0, 255 });

    for (auto y = startY; y < endY; ++y)
    {
        for (auto x = startX; x < endX; ++x)
        {
            auto tile = GG_GetTile(map, x, y);

            src.x = GG_GetNumber(tile);

            auto dest = GG_GetBoundary(GG_GetTile(map, x, y));

            dest.x -= cameraPos.x;
            dest.y -= cameraPos.y;

            dest.x /= 8.0f;
            dest.y /= 8.0f;
            dest.w /= 8.0f;
            dest.h /= 8.0f;

            GG_RenderTexture(renderer, texture, src, dest);
        }
    }

    GG_SetViewPort(renderer);
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
    GG_Rect tileBoundary;
    std::vector<std::vector<GG_Tile>> tiles;

    for (auto y = 0; y < mapSize; ++y)
    {
        std::vector<GG_Tile> tilesRow;

        for (auto x = 0; x < mapSize; ++x)
        {
            map >> tileNumber;

            tileBoundary = { x, y, 1, 1 };

            tilesRow.push_back(GG_Tile(tileBoundary, 1, tileNumber, GG_TileType::Normal, GG_TileShape::Box, GG_CollisionType::Box));
        }

        tiles.push_back(tilesRow);
    }

    return GG_Map(GG_GetTextureId(textureManager, tilesetName), mapSize, tiles);
}
