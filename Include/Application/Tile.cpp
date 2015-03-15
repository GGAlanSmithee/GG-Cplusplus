#include "Tile.h"

GG_Tile::GG_Tile() :
    GG_Tile({ 0, 0, 1, 1 }, 1, 1, GG_TileType::Normal, GG_TileShape::Box, GG_CollisionType::Box)
{
    // Empty
}


GG_Tile::GG_Tile(GG_Rect const& boundary,
                 const unsigned int tilesetId,
                 const unsigned int number,
                 const GG_TileType type,
                 const GG_TileShape shape,
                 const GG_CollisionType collisionType) :
    boundary(boundary),
    tilesetId(tilesetId),
    number(number),
    type(type),
    shape(shape),
    collisionType(collisionType)
{
    // Empty
}

GG_Tile::~GG_Tile()
{

}

GG_Rect const& GG_GetBoundary(GG_Tile const& tile)
{
    return tile.boundary;
}

unsigned int const GG_GetTilesetId(GG_Tile const& tile)
{
    return tile.tilesetId;
}

unsigned int const GG_GetNumber(GG_Tile const& tile)
{
    return tile.number;
}

GG_TileType const GG_GetType(GG_Tile const& tile)
{
    return tile.type;
}

GG_TileShape const GG_GetShape(GG_Tile const& tile)
{
    return tile.shape;
}

GG_CollisionType const GG_GetCollisionType(GG_Tile const& tile)
{
    return tile.collisionType;
}

void GG_SetBoundary(GG_Tile& tile, GG_Rect const& boundary)
{
    tile.boundary = boundary;
}

void GG_SetTilesetId(GG_Tile& tile, const unsigned int tilesetId)
{
    tile.tilesetId = tilesetId;
}

void GG_SetNumber(GG_Tile& tile, const unsigned int number)
{
    tile.number = number;
}

void GG_SetType(GG_Tile& tile, GG_TileType const& type)
{
    tile.type = type;
}

void GG_SetShape(GG_Tile& tile, GG_TileShape const& shape)
{
    tile.shape = shape;
}

void GG_SetCollisionType(GG_Tile& tile, GG_CollisionType const& collisionType)
{
    tile.collisionType = collisionType;
}
