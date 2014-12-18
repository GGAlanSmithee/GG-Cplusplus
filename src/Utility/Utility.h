#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <string>
#include <sstream>
#include <string>
#include <vector>

namespace GGUtility
{
    /// Converts an enum variable to its underlying type
    /// @author Alan Smithee
    /// @date created 2014-11-25
    /// @param e the enum to cast
    /// @return e as its underlying type
    template <typename E>
    typename std::underlying_type<E>::type ToUnderlying(E e)
    {
        return static_cast<typename std::underlying_type<E>::type>(e);
    }

    /// Converts an enum variable to an integral value
    /// @author Alan Smithee
    /// @date created 2014-11-25
    /// @param e the enum to cast
    /// @return e as an integer
    template<typename E>
    const int ToIntegral(E e)
    {
        return ToUnderlying(e);
    }

    /// Splits a string by a character into a vector of substrings
    /// @author Alan Smithee
    /// @date created 2014-12-15
    /// @param s the string to split
    /// @param delim the delimeter to split the string at
    /// @return a vector of substrings
    std::vector<std::string> Split(const std::string&, char);

    /// Converts a space separated string of int values to an array of ints
    /// @author Alan Smithee
    /// @date created 2014-12-15
    /// @param s the string to split
    /// @return a vector of ints
    /// @remark the string is split using the Split function, and then converted to integers
    std::vector<int> ToInts(const std::string&);

    /// Converts a space separated string of float values to an array of floats
    /// @author Alan Smithee
    /// @date created 2014-12-15
    /// @param s the string to split
    /// @return a vector of floats
    /// @remark the string is split using the Split function, and then converted to floats
    std::vector<float> ToFloats(const std::string&);
}

#endif // UTILITY_H_INCLUDED
