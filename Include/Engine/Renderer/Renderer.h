#ifndef ENGINE_RENDERER_RENDERER_H_INCLUDED
#define ENGINE_RENDERER_RENDERER_H_INCLUDED

#include <SDL.h>

namespace GGRendererEngine
{
    class Instance
    {
        friend class InstanceAccessor;

        Instance() { };

        SDL_Renderer* _renderer = nullptr;
    };

    Instance* Create(SDL_Window*);
    void Destroy(Instance*);
    void Render(Instance*, SDL_Texture*);
    SDL_Texture* CreateTexture(Instance*);
    SDL_Renderer* GetRenderer(Instance*);
}

#endif // ENGINE_RENDERER_RENDERER_H_INCLUDED
