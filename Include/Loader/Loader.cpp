#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Loader.h"
#include "Utility/Exception.h"

GG_TextureLoader::GG_TextureLoader()
{
    // Empty
}

GG_TextureLoader::~GG_TextureLoader()
{
    // Empty
}

SDL_Texture* const GG_LoadTexture(std::unique_ptr<GG_TextureLoader> const& textureLoader,
                                  std::unique_ptr<GG_Renderer> const& renderer,
                                  const std::string& name)
{
    SDL_Surface* surface = IMG_Load((textureLoader->_path + name).c_str());

    if (surface == nullptr)
    {
        throw file_not_found_error(IMG_GetError());
    }

    auto texture = SDL_CreateTextureFromSurface(GG_GetSDLRenderer(renderer), surface);

    SDL_FreeSurface(surface);

    if (texture == nullptr)
    {
        throw sdl_error(SDL_GetError());
    }

    return texture;
}
