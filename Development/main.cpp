#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Engine/Renderer/Renderer.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL" << std::endl;
        return -1;
    }

    auto instance = GGRendererEngine::Create();

    auto texture = GGRendererEngine::CreateTexture(instance);

    auto running = true;
    while (running)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        running = false;
                        break;
                    }
                }
            }
        }

        GGRendererEngine::Render(instance, texture);
    }

    SDL_DestroyTexture(texture);
    GGRendererEngine::Destroy(instance);

    SDL_Quit();

    return 0;
}
