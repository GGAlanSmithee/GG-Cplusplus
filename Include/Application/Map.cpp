#include "Map.h"

GG_Map::GG_Map() :
    tilesetId(0)
{
    auto numbTiles = 500;

    std::vector<std::vector<GG_Tile>> tiles;

    for (auto y = 0; y < numbTiles; ++y)
    {
        std::vector<GG_Tile> tilesRow;

        for (auto x = 0; x < numbTiles; ++x)
        {
            SDL_Rect rect = { x, y, 1, 1 };
            tilesRow.push_back(GG_Tile(rect, GG_TileType::Normal, GG_CollisionType::Box));
        }

        tiles.push_back(tilesRow);
    }

    boundary = { 0, 0, numbTiles, numbTiles };
    this->tiles = tiles;
}

GG_Map::~GG_Map()
{

}

SDL_Rect const& GG_GetBoundary(GG_Map const& map)
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
                  SDL_Rect const& cameraRect)
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

    SDL_Rect source = { 32, 32, 32, 32 };

    auto texture = GG_GetTexture(textureManager, GG_GetTilesetId(map));

    for (auto y = startY; y < endY; ++y)
    {
        for (auto x = startX; x < endX; ++x)
        {
            auto tile = GG_GetTile(map, x, y);
            SDL_Rect tileBoundary = GG_GetBoundary(GG_GetTile(map, x, y));
            tileBoundary.x = (tileBoundary.x - cameraPos.x) * 32.0f;
            tileBoundary.y = (tileBoundary.y - cameraPos.y) * 32.0f;
            tileBoundary.w *= 32.0f;
            tileBoundary.h *= 32.0f;

            GG_RenderTexture(renderer, texture, source, tileBoundary);
        }
    }
}
