#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>
#include "Engine/Core/Core.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Event/Event.h"
#include "Manager/Texture/Texture.h"
#include "Loader/Loader.h"
#include "Utility/Exception.h"
#include <stdexcept>

GG_Engine::GG_Engine(SDL_Window* window,
                     GG_Renderer* renderer,
                     GG_Event* event,
                     GG_TextureManager* textureManager) :
    _window(window),
    _renderer(renderer),
    _event(event),
    _textureManager(textureManager)
{
    // Empty
}

GG_Engine::~GG_Engine()
{
    GG_DestroyTextureManager(_textureManager);
    GG_DestroyEvent(_event);
    GG_DestroyRenderer(_renderer);

    if (_window != nullptr)
    {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }
}

GG_Engine* const GG_CreateEngine(SDL_Window* const window,
                                 GG_Renderer* const renderer,
                                 GG_Event* const event,
                                 GG_TextureManager* const textureManager)
{
    return new GG_Engine(window, renderer, event, textureManager);
}

GG_Renderer* const GG_GetRenderer(GG_Engine* const engine)
{
    if (engine == nullptr)
    {
        throw new std::invalid_argument("engine cannot be null.");
    }

    return engine->_renderer;
}

GG_Event* const GG_GetEvent(GG_Engine* const engine)
{
    if (engine == nullptr)
    {
        throw new std::invalid_argument("engine cannot be null.");
    }

    return engine->_event;
}

GG_TextureManager* const GG_GetTextureManager(GG_Engine* const engine)
{
    if (engine == nullptr)
    {
        throw new std::invalid_argument("engine cannot be null.");
    }

    return engine->_textureManager;
}

void GG_DestroyEngine(GG_Engine* engine)
{
    if (engine == nullptr)
    {
        return;
    }

    delete engine;
    engine = nullptr;
}

void GG_InitializeSDL(const int flags)
{
    auto result = SDL_Init(flags);

    if (result != 0)
    {
        throw init_error(std::string("Failed to initialize SDL: ") + SDL_GetError());
    }
}

void GG_InitializeSDLImage(const int flags)
{
    auto result = IMG_Init(flags);

    if (result & flags != flags)
    {
        throw init_error(std::string("Failed to initialize SDL: ") + IMG_GetError());
    }
}

void GG_QuitSDL()
{
    SDL_Quit();
}

void GG_QuitSDLImage()
{
    IMG_Quit();
}

const int GG_Execute(GG_Engine* const engine, GG_Application* const application)
{
    GG_SetDefaultTexture(GG_GetTextureManager(engine), GG_GetRenderer(engine), "default.png");

    auto handle = GG_AddTexture(GG_GetTextureManager(engine),
                                GG_GetRenderer(engine),
                                "test.png");

    auto running = true;

    GG_RegisterKeyboardEvent(GG_GetEvent(engine), SDLK_ESCAPE, [&]() { running = false; });

    while (running)
    {
        GG_HandleEvents(GG_GetEvent(engine));

        GG_RenderTexture(GG_GetRenderer(engine), GG_GetTexture(GG_GetTextureManager(engine), handle+1));

        SDL_Delay(1);
    }

    return 0;
}
