#include "Logging.h"

namespace GGRendererEngine
{
    std::string error = "";

    void SetError(const char* err, const char* additionalErr)
    {
        error = std::string(err) + additionalErr;
    }

    void SetError(const char* err, const unsigned char* additionalErr)
    {
        error = std::string(err) + reinterpret_cast<const char*>(additionalErr);
    }

    void SetError(const char* err, const std::string& additionalErr)
    {
        error = err + additionalErr;
    }

    void SetError(const char* err, const std::vector<char>& additionalErr)
    {
        error = err + std::string(additionalErr.begin(), additionalErr.end());
    }

    void SetError(const char* err, const int additionalErr)
    {
        error = err + std::to_string(additionalErr);
    }

    const std::vector<GLchar> GetShaderInfoLog(const GLuint shader)
    {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

        return infoLog;
    }

    const std::vector<GLchar> GetProgramInfoLog(const GLuint program)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        return infoLog;
    }

    const std::string GetError()
    {
        return error;
    }
}
