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
}

GG_Engine* const GG_CreateEngine(SDL_Window* const window,
                                 GG_Renderer* const renderer,
                                 GG_Event* const event,
                                 GG_TextureManager* const textureManager)
{
    return new GG_Engine(window, renderer, event, textureManager);
}

SDL_Window* const GG_GetWindow(GG_Engine* const engine)
{
    return engine->_window;
}

GG_Event* const GG_GetEventFromEngine(GG_Engine* const engine)
{
    return engine->_event;
}

void GG_DestroyEngine(GG_Engine* engine)
{
    if (engine == nullptr)
    {
        return;
    }

    if (engine->_window != nullptr)
    {
        SDL_DestroyWindow(engine->_window);
        engine->_window = nullptr;
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

const int GG_Execute(GG_Engine* const engine)
{
    //auto texture = GGLoader::LoadTexture(GG_GetSDLRenderer(renderer), "test.png");

    //auto handle = GG_AddTexture(textureManager, texture);

    auto running = true;

    GG_RegisterKeyboardEvent(GG_GetEventFromEngine(engine), SDLK_ESCAPE, [&]() { running = false; });

    while (running)
    {
        GG_HandleEvents(GG_GetEventFromEngine(engine));

        //GG_RenderTexture(renderer, GG_GetTexture(textureManager, handle));

        SDL_Delay(1);
    }

    return 0;
}
