#include <iostream>
#include <fstream>
#include <sstream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderManager.h"
#include "Logging.h"
#include <SDL_image.h>

namespace GGRendererEngine
{
    void ShaderManager::CreateProgram()
    {
        _programWasBuilt = false;

        auto vertexShader = CompileShader(GL_VERTEX_SHADER, "Basic.vs");

        if (vertexShader == 0)
        {
            return;
        }

        auto fragmentShader = CompileShader(GL_FRAGMENT_SHADER, "Basic.fs");

        if (fragmentShader == 0)
        {
            glDeleteShader(vertexShader);

            return;
        }

        _program = glCreateProgram();

        glAttachShader(_program, vertexShader);
        glAttachShader(_program, fragmentShader);

        glLinkProgram(_program);

        GLint isLinked = 0;
        glGetProgramiv(_program, GL_LINK_STATUS, (int*)&isLinked);

        if (isLinked == GL_FALSE)
        {
            SetError("Could not link program: ", GetProgramInfoLog(_program));

            glDeleteProgram(_program);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            return;
        }

        glDetachShader(_program, vertexShader);
        glDetachShader(_program, fragmentShader);

        glValidateProgram(_program);

        GLint isValid = 0;
        glGetProgramiv(_program, GL_VALIDATE_STATUS, &isValid);

        if (isValid == GL_FALSE)
        {
            SetError("Program is not valid: ", GetProgramInfoLog(_program));

            glDeleteProgram(_program);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            return;
        }

        _programWasBuilt = true;

        glUseProgram(_program);
    }

    const bool ShaderManager::ProgramWasCreated() const
    {
        return _programWasBuilt;
    }

    void ShaderManager::BindUniforms()
    {
        _uniformsWereBound = false;

        auto mvpUniform = glGetUniformLocation(_program, "MVP");

        if (mvpUniform == 0xFFFFFFFF)
        {
            SetError("Unable to set MVP uniform.");
            return;
        }

        _uniforms[GGEnum::Uniform::MVP] = mvpUniform;

        SetUniformMatrix4f(GGEnum::Uniform::MVP, glm::mat4(1.0));

        auto textureSamplerUniform = glGetUniformLocation(_program, "TextureSampler");

        if (textureSamplerUniform == 0xFFFFFFFF)
        {
            SetError("Unable to set TextureSampler uniform.");
            return;
        }

        _uniforms[GGEnum::Uniform::TextureSampler] = textureSamplerUniform;

        SetUniform1i(GGEnum::Uniform::TextureSampler, 0);

        _uniformsWereBound = true;
    }

    const bool ShaderManager::UniformsWereBound() const
    {
        return _uniformsWereBound;
    }

    void ShaderManager::LoadTextures()
    {
        _texturesWereLoaded = false;

        auto texture = LoadTexture("../gfx/crate.jpg", GL_TEXTURE0, GL_TEXTURE_2D);

        if (texture.Id == -1)
        {
            return;
        }

        _textures[GGEnum::Texture::Crate] = texture;

        _texturesWereLoaded = true;
    }

    const bool ShaderManager::TexturesWereLoaded() const
    {
        return _texturesWereLoaded;
    }

    void ShaderManager::SetUniform1i(const GGEnum::Uniform uniform, const int value)
    {
        glUniform1i(_uniforms[uniform], value);
    }

    void ShaderManager::SetUniform1f(const GGEnum::Uniform uniform, const float value)
    {
        glUniform1f(_uniforms[uniform], value);
    }

    void ShaderManager::SetUniformMatrix4f(const GGEnum::Uniform uniform, const glm::mat4& value)
    {
        glUniformMatrix4fv(_uniforms[uniform], 1, GL_FALSE, glm::value_ptr(value));
    }

    void ShaderManager::ActivateTexture(const GGEnum::Texture texture)
    {
        glActiveTexture(_textures[texture].Unit);
        glBindTexture(_textures[texture].Target, _textures[texture].Id);
    }

    //{ Private helpers

    const GGGraphics::Texture ShaderManager::LoadTexture(const std::string& path,
                                                         const GLenum unit   = GL_TEXTURE0,
                                                         const GLenum target = GL_TEXTURE_2D)
    {
        GGGraphics::Texture texture;

        texture.Target = target;
        texture.Unit = unit;

        SDL_Surface* surface = IMG_Load(path.c_str());

        if (!surface)
        {
            SetError("Failed to load surface: ", IMG_GetError());

            return texture;
        }

        int mode;

        if (surface->format->BytesPerPixel == 3) // RGB 24bit
        {
            mode = GL_RGB;
        }
        else if (surface->format->BytesPerPixel == 4) // RGBA 32bit
        {
            mode = GL_RGBA;
        }
        else
        {
            SetError("Loaded image was of wrong format: ", path.c_str());
            SDL_FreeSurface(surface);

            return texture;
        }

        glGenTextures(1, &texture.Id);
        glBindTexture(texture.Target, texture.Id);
        glTexImage2D(texture.Target, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
        glTexParameteri(texture.Target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(texture.Target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(texture.Target, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texture.Target, GL_TEXTURE_WRAP_T, GL_REPEAT);

        SDL_FreeSurface(surface);

        return texture ;
    }

    const GLuint ShaderManager::CompileShader(const GLenum type, const std::string& fileName) const
    {
        auto shader = glCreateShader(type);

        if (shader == 0)
        {
            SetError("Could not create shader of type ", type);
            return shader;
        }

        auto shaderSource = GetShaderSource(fileName);
        auto source = (const GLchar*)shaderSource.c_str();
        glShaderSource(shader, 1, &source, 0);

        glCompileShader(shader);

        GLint isCompiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

        if (isCompiled == GL_FALSE)
        {
            SetError("Could not compile vertex shader: ", GetShaderInfoLog(shader));
            glDeleteShader(shader);
            return 0;
        }

        return shader;
    }

    const std::string ShaderManager::GetShaderSource(const std::string& path) const
    {
        std::ifstream stream(path.c_str());
        std::string file;

        if (!stream.is_open())
        {
            SetError("Could not open file with path ", path);
            return "";
        }

        std::string line;

        while (getline(stream, line))
        {
            file.append(line);
            file.append("\n");
        }

        stream.close();

        return file;
    }

    //} Private helpers
}
