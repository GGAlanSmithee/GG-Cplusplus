#ifndef LOADER_LOADER_H_INCLUDED
#define LOADER_LOADER_H_INCLUDED

#include <string>

namespace GGLoader
{
    SDL_Texture* LoadTexture(SDL_Renderer*, const std::string&);
};

#endif // LOADER_LOADER_H_INCLUDED
