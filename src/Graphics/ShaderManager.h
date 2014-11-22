#ifndef SHADER_MANAGER_H_INCLUDED
#define SHADER_MANAGER_H_INCLUDED

#include <string>
#include <map>
#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm.hpp>
#include "Pipeline.h"
#include "Enum/Enum.h"
#include "Texture.h"

namespace GGGraphics
{
    class ShaderManager
    {
        public:
            /// Creates an opengl program by linking and building it and associated shaders
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @todo inject shaders
            void CreateProgram();

            /// Returns a boolean value indicating if the program was built
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @return true if the program was built succesfully, false if not
            const bool ProgramWasCreated() const;

            /// Loads all textures
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @remarks The textures that are loaded are stored in the Handles structure in the Texture map
            void LoadTextures();

            /// Returns a boolean value indicating if the textures were loaded
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @return true if the textures were loaded succesfully, false if not
            const bool TexturesWereLoaded() const;

            /// Binds all uniforms
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @remarks The uniforms that are bound are stored in the Handles structure in the Texture map
            void BindUniforms();

            /// Returns a boolean value indicating if the uniforms were bound
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @return true if the uniforms were bound succesfully, false if not
            const bool UniformsWereBound() const;

            /// Sets the value of an uniform by binding its value to the glsl uniform
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @param uniform the uniform to set
            /// @param value the value to set
            void SetUniform1i(const GGEnum::Uniform, const int);

            /// Sets the value of an uniform by binding its value to the glsl uniform
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @param uniform the uniform to set
            /// @param value the value to set
            void SetUniform1f(const GGEnum::Uniform, const float);

            /// Sets the value of an uniform by binding its value to the glsl uniform
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @param uniform the uniform to set
            /// @param value the value to set
            void SetUniformMatrix4f(const GGEnum::Uniform, const glm::mat4&);

            /// Activates a texture on the shader
            /// @author Alan Smithee
            /// @date 2014-11-22
            /// @param texture the texture to activate
            void ActivateTexture(const GGEnum::Texture);

        private:
            const Texture LoadTexture(const std::string&, const GLenum, const GLenum);
            const GLuint CompileShader(const GLenum, const std::string&) const;
            const std::string GetShaderSource(const std::string&) const;

            GLuint _program;

            std::map<GGEnum::Uniform, GLuint>  _uniforms;
            std::map<GGEnum::Texture, Texture> _textures;

            bool _programWasBuilt   = false;
            bool _uniformsWereBound = false;
            bool _texturesWereLoaded = false;
    };
}

#endif // SHADER_MANAGER_H_INCLUDED
