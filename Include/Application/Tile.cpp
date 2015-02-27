#include "Tile.h"

GG_Tile::GG_Tile() :
    GG_Tile({ 0, 0, 1, 1 }, 1, GG_TileType::Normal, GG_CollisionType::Box)
{
    // Empty
}


GG_Tile::GG_Tile(SDL_Rect const& boundary,
                 const unsigned int tileNumber,
                 const GG_TileType tileType,
                 const GG_CollisionType collisionType) :
    boundary(boundary),
    tileNumber(tileNumber),
    tileType(tileType),
    collisionType(collisionType)
{
    // Empty
}

GG_Tile::~GG_Tile()
{

}

SDL_Rect const& GG_GetBoundary(GG_Tile const& tile)
{
    return tile.boundary;
}

unsigned int const GG_GetTileNumber(GG_Tile const& tile)
{
    return tile.tileNumber;
}

GG_TileType const  GG_GetTileType(GG_Tile const& tile)
{
    return tile.tileType;
}

GG_CollisionType const  GG_GetCollisionType(GG_Tile const& tile)
{
    return tile.collisionType;
}
