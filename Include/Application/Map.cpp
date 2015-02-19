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
                  SDL_Rect const& cameraRect)
{
    auto boundary = GG_GetBoundary(map);

//    if (!(cameraRect.x + cameraRect.w >= boundary.x && cameraRect.x <= boundary.x + boundary.w &&
//          cameraRect.y + cameraRect.h >= boundary.y && cameraRect.y <= boundary.y + boundary.h))
//    {
//        return;
//    }

    auto startX = static_cast<int>(cameraRect.x) / 32;
    auto endX   = static_cast<int>(cameraRect.x + cameraRect.w) / 32;
    auto startY = static_cast<int>(cameraRect.y) / 32;
    auto endY   = static_cast<int>(cameraRect.y + cameraRect.h) / 32;

    auto tiles = GG_GetTiles(map);
    SDL_Rect source = { 32, 32, 32, 32 };

    for (auto y = startY; y < endY; ++y)
    {
        for (auto x = startX; x < endX; ++x)
        {
            SDL_Rect tileBoundary = GG_GetBoundary(tiles[y][x]);
            tileBoundary.x *= 32;
            tileBoundary.y *= 32;
            tileBoundary.w *= 32;
            tileBoundary.h *= 32;

            GG_RenderTexture(renderer,
                             GG_GetTexture(textureManager, GG_GetTilesetId(map)),
                             source,
                             tileBoundary);
        }
    }
}
