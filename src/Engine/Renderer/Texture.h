#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <SDL_opengl.h>

namespace GGRendererEngine
{
    typedef struct Texture
    {
        GLenum Unit   = GL_TEXTURE0;
        GLenum Target = GL_TEXTURE_2D;
        GLuint Id     = -1;
    }
    Texture;
}

#endif // TEXTURE_H_INCLUDED
