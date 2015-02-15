#ifndef ENGINE_RENDERER_H_INCLUDED
#define ENGINE_RENDERER_H_INCLUDED

#include <memory>
#include <SDL.h>

class GG_Renderer
{
    public:
        GG_Renderer(SDL_Window* const);
        ~GG_Renderer();

        friend void GG_RenderTexture(std::unique_ptr<GG_Renderer> const&, SDL_Texture* const);
        /// @todo remove this method, it break encapsulation, refactor code using it
        friend SDL_Renderer* const GG_GetSDLRenderer(std::unique_ptr<GG_Renderer> const&);

    private:
        SDL_Renderer* _sdlRenderer = nullptr;
};

/// Renders a texture
/// @author Alan Smithee
/// @date created 2015-02-07
/// @param renderer the renderer to use to render the texture
/// @param texture the texture to render
/// @exception throws a std::invalid_arugment exception if \a renderer is null
/// @exception throws a std::invalid_arugment exception if \a texture is null
/// @remarks friend of GG_Renderer
void GG_RenderTexture(std::unique_ptr<GG_Renderer> const&, SDL_Texture* const);

/// @todo remove this method, it breaks encapsulation, refactor code using it
SDL_Renderer* const GG_GetSDLRenderer(std::unique_ptr<GG_Renderer> const&);


#endif // ENGINE_RENDERER_H_INCLUDED
