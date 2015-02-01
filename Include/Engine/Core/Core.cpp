#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Engine/Core/Core.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Event/Event.h"
#include "Manager/Texture/Texture.h"
#include "Loader/Loader.h"

namespace GGCoreEngine
{
    const bool InitializeSDL(const int flags)
    {
        if (SDL_Init(flags) != 0)
        {
            std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }

    const bool InitializeSDLImage(const int flags)
    {
        if (!(IMG_Init(flags) & flags))
        {
            std::cerr << "Failed to initialize SDL_Image: " << IMG_GetError() << std::endl;
            return false;
        }

        return true;
    }

    const int Execute(GGApplication::Application& application)
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
                                                   GGLoader::LoadTexture(GGRendererEngine::GetRenderer(renderer),
                                                                         "test.png"));

        auto event = GGEventEngine::Create();

        auto running = true;

        GGEventEngine::RegisterCallbackToKeyboardEvent(event, SDLK_ESCAPE, [&]() { running = false; });

        while (running)
        {
            GGEventEngine::HandleEvents(event);

            auto texture = GGTextureManager::GetTexture(textureManager, handle);
            GGRendererEngine::Render(renderer, texture);

            SDL_Delay(1);
        }

        GGTextureManager::Destroy(textureManager);
        GGEventEngine::Destroy(event);

        GGRendererEngine::Destroy(renderer);

        SDL_DestroyWindow(window);
        window = nullptr;

        SDL_Quit();

        return 0;
    }
}
