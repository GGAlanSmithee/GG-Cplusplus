#include <iostream>
#include "Texture.h"

// Private accessor
namespace GGTextureManager
{
    class InstanceAccessor
    {
        public:
            static Instance* Create();
            static void Destroy(Instance*);
            static const int AddTexture(Instance*, SDL_Texture*);
            static SDL_Texture* GetTexture(Instance*, const int);
    };

    Instance* InstanceAccessor::Create()
    {
        return new Instance();
    }

    void InstanceAccessor::Destroy(Instance* instance)
    {
        if (instance == nullptr)
        {
            return;
        }

        for (auto& kvp : instance->_textures)
        {
            if (kvp.second != nullptr)
            {
                SDL_DestroyTexture(kvp.second);
                kvp.second = nullptr;
            }
        }

        delete instance;
        instance = nullptr;
    }

    const int InstanceAccessor::AddTexture(Instance* instance, SDL_Texture* texture)
    {
        auto index = 0;
        while (true)
        {
            if (instance->_textures.count(index) <= 0)
            {
                instance->_textures[index] = texture;
                break;
            }

            ++index;
        }

        return index;
    }

    SDL_Texture* InstanceAccessor::GetTexture(Instance* instance, const int key)
    {
        instance->_textures[key];
    }
}

// Public interface
namespace GGTextureManager
{
    Instance* Create()
    {
        return InstanceAccessor::Create();
    }

    void Destroy(Instance* instance)
    {
        InstanceAccessor::Destroy(instance);
    }

    const int AddTexture(Instance* instance, SDL_Texture* texture)
    {
        if (texture == nullptr)
        {
            return -1;
        }

        return InstanceAccessor::AddTexture(instance, texture);
    }

    SDL_Texture* GetTexture(Instance* instance, const int key)
    {
        if (instance == nullptr || key < 0)
        {
            std::cerr << "Could not fetch the requested texture" << std::endl;
            return nullptr;
        }

        return InstanceAccessor::GetTexture(instance, key);
    }
}
