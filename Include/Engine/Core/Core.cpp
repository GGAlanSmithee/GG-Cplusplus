#include <iostream>
#include <SDL.h>
#include "Engine/Core/Core.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Event/Event.h"

namespace GGCoreEngine
{
    const int Execute(GGApplication::Application& application)
    {
        if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0)
        {
            std::cerr << "Failed to initialize SDL Events." << std::endl;

            return -1;
        }

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

        auto texture = GGRendererEngine::CreateTexture(renderer);

        auto event = GGEventEngine::Create();

        auto running = true;

        GGEventEngine::RegisterCallbackToKeyboardEvent(event, SDLK_ESCAPE, [&]() { running = false; });

        while (running)
        {
            GGEventEngine::HandleEvents(event);

            GGRendererEngine::Render(renderer, texture);

            SDL_Delay(1);
        }

        GGEventEngine::Destroy(event);

        SDL_DestroyTexture(texture);
        GGRendererEngine::Destroy(renderer);

        SDL_DestroyWindow(window);
        window = nullptr;

        SDL_Quit();

        return 0;
    }
}
