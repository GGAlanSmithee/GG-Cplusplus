#ifndef MANAGER_TEXTURE_TEXTURE_H_INCLUDED
#define MANAGER_TEXTURE_TEXTURE_H_INCLUDED

#include <string>
#include <SDL.h>
#include <unordered_map>

namespace GGTextureManager
{
    class Instance
    {
        friend class InstanceAccessor;

        Instance() { };

        std::unordered_map<int, SDL_Texture*> _textures;
    };

    Instance* Create();
    void Destroy(Instance*);
    const int AddTexture(Instance*, SDL_Texture*);
    SDL_Texture* GetTexture(Instance*, const int);
}

#endif // MANAGER_TEXTURE_TEXTURE_H_INCLUDED
