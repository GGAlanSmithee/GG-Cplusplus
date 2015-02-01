#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Loader.h"

namespace GGLoader
{
    SDL_Texture* LoadTexture(SDL_Renderer* renderer, const std::string& path)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());

        if (surface == nullptr)
        {
            std::cerr << "Unable to load image:" << IMG_GetError() << std::endl;
            return nullptr;
        }

        auto texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_FreeSurface(surface);

        if (texture == nullptr)
        {
            std::cerr <<"Unable to create texture:" << SDL_GetError() << std::endl;
        }

        return texture;
    }
}
