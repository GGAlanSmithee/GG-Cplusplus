#ifndef SHADER_MANAGER_H_INCLUDED
#define SHADER_MANAGER_H_INCLUDED

#include <string>
#include <map>
#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm.hpp>
#include "Pipeline.h"

namespace GGGraphics
{
    enum class Uniform : int
    {
        MVP
    };

    class ShaderManager
    {
        public:
            /// @author Alan Smithee
            /// Creates an opengl program by linking and building it and associated shaders
            /// @todo inject shaders
            void CreateProgram();

            /// @author Alan Smithee
            /// Returns a boolean value indicating if the program was built
            /// @return true if the program was built succesfully, false if not
            const bool ProgramWasCreated() const;

            /// @author Alan Smithee
            /// Binds all uniforms
            void BindUniforms();

            /// @author Alan Smithee
            /// Returns a boolean value indicating if the uniforms were bound
            /// @return true if the uniforms were bound succesfully, false if not
            const bool UniformsWereBound() const;

            /// @author Alan Smithee
            /// Sets the value of an uniform by binding its value to the glsl uniform
            /// @param uniform the uniform to set
            /// @param value the value to set
            void SetUniform1f(Uniform, const float);

            /// @author Alan Smithee
            /// Sets the value of an uniform by binding its value to the glsl uniform
            /// @param uniform the uniform to set
            /// @param value the value to set
            void SetUniformMatrix4f(Uniform, const glm::mat4&);

        private:
            const GLuint CompileShader(const GLenum, const std::string&) const;
            const std::string GetShaderSource(const std::string&) const;

            GLuint _program;

            std::map<Uniform, GLuint> _uniforms;

            bool _programWasBuilt   = false;
            bool _uniformsWereBound = false;
    };
}

#endif // SHADER_MANAGER_H_INCLUDED
