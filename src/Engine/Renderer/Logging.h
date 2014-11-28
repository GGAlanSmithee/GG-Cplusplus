#ifndef LOGGING_H_INCLUDED
#define LOGGING_H_INCLUDED

#include <string>
#include <vector>
#include <GL/glew.h>

namespace GGRendererEngine
{
    /// Holds the last encountered error
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @todo this needs to be refactored to be encapsulated
    extern std::string error;

    /// Sets an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    void SetError(const char*, const char* = "");
    
    /// Sets an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    void SetError(const char*, const unsigned char*);
    
    /// Sets an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    void SetError(const char*, const std::string&);
    
    /// Sets an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    void SetError(const char*, const std::vector<char>&);
    
    /// Sets an error text
    /// @author Alan Smithee
    /// @date created 2014-11-28
    void SetError(const char*, const int);

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

    /// Gets the latest recorded error from within the GGGraphics namespace
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @return an errormessage as a std::string
    const std::string GetError();
}


#endif // LOGGING_H_INCLUDED
