#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SDL.h>

namespace GGRendererEngine
{
    class Instance
    {
        private:
            friend class InstanceAccessor;

            Instance() { };

            SDL_Window*   _window   = nullptr;
            SDL_Renderer* _renderer = nullptr;
    };

    Instance* Create();
    void Destroy(Instance*);
    void Render(Instance*, SDL_Texture*);
    SDL_Texture* CreateTexture(Instance*);
}

#endif // RENDERER_H_INCLUDED
