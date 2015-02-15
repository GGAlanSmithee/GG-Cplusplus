#include <iostream>
#include "Texture.h"

GG_TextureManager::GG_TextureManager(std::unique_ptr<GG_TextureLoader> textureLoader) :
    _textureLoader(std::move(textureLoader))
{
    // Empty
}

GG_TextureManager::~GG_TextureManager()
{
    for (auto& kvp : _textures)
    {
        if (kvp.second != nullptr)
        {
            SDL_DestroyTexture(kvp.second);
            kvp.second = nullptr;
        }
    }
}

const unsigned int GG_AddTexture(std::unique_ptr<GG_TextureManager> const& textureManager,
                                 std::unique_ptr<GG_Renderer> const& renderer,
                                 const std::string& name)
{
    if (!textureManager)
    {
        throw std::invalid_argument("textureManager cannot be null.");
    }

    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null.");
    }

    auto index = textureManager->_textures.size();

    textureManager->_textures[index] = GG_LoadTexture(textureManager->_textureLoader, renderer, name);

    return index;
}

SDL_Texture* const GG_GetTexture(std::unique_ptr<GG_TextureManager> const& textureManager, const unsigned int key)
{
    if (!textureManager)
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

void GG_SetDefaultTexture(std::unique_ptr<GG_TextureManager> const& textureManager,
                          std::unique_ptr<GG_Renderer> const& renderer,
                          const std::string& name)
{
    if (!textureManager)
    {
        throw std::invalid_argument("textureManager cannot be null.");
    }

    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null.");
    }

    textureManager->_defaultTexture = GG_LoadTexture(textureManager->_textureLoader, renderer, name);
}
