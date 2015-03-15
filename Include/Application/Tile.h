#ifndef APPLICATION_TILE_H_INCLUDED
#define APPLICATION_TILE_H_INCLUDED

#include "Math/Rect.h"
#include "Engine/Physics.h"

enum class GG_TileType
{
    None,
    Normal,
    Ice
};

enum class GG_TileShape
{
    None,
    Box,
    Top,
    Right,
    Bottom,
    Left,
    TopRight,
    BottomRight,
    BottomLeft,
    TopLeft
};

class GG_Tile
{
    public:
        GG_Tile();
        GG_Tile(GG_Rect const&,
                const unsigned int,
                const unsigned int,
                const GG_TileType,
                const GG_TileShape,
                const GG_CollisionType);
        ~GG_Tile();

        friend GG_Rect const&          GG_GetBoundary(GG_Tile const&);
        friend unsigned int const      GG_GetNumber(GG_Tile const&);
        friend unsigned int const      GG_GetTilesetId(GG_Tile const&);
        friend GG_TileType const       GG_GetType(GG_Tile const&);
        friend GG_TileShape const      GG_GetShape(GG_Tile const&);
        friend GG_CollisionType const  GG_GetCollisionType(GG_Tile const&);

        friend void GG_SetBoundary(GG_Tile&, GG_Rect const&);
        friend void GG_SetNumber(GG_Tile&, const unsigned int);
        friend void GG_SetTilesetId(GG_Tile&, const unsigned int);
        friend void GG_SetType(GG_Tile&, GG_TileType const&);
        friend void GG_SetShape(GG_Tile&, GG_TileShape const&);
        friend void GG_SetCollisionType(GG_Tile&, GG_CollisionType const&);

    private:
        GG_Rect          boundary;
        unsigned int     tilesetId;
        unsigned int     number;
        GG_TileType      type;
        GG_TileShape     shape;
        GG_CollisionType collisionType;
};

#endif // APPLICATION_TILE_H_INCLUDED
