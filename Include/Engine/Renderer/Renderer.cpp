#include "Renderer.h"

#include <iostream>
#include <SDL.h>

namespace GGRendererEngine
{
    class InstanceAccessor
    {
        public:
            static Instance* Create(SDL_Window* window)
            {
                Instance* instance = new Instance();

                instance->_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

                if (instance->_renderer == nullptr)
                {
                    Destroy(instance);
                }

                return instance;
            }

            static void Destroy(Instance* instance)
            {
                if (instance == nullptr)
                {
                    return;
                }

                if (instance->_renderer != nullptr)
                {
                    SDL_DestroyRenderer(instance->_renderer);
                    instance->_renderer = nullptr;
                }

                delete instance;
                instance = nullptr;
            }

            static SDL_Texture* CreateTexture(Instance* instance, SDL_Surface* surface)
            {
                return SDL_CreateTextureFromSurface(instance->_renderer, surface);
            }

            static void Render(Instance* instance, SDL_Texture* texture)
            {
                SDL_RenderClear(instance->_renderer);
                SDL_RenderCopy(instance->_renderer, texture, nullptr, nullptr);
                SDL_RenderPresent(instance->_renderer);
            }
    };

    Instance* Create(SDL_Window* window)
    {
        return InstanceAccessor::Create(window);
    }

    void Destroy(Instance* instance)
    {
        InstanceAccessor::Destroy(instance);
    }

    void Render(Instance* instance, SDL_Texture* texture)
    {
        InstanceAccessor::Render(instance, texture);
    }

    SDL_Texture* CreateTexture(Instance* instance)
    {
        SDL_Surface* surface = SDL_LoadBMP("helloworld.bmp");

        auto texture = InstanceAccessor::CreateTexture(instance, surface);

        SDL_FreeSurface(surface);

        return texture;
    }
}
