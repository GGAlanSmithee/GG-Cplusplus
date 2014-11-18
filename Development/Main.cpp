#include <iostream>
#include <SDL.h>
#include "Graphics/Graphics.h"
#include "System/System.h"
#include "Entity/World.h"
#include "Entity/Entity.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        std::cerr << "Failed to initialize SDL Events." << std::endl;

        return -1;
    }

    GGGraphics::Initialize();

    if (!GGGraphics::WasInitialized())
    {
        std::cerr << GGGraphics::GetError() << std::endl;
        return -1;
    }

    GGGraphics::CreateVertexBuffer();
    GGGraphics::CreateIndexBuffer();

    SDL_Event event;

    bool running = true;
    float scale = 1.0f;
    GGEntity::World world(1000);
    GGEntity::CreateEntity(world);

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
                        case SDLK_1:
                        {
                            scale += 0.05f;
                            GGGraphics::SetScale(scale);
                            break;
                        }
                        case SDLK_2:
                        {
                            scale -= 0.05f;
                            GGGraphics::SetScale(scale);
                            break;
                        }
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

        GGSystem::Movement(world);
        GGSystem::Render(world);
    }

    GGGraphics::CleanUp();
    SDL_Quit();

    return 0;
}

