#include "Texture.h"

namespace GGResource
{
    bool textureWasLoaded = false;

    void LoadTexture(GLenum a, std::string b)
    {
        Textures[b] = Texture();
    }
}
