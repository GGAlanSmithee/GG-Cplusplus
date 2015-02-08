#include "Renderer.h"

#include <iostream>
#include <SDL.h>
#include "Utility/Exception.h"

/// @todo add parameter for flags
GG_Renderer* const GG_CreateRenderer(SDL_Window* const window)
{
    auto renderer = new GG_Renderer();

    renderer->_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer->_renderer == nullptr)
    {
        GG_DestroyRenderer(renderer);
        throw init_error(std::string("Failed to create SDL renderer: ") + SDL_GetError());
    }

    return renderer;
}

void GG_DestroyRenderer(GG_Renderer* renderer)
{
    if (renderer == nullptr)
    {
        return;
    }

    if (renderer->_renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer->_renderer);
        renderer->_renderer = nullptr;
    }

    delete renderer;
    renderer = nullptr;
}

void GG_RenderTexture(GG_Renderer* const renderer, SDL_Texture* const texture)
{
    if (renderer == nullptr)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    if (texture == nullptr)
    {
        throw std::invalid_argument("texture cannot be null");
    }

    SDL_RenderClear(renderer->_renderer);
    SDL_RenderCopy(renderer->_renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer->_renderer);
}

SDL_Renderer* const GG_GetSDLRenderer(GG_Renderer* renderer)
{
    return renderer->_renderer;
}
