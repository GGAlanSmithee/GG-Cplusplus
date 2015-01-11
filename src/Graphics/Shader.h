#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <map>
#include <string>

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "Enum/Enum.h"

namespace GGGraphics
{
    /// Represents a glsl shader and contains information about its uniforms and program etc
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-01-10
    typedef struct Shader
    {
        /// The name of the shader
        /// @author Alan Smithee
        /// @date created 2015-01-11
        std::string Name;

        /// The program of the shader
        /// @author Alan Smithee
        /// @date created 2015-01-10
        GLuint Program;

        /// The uniforms of the shader
        /// @author Alan Smithee
        /// @date created 2015-01-10
        std::map<GGEnum::Uniform, GLuint> Uniforms;
    }
    Shader;
}

#endif // SHADER_H_INCLUDED
