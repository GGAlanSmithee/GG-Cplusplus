#include <iostream>
#include <SDL.h>
#include "Engine/Core/Core.h"
#include "Engine/Core/System.h"
#include "Engine/Renderer/Renderer.h"

namespace GGCoreEngine
{
    const int Execute(GGGame::Game& game)
    {
        if (SDL_Init(SDL_INIT_EVENTS) != 0)
        {
            std::cerr << "Failed to initialize SDL Events." << std::endl;

            return -1;
        }

        GGRendererEngine::Initialize();

        if (!GGRendererEngine::WasInitialized())
        {
            std::cerr << GGRendererEngine::GetError() << std::endl;
            return -1;
        }

        SDL_Event event;

        bool running = true;
        float scale = 1.0f;

        while (running)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_KEYDOWN:
                    {
                        switch (event.key.keysym.sym)
                        {

                        }
                    }
                    case SDL_KEYUP:
                    {
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                            {
                                running = false;
                                break;
                            }
                        }

                        break;
                    }
                    case SDL_QUIT:
                    {
                        running = false;
                        break;
                    }
                }
            }

            auto world = game.GetWorld();

            GGCoreEngine::Movement(world);

            GGRendererEngine::ClearScreen();

            GGCoreEngine::Render(world);

            GGRendererEngine::UpdateScreen();
        }

        GGRendererEngine::CleanUp();
        SDL_Quit();

        return 0;
    }
}
