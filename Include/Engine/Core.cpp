#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>
#include "Engine/Core.h"
#include "Engine/Renderer.h"
#include "Engine/Event.h"
#include "Manager/Texture.h"
#include "Loader/Texture.h"
#include "Utility/Exception.h"
#include <stdexcept>

GG_Engine::GG_Engine(SDL_Window* window,
                     std::unique_ptr<GG_Renderer> renderer,
                     std::unique_ptr<GG_Event> event,
                     std::unique_ptr<GG_TextureManager> textureManager) :
    _window(window),
    _renderer(std::move(renderer)),
    _event(std::move(event)),
    _textureManager(std::move(textureManager))
{
    // Empty
}

GG_Engine::~GG_Engine()
{
    if (_window != nullptr)
    {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }

    IMG_Quit();
    SDL_Quit();
}

std::unique_ptr<GG_Renderer> const& GG_GetRenderer(std::unique_ptr<GG_Engine> const& engine)
{
    if (engine == nullptr)
    {
        throw new std::invalid_argument("engine cannot be null.");
    }

    return engine->_renderer;
}

std::unique_ptr<GG_Event> const& GG_GetEvent(std::unique_ptr<GG_Engine> const& engine)
{
    if (engine == nullptr)
    {
        throw new std::invalid_argument("engine cannot be null.");
    }

    return engine->_event;
}

std::unique_ptr<GG_TextureManager> const& GG_GetTextureManager(std::unique_ptr<GG_Engine> const& engine)
{
    if (engine == nullptr)
    {
        throw new std::invalid_argument("engine cannot be null.");
    }

    return engine->_textureManager;
}
