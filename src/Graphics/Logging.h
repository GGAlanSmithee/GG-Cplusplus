#ifndef LOGGING_H_INCLUDED
#define LOGGING_H_INCLUDED

#include <string>
#include <vector>
#include <GL/glew.h>

namespace GGGraphics
{
    extern std::string error;

    void SetError(const char*, const char* = "");
    void SetError(const char*, const unsigned char*);
    void SetError(const char*, const std::string&);
    void SetError(const char*, const std::vector<char>&);
    void SetError(const char*, const int);

    const std::vector<GLchar> GetShaderInfoLog(const GLuint);
    const std::vector<GLchar> GetProgramInfoLog(const GLuint);

    /// @author Alan Smithee
    /// Gets the latest recorded error from within the GGGraphics namespace
    /// @return an errormessage as a std::string
    const std::string GetError();
}


#endif // LOGGING_H_INCLUDED
