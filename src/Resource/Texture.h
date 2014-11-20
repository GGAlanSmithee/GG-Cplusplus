#ifndef GGRESOURCE_TEXTURE_H_INCLUDED
#define GGRESOURCE_TEXTURE_H_INCLUDED

#include <map>

namespace GGResource
{
    extern bool textureWasLoaded;

    void LoadTexture(GLenum a, std::string b);

    std::map<std::string, Texture> Textures;
}

#endif // GGRESOURCE_TEXTURE_H_INCLUDED
