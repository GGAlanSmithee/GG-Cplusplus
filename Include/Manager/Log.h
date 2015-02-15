#ifndef LOGGING_H_INCLUDED
#define LOGGING_H_INCLUDED

#include <string>
#include <vector>
#include <GL/glew.h>

namespace GGLoggingManager
{
    /// Logs an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-01-11
    void LogError(const char*, const char* = "");

    /// Logs an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-01-11
    void LogError(const char*, const unsigned char*);

    /// Logs an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-01-11
    void LogError(const char*, const std::string&);

    /// Logs an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-01-11
    void LogError(const char*, const std::vector<char>&);

    /// Logs an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-01-11
    void LogError(const char*, const int);

    /// Retrieves the info log from a shader
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @param shader the id of the sahder to get the log for
    /// @return an errormessage as a char vector
    const std::vector<GLchar> GetShaderInfoLog(const GLuint);

    /// Retrieves the info log from a shader program
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @param program the id of the program to get the log for
    /// @return an errormessage as a char vector
    const std::vector<GLchar> GetProgramInfoLog(const GLuint);

    /// Sets the logging method to console
    /// @author Alan Smithee
    /// @date created 2014-11-28
    void SetLoggingMethodToConsole();
}


#endif // LOGGING_H_INCLUDED
