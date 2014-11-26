#include <iostream>
#include <SDL.h>
#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/System.h"
#include "Engine/Core/World.h"
#include "Engine/Core/Entity.h"

int main(int argc, char* args[])
{
    /// @todo MOVE TO CORE.
    /// Core should take a game as an inparameter and be responsible for running the game
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

    GGRendererEngine::CreateVertexBuffer();
    GGRendererEngine::CreateIndexBuffer();

    SDL_Event event;

    bool running = true;
    float scale = 1.0f;
    GGCoreEngine::World world(1000);
    GGCoreEngine::CreateEntity(world);

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

        GGCoreEngine::Movement(world);
        GGCoreEngine::Render(world);
        GGRendererEngine::UpdateScreen();
    }

    GGRendererEngine::CleanUp();
    SDL_Quit();

    return 0;
}

