#include <iostream>

#include "Logging.h"

namespace
{
    enum class LoggingMethod
    {
        Console
    };

    LoggingMethod loggingMethod = LoggingMethod::Console;

    void LogErrorHelper(const std::string& error)
    {
        switch (loggingMethod)
        {
            case LoggingMethod::Console:
            {
                std::cerr << error << std::endl;

                break;
            }
            default: break;
        }
    }
}

namespace GGLoggingManager
{
    void LogError(const char* err, const char* additionalErr)
    {
        LogErrorHelper(std::string(err) + additionalErr);
    }

    void LogError(const char* err, const unsigned char* additionalErr)
    {
        LogErrorHelper(std::string(err) + reinterpret_cast<const char*>(additionalErr));
    }

    void LogError(const char* err, const std::string& additionalErr)
    {
        LogErrorHelper(err + additionalErr);
    }

    void LogError(const char* err, const std::vector<char>& additionalErr)
    {
        LogErrorHelper(err + std::string(additionalErr.begin(), additionalErr.end()));
    }

    void LogError(const char* err, const int additionalErr)
    {
        LogErrorHelper(err + std::to_string(additionalErr));
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

    void SetLoggingMethodToConsole()
    {
        loggingMethod = LoggingMethod::Console;
    }
}
