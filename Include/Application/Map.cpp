#include <iostream>
#include "Map.h"

GG_Map::GG_Map() :
    tilesetId(0)
{
    std::vector<std::vector<GG_Tile>> tiles;

    for (auto y = 0; y < 100; ++y)
    {
        std::vector<GG_Tile> tilesRow;

        for (auto x = 0; x < 100; ++x)
        {
            SDL_Rect rect = { x, y, 1, 1 };
            tilesRow.push_back(GG_Tile(rect, GG_TileType::Normal, GG_CollisionType::Box));
        }

        tiles.push_back(tilesRow);
    }

    boundary = { 0, 0, 100, 100 };
    this->tiles = tiles;
}

GG_Map::~GG_Map()
{

}

SDL_Rect const& GG_GetBoundary(GG_Map const& map)
{
    return map.boundary;
}

std::vector<std::vector<GG_Tile>> const& GG_GetTiles(GG_Map const& map)
{
    return map.tiles;
}

const int GG_GetTilesetId(GG_Map const& map)
{
    return map.tilesetId;
}

void GG_RenderMap(GG_Map const& map,
                  std::unique_ptr<GG_Renderer> const& renderer,
                  std::unique_ptr<GG_TextureManager> const& textureManager,
                  GG_Vec2f const& cameraPos,
                  SDL_Rect const& cameraRect)
{
    auto boundary = GG_GetBoundary(map);

    static auto last = 0.0f;

    std::cout << SDL_GetTicks() - last << std::endl;

    last = SDL_GetTicks();

    if (!(cameraPos.x + cameraRect.w >= boundary.x && cameraPos.x <= boundary.x + boundary.w &&
          cameraPos.y + cameraRect.h >= boundary.y && cameraPos.y <= boundary.y + boundary.h))
    {
        return;
    }

    auto startX = cameraPos.x < 0 ? 0 : static_cast<int>(cameraPos.x);
    auto endX   = cameraPos.x + cameraRect.w + 1 > 100 ? 100 : static_cast<int>(cameraPos.x + cameraRect.w + 1);
    auto startY = cameraPos.y < 0 ? 0 : static_cast<int>(cameraPos.y);
    auto endY   = cameraPos.y + cameraRect.h + 1 > 100 ? 100 : static_cast<int>(cameraPos.y + cameraRect.h + 1);

    auto tiles = GG_GetTiles(map);
    SDL_Rect source = { 32, 32, 32, 32 };

    for (auto y = startY; y < endY; ++y)
    {
        for (auto x = startX; x < endX; ++x)
        {
            SDL_Rect tileBoundary = GG_GetBoundary(tiles[y][x]);
            tileBoundary.x = (tileBoundary.x - cameraPos.x) * 32.0f;
            tileBoundary.y = (tileBoundary.y - cameraPos.y) * 32.0f;
            tileBoundary.w *= 32.0f;
            tileBoundary.h *= 32.0f;

            GG_RenderTexture(renderer,
                             GG_GetTexture(textureManager, GG_GetTilesetId(map)),
                             source,
                             tileBoundary);
        }
    }
}
