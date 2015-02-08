#include <iostream>
#include "Texture.h"

GG_TextureManager* const GG_CreateTextureManager()
{
    return new GG_TextureManager();
}

void GG_DestroyTextureManager(GG_TextureManager* textureManager)
{
    if (textureManager == nullptr)
    {
        return;
    }

    for (auto& kvp : textureManager->_textures)
    {
        if (kvp.second != nullptr)
        {
            SDL_DestroyTexture(kvp.second);
            kvp.second = nullptr;
        }
    }

    delete textureManager;
    textureManager = nullptr;
}

const unsigned int GG_AddTexture(GG_TextureManager* const textureManager, SDL_Texture* texture)
{
    if (textureManager == nullptr)
    {
        throw std::invalid_argument("textureManager can not be null.");
    }

    auto index = textureManager->_textures.size();

    textureManager->_textures.insert(std::make_pair<unsigned int, SDL_Texture*>(index, std::move(texture)));

    return index;
}

SDL_Texture* const GG_GetTexture(GG_TextureManager* const textureManager, const unsigned int key)
{
    if (textureManager == nullptr)
    {
        throw std::invalid_argument("textureManager can not be null.");
    }

    if (key < 0)
    {
        throw std::invalid_argument("key cannot be a negative value.");
    }

    try
    {
        return textureManager->_textures.at(key);
    }
    catch (const std::out_of_range& e)
    {
        return textureManager->_defaultTexture;
    }
}
