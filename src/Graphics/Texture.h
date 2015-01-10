#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <SDL.h>
#include <SDL_opengl.h>

namespace GGGraphics
{
    /// Contains information about a textures shader related information, such as id, unit and target
    /// @author Alan Smithee
    /// @date created 2014-11-27
    typedef struct Texture
    {
        GLenum Unit   = GL_TEXTURE0;
        GLenum Target = GL_TEXTURE_2D;
        GLuint Id     = -1;
    }
    Texture;
}

#endif // TEXTURE_H_INCLUDED
