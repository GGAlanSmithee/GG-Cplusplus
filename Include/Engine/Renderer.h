#ifndef ENGINE_RENDERER_H_INCLUDED
#define ENGINE_RENDERER_H_INCLUDED

#include <memory>
#include <SDL.h>
#include "Math/Rect.h"

class GG_Renderer
{
    public:
        GG_Renderer(SDL_Window* const);
        ~GG_Renderer();

        /// Renders a texture
        /// @author Alan Smithee
        /// @date created 2015-02-07
        /// @param renderer the renderer to use to render the texture
        /// @param texture the texture to render
        /// @exception throws a std::invalid_arugment exception if \a renderer is null
        /// @exception throws a std::invalid_arugment exception if \a texture is null
        friend void GG_RenderTexture(std::unique_ptr<GG_Renderer> const&, SDL_Texture* const);
        friend void GG_RenderTexture(std::unique_ptr<GG_Renderer> const&,
                                     SDL_Texture* const,
                                     GG_Rect const&,
                                     GG_Rect const&);

        friend const GG_Rect GG_GetWindowSize(std::unique_ptr<GG_Renderer> const&);
        friend const GG_Rect GG_GetWindowLogicalSize(std::unique_ptr<GG_Renderer> const&);

        friend const float GG_ToLogical(std::unique_ptr<GG_Renderer> const&, const float);
        friend const float GG_ToView(std::unique_ptr<GG_Renderer> const&, const float);

        friend SDL_Renderer* const GG_GetSDLRenderer(std::unique_ptr<GG_Renderer> const&);

    private:
        SDL_Renderer* _sdlRenderer = nullptr;
        GG_Rect       _windowRect;
        const float   UnitSize;
};

void GG_ClearScreen(std::unique_ptr<GG_Renderer> const&);
void GG_UpdateScreen(std::unique_ptr<GG_Renderer> const&);

#endif // ENGINE_RENDERER_H_INCLUDED
