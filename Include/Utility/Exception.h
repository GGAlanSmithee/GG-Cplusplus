#ifndef UTILITY_EXCEPTION_H_INCLUDED
#define UTILITY_EXCEPTION_H_INCLUDED

#include <stdexcept>

/// Exception indicating that an element was attempted to be fetched from a collection using an invalid key
/// @author Alan Smithee
/// @date created 2015-03-22
class invalid_key_error : public std::runtime_error
{
    public:
        using runtime_error::runtime_error;
};

/// Exception indicating that something went wrong with initialization
/// @author Alan Smithee
/// @date created 2015-02-07
class init_error : public std::runtime_error
{
    public:
        using runtime_error::runtime_error;
};

/// Exception indicating that a file was not found
/// @author Alan Smithee
/// @date created 2015-02-09
class file_not_found_error : public std::runtime_error
{
    public:
        using runtime_error::runtime_error;
};

/// Exception indicating that a SDL function failed
/// @author Alan Smithee
/// @date created 2015-02-09
class sdl_error : public std::runtime_error
{
    public:
        using runtime_error::runtime_error;
};

#endif // UTILITY_EXCEPTION_H_INCLUDED
