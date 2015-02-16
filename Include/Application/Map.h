#ifndef APPLICATION_MAP_H_INCLUDED
#define APPLICATION_MAP_H_INCLUDED

#include <SDL.h>
#include <vector>
#include "Tile.h"

class GG_Map
{
    public:
        GG_Map() {};
        ~GG_Map() {};

    private:
        SDL_Rect boundry;
        std::vector<GG_Tile> tiles;
};

#endif // APPLICATION_MAP_H_INCLUDED
