#include "Renderer.h"

#include <iostream>
#include <SDL.h>

namespace GGRendererEngine
{
    class InstanceAccessor
    {
        public:
            static Instance* Create()
            {
                Instance* instance = new Instance();

                instance->_window = SDL_CreateWindow("Hello, World!",
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     640,
                                                     480,
                                                     SDL_WINDOW_ALLOW_HIGHDPI);

                if (instance->_window == nullptr)
                {
                    Destroy(instance);
                }

                instance->_renderer = SDL_CreateRenderer(instance->_window, -1, SDL_RENDERER_ACCELERATED);

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

                if (instance->_window != nullptr)
                {
                    SDL_DestroyWindow(instance->_window);
                    instance->_window = nullptr;
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

    Instance* Create()
    {
        return InstanceAccessor::Create();
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
