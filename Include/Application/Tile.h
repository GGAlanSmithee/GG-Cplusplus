#ifndef APPLICATION_TILE_H_INCLUDED
#define APPLICATION_TILE_H_INCLUDED

#include <SDL.h>

enum class GG_TileType
{
    None
};

class GG_Tile
{
    public:
        GG_Tile() {};
        ~GG_Tile() {};

    private:
        SDL_Rect boundary;
        GG_TileType type;
};

#endif // APPLICATION_TILE_H_INCLUDED
