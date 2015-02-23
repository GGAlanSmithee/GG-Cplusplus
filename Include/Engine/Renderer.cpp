#include "Renderer.h"

#include <iostream>
#include <SDL.h>
#include "Utility/Exception.h"

/// @todo add parameter for flags
GG_Renderer::GG_Renderer(SDL_Window* const window)
{
    if (window == nullptr)
    {
        throw std::invalid_argument("window cannot be null");
    }

    _windowRect.x = 0;
    _windowRect.y = 0;

    SDL_GetWindowSize(window, &_windowRect.w, &_windowRect.h);

    _sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (_sdlRenderer == nullptr)
    {
        throw init_error(std::string("Failed to create SDL renderer: ") + SDL_GetError());
    }
}

GG_Renderer::~GG_Renderer()
{
    if (_sdlRenderer != nullptr)
    {
        SDL_DestroyRenderer(_sdlRenderer);
        _sdlRenderer = nullptr;
    }
}

void GG_ClearScreen(std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    SDL_RenderClear(GG_GetSDLRenderer(renderer));
}

void GG_UpdateScreen(std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    SDL_RenderPresent(GG_GetSDLRenderer(renderer));
}

void GG_RenderTexture(std::unique_ptr<GG_Renderer> const& renderer, SDL_Texture* const texture)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    if (texture == nullptr)
    {
        throw std::invalid_argument("texture cannot be null");
    }

    SDL_RenderClear(renderer->_sdlRenderer);
    SDL_RenderCopy(renderer->_sdlRenderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer->_sdlRenderer);
}

void GG_RenderTexture(std::unique_ptr<GG_Renderer> const& renderer,
                      SDL_Texture* const texture,
                      SDL_Rect& source,
                      SDL_Rect& dest)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    if (texture == nullptr)
    {
        throw std::invalid_argument("texture cannot be null");
    }

    if (dest.w == 0)
    {
        dest.w = source.w;
    }

    if (dest.h == 0)
    {
        dest.h = source.h;
    }

    SDL_RenderCopy(renderer->_sdlRenderer, texture, &source, &dest);
}

SDL_Renderer* const GG_GetSDLRenderer(std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    return renderer->_sdlRenderer;
}

const SDL_Rect GG_GetWindowSize(std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    return renderer->_windowRect;
}
