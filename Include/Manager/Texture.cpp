#include <dirent.h>
#include <stdexcept>
#include "Texture.h"
#include "Utility/Utility.h"

GG_TextureManager::GG_TextureManager(std::unique_ptr<GG_TextureLoader> textureLoader,
                                     std::unique_ptr<GG_Renderer> const& renderer,
                                     std::string const& gfxPath) :
    _textureLoader(std::move(textureLoader)),
    _gfxPath(gfxPath)
{
    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null.");
    }

    auto surface = SDL_CreateRGBSurface(0, 33, 33, 32, 0, 0, 0, 0);

    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 100, 149, 237));

    _defaultTexture = SDL_CreateTextureFromSurface(GG_GetSDLRenderer(renderer), surface);
}

GG_TextureManager::~GG_TextureManager()
{
    for (auto texture : _textures)
    {
        if (texture != nullptr)
        {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }
}

std::string const& GG_GetPath(std::unique_ptr<GG_TextureManager> const& textureManager)
{
    if (!textureManager)
    {
        throw std::invalid_argument("textureManager cannot be null.");
    }

    return textureManager->_gfxPath;
}

void GG_AddTexture(std::unique_ptr<GG_TextureManager> const& textureManager,
                   std::unique_ptr<GG_Renderer> const& renderer,
                   std::string const& name)
{
    if (!textureManager)
    {
        throw std::invalid_argument("textureManager cannot be null.");
    }

    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null.");
    }

    auto texture = GG_LoadTexture(textureManager->_textureLoader, renderer, name);

    auto index = 0;
    while (index < textureManager->_textures.size())
    {
        if (textureManager->_textures[index] == nullptr)
        {
            break;
        }

        ++index;
    }

    if (index >= textureManager->_textures.size())
    {
        textureManager->_textures.push_back(texture);
    }
    else
    {
        textureManager->_textures[index] = texture;
    }
}

void GG_AddAllTextures(std::unique_ptr<GG_TextureManager> const& textureManager,
                       std::unique_ptr<GG_Renderer> const& renderer)
{
    if (!textureManager)
    {
        throw std::invalid_argument("textureManager cannot be null.");
    }

    if (!renderer)
    {
        throw std::invalid_argument("renderer cannot be null.");
    }

    auto dir = opendir(GG_GetPath(textureManager).c_str());

    if (dir == nullptr)
    {
        throw std::runtime_error("could not open path " + GG_GetPath(textureManager));
    }

    while (auto entity = readdir(dir))
    {
        std::string filename(entity->d_name);

        if (!GG_Utility::EndsWith(filename, ".png"))
        {
            continue;
        }

        GG_AddTexture(textureManager, renderer, filename);
    }

    closedir(dir);
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
