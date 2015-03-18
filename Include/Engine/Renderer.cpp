#include "Renderer.h"

#include <iostream>
#include "Utility/Exception.h"

/// @todo add parameter for flags
GG_Renderer::GG_Renderer(SDL_Window* const window) :
    UnitSize(32.0f)
{
    if (window == nullptr)
    {
        throw std::invalid_argument("window cannot be null");
    }

    int w = 0;
    int h = 0;

    SDL_GetWindowSize(window, &w, &h);

    _windowRect.w = w;
    _windowRect.h = h;

    _sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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

    SDL_SetRenderDrawColor(GG_GetSDLRenderer(renderer), 100, 149, 237, 255);
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

    SDL_RenderCopy(renderer->_sdlRenderer, texture, nullptr, nullptr);
}

void GG_RenderTexture(std::unique_ptr<GG_Renderer> const& renderer,
                      SDL_Texture* const texture,
                      GG_Rect const& source,
                      GG_Rect const& destination)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    if (texture == nullptr)
    {
        throw std::invalid_argument("texture cannot be null");
    }

    SDL_Rect src =
             {
                 GG_ToView(renderer, source.x),
                 GG_ToView(renderer, source.y),
                 GG_ToView(renderer, source.w),
                 GG_ToView(renderer, source.h)
             };

    SDL_Rect dest =
             {
                 GG_ToView(renderer, destination.x),
                 GG_ToView(renderer, destination.y),
                 GG_ToView(renderer, destination.w),
                 GG_ToView(renderer, destination.h)
             };

    SDL_RenderCopy(renderer->_sdlRenderer, texture, &src, &dest);
}

void GG_RenderRect(std::unique_ptr<GG_Renderer> const& renderer, GG_Rect const& rect)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    SDL_Rect dest =
             {
                 GG_ToView(renderer, rect.x - (rect.w / 2)),
                 GG_ToView(renderer, rect.y - (rect.h / 2)),
                 GG_ToView(renderer, rect.w),
                 GG_ToView(renderer, rect.h)
             };

    /// @todo add color struct and add an instance "backgroundColor" of it to the GG_GUI_Element class
    /// and pass it in as a paramter
    SDL_SetRenderDrawColor(GG_GetSDLRenderer(renderer), 255, 0, 0, 255);

    SDL_RenderFillRect(GG_GetSDLRenderer(renderer), &dest);
}

SDL_Renderer* const GG_GetSDLRenderer(std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    return renderer->_sdlRenderer;
}

const GG_Rect GG_GetWindowSize(std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    return renderer->_windowRect;
}

const GG_Rect GG_GetWindowLogicalSize(std::unique_ptr<GG_Renderer> const& renderer)
{
    auto windowRect = GG_GetWindowSize(renderer);

    windowRect.x = GG_ToLogical(renderer, windowRect.x);
    windowRect.y = GG_ToLogical(renderer, windowRect.y);
    windowRect.w = GG_ToLogical(renderer, windowRect.w);
    windowRect.h = GG_ToLogical(renderer, windowRect.h);

    return windowRect;
}

const float GG_ToLogical(std::unique_ptr<GG_Renderer> const& renderer, const float value)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    return value / renderer->UnitSize;
}

const float GG_ToView(std::unique_ptr<GG_Renderer> const& renderer, const float value)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null");
    }

    return value * renderer->UnitSize;
}
