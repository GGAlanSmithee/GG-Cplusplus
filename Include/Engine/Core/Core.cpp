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

GG_Engine* const GG_CreateEngine(const std::string& title,
                                 const unsigned int x,
                                 const unsigned int y,
                                 const unsigned int w,
                                 const unsigned int h,
                                 const unsigned int flags)
{
    auto engine = new GG_Engine();

    engine->_window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

    if (engine->_window == nullptr)
    {
        GG_DestroyEngine(engine);
        throw init_error(std::string("Failed to create SDL window: ") + SDL_GetError());
    }

    return engine;
}

SDL_Window* const GG_GetWindow(GG_Engine* const engine)
{
    return engine->_window;
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
    GG_Renderer* renderer = nullptr;

    try
    {
        renderer = GG_CreateRenderer(GG_GetWindow(engine));
    }
    catch (const init_error& e)
    {
        GG_DestroyEngine(engine);
        throw;
    }

    auto textureManager = GG_CreateTextureManager();
    auto event = GG_CreateEvent();

    auto texture = GGLoader::LoadTexture(GG_GetSDLRenderer(renderer), "test.png");

    auto handle = GG_AddTexture(textureManager, texture);

    auto running = true;

    GG_RegisterKeyboardEvent(event, SDLK_ESCAPE, [&]() { running = false; });

    while (running)
    {
        GG_HandleEvents(event);

        GG_RenderTexture(renderer, GG_GetTexture(textureManager, handle));

        SDL_Delay(1);
    }

    GG_DestroyEvent(event);
    GG_DestroyTextureManager(textureManager);
    GG_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
