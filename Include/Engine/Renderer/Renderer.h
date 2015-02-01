#ifndef ENGINE_RENDERER_RENDERER_H_INCLUDED
#define ENGINE_RENDERER_RENDERER_H_INCLUDED

#include <SDL.h>

namespace GGRendererEngine
{
    class Instance
    {
        private:
            friend class InstanceAccessor;

            Instance() { };

            SDL_Renderer* _renderer = nullptr;
    };

    Instance* Create(SDL_Window*);
    void Destroy(Instance*);
    void Render(Instance*, SDL_Texture*);
    SDL_Texture* CreateTexture(Instance*);
}

#endif // ENGINE_RENDERER_RENDERER_H_INCLUDED
