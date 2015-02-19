#ifndef APPLICATION_MAP_H_INCLUDED
#define APPLICATION_MAP_H_INCLUDED

#include <memory>
#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "Engine/Renderer.h"
#include "Manager/Texture.h"

class GG_Map
{
    public:
        GG_Map();
        ~GG_Map();

        friend SDL_Rect const& GG_GetBoundary(GG_Map const&);
        friend std::vector<std::vector<GG_Tile>> const& GG_GetTiles(GG_Map const&);
        friend const int GG_GetTilesetId(GG_Map const&);

    private:
        int                               tilesetId;
        SDL_Rect                          boundary;
        std::vector<std::vector<GG_Tile>> tiles;
};

void GG_RenderMap(GG_Map const&,
                  std::unique_ptr<GG_Renderer> const&,
                  std::unique_ptr<GG_TextureManager> const&,
                  SDL_Rect const&);

#endif // APPLICATION_MAP_H_INCLUDED
