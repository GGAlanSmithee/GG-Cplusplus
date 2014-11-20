#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <SDL_opengl.h>

namespace GGGraphics
{
    typedef struct Texture
    {
        Texture(const GLenum target = GL_TEXTURE_2D, std::string path = "") :
            Path(path),
            Target(target),
            Id(-1)
        {

        }

        std::string Path;
        GLenum      Target;
        GLuint      Id;
    }
    Texture;
}

#endif // TEXTURE_H_INCLUDED
