#ifndef UTILITY_EXCEPTION_H_INCLUDED
#define UTILITY_EXCEPTION_H_INCLUDED

#include <stdexcept>

/// Exception indicating that something went wrong with initialization
/// @author Alan Smithee
/// @date created 2015-02-07
class init_error : public std::runtime_error
{
    public:
        using runtime_error::runtime_error;
};

#endif // UTILITY_EXCEPTION_H_INCLUDED
