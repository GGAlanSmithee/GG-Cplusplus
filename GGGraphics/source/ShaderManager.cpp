#include <iostream>
#include <fstream>
#include <sstream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderManager.h"
#include "Logging.h"

namespace GGGraphics
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

        auto scaleUniform = glGetUniformLocation(_program, "Scale");

        if (scaleUniform == 0xFFFFFFFF)
        {
            SetError("Unable to set scale uniform.");
            return;
        }

        _uniforms[Uniform::Scale] = scaleUniform;

        SetUniform1f(Uniform::Scale, 1.0f);

        auto worldUniform = glGetUniformLocation(_program, "World");

        if (worldUniform == 0xFFFFFFFF)
        {
            SetError("Unable to set world uniform.");
            return;
        }

        _uniforms[Uniform::World] = worldUniform;

        SetUniformMatrix4f(Uniform::World, glm::mat4(1.0));

        _uniformsWereBound = true;
    }

    const bool ShaderManager::UniformsWereBound() const
    {
        return _uniformsWereBound;
    }

    void ShaderManager::SetUniform1f(Uniform uniform, const float value)
    {
        glUniform1f(_uniforms[uniform], value);
    }

    void ShaderManager::SetUniformMatrix4f(Uniform uniform, const glm::mat4& value)
    {
        glUniformMatrix4fv(_uniforms[uniform], 1, GL_FALSE, glm::value_ptr(value));
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
}
