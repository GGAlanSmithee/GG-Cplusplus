#include "Renderer.h"

#include <iostream>
#include <SDL.h>
#include "Utility/Exception.h"

/// @todo add parameter for flags
GG_Renderer::GG_Renderer(SDL_Window* const window)
{
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
                      SDL_Rect& renderQuad,
                      SDL_Rect& clipRect)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    if (texture == nullptr)
    {
        throw std::invalid_argument("texture cannot be null");
    }

    renderQuad.w = clipRect.w;
    renderQuad.h = clipRect.h;

    SDL_RenderClear(renderer->_sdlRenderer);
    SDL_RenderCopy(renderer->_sdlRenderer, texture, &clipRect, &renderQuad);
    SDL_RenderPresent(renderer->_sdlRenderer);
}

SDL_Renderer* const GG_GetSDLRenderer(std::unique_ptr<GG_Renderer> const& renderer)
{
    return renderer->_sdlRenderer;
}
