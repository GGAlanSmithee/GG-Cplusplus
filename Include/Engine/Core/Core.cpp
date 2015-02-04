#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Engine/Core/Core.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Event/Event.h"
#include "Manager/Texture/Texture.h"
#include "Loader/Loader.h"
#include "Utility/Exception.h"

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

const int GG_Execute(GG_Application& application)
{
    auto window = SDL_CreateWindow("Hello, World!",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   640,
                                   480,
                                   SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr)
    {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    auto renderer = GGRendererEngine::Create(window);

    if (renderer == nullptr)
    {
        std::cerr << "Failed to create renderer" << std::endl;
        SDL_DestroyWindow(window);
        window = nullptr;
        return -1;
    }

    auto textureManager = GGTextureManager::Create();
    auto handle = GGTextureManager::AddTexture(textureManager,
    GGLoader::LoadTexture(GGRendererEngine::GetRenderer(renderer), "test.png"));

    auto event = GG_CreateEvent();

    auto running = true;

    GG_RegisterKeyboardEvent(event, SDLK_ESCAPE, [&]() { running = false; });

    while (running)
    {
        GGEventEngine::HandleEvents(event);

        auto texture = GGTextureManager::GetTexture(textureManager, handle);
        GGRendererEngine::Render(renderer, texture);

        SDL_Delay(1);
    }

    GGTextureManager::Destroy(textureManager);
    GG_DestroyEvent(event);

    GGRendererEngine::Destroy(renderer);

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();

    return 0;
}
