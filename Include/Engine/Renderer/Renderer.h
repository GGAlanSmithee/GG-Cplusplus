#ifndef ENGINE_RENDERER_RENDERER_H_INCLUDED
#define ENGINE_RENDERER_RENDERER_H_INCLUDED

#include <SDL.h>

class GG_Renderer
{
    public:
        friend GG_Renderer* const GG_CreateRenderer(SDL_Window* const);
        friend void GG_DestroyRenderer(GG_Renderer*);
        friend void GG_RenderTexture(GG_Renderer* const, SDL_Texture* const);
        /// @todo remove this method, it break encapsulation, refactor code using it
        friend SDL_Renderer* const GG_GetSDLRenderer(GG_Renderer* const);

    private:
        GG_Renderer() { };
        ~GG_Renderer() { };

        SDL_Renderer* _renderer = nullptr;
};

/// Creates an instance of the GG_Renderer class
/// @author Alan Smithee
/// @date created 2015-02-07
/// @param window a SDL window to bind the renderer too
/// @return an instance of the GG_Renderer class
/// @todo wrap SDL_Window in own GG_Window class
/// @remarks friend of GG_Renderer
GG_Renderer* const GG_CreateRenderer(SDL_Window* const);

/// Destroys an instance of the GG_Renderer class
/// @author Alan Smithee
/// @date created 2015-02-07
/// @param renderer the renderer to destroy
/// @remarks friend of GG_Renderer
void GG_DestroyRenderer(GG_Renderer*);

/// Renders a texture
/// @author Alan Smithee
/// @date created 2015-02-07
/// @param renderer the renderer to use to render the texture
/// @param texture the texture to render
/// @exception throws a std::invalid_arugment exception if \a renderer is null
/// @exception throws a std::invalid_arugment exception if \a texture is null
/// @remarks friend of GG_Renderer
void GG_RenderTexture(GG_Renderer* const, SDL_Texture* const);

/// @todo remove this method, it breaks encapsulation, refactor code using it
SDL_Renderer* const GG_GetSDLRenderer(GG_Renderer* const);


#endif // ENGINE_RENDERER_RENDERER_H_INCLUDED
