#ifndef APPLICATION_MAP_H_INCLUDED
#define APPLICATION_MAP_H_INCLUDED

#include <climits>
#include <memory>
#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "Engine/Renderer.h"
#include "Manager/Texture.h"
#include "Math/Vec2.h"

class GG_Map
{
    public:
        GG_Map(const unsigned int = INT_MAX, const unsigned int = 10, std::vector<std::vector<GG_Tile>> const& = std::vector<std::vector<GG_Tile>>());
        ~GG_Map();

        friend GG_Rect const& GG_GetBoundary(GG_Map const&);
        friend const int GG_GetTilesetId(GG_Map const&);
        friend GG_Tile const& GG_GetTile(GG_Map const&, const int, const int);
        friend void GG_RenderMap(GG_Map const&,
                                 std::unique_ptr<GG_Renderer> const&,
                                 std::unique_ptr<GG_TextureManager> const&,
                                 GG_Vec2f const&,
                                 GG_Rect const&);

    private:
        int                               size;
        int                               tilesetId;
        GG_Rect                           boundary;
        std::vector<std::vector<GG_Tile>> tiles;

};

const GG_Map GG_LoadMap(std::unique_ptr<GG_TextureManager> const&, std::string const&);

#endif // APPLICATION_MAP_H_INCLUDED
