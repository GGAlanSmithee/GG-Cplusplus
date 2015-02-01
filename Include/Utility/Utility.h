#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <algorithm>
#include <string>
#include <sstream>
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

    /// Checks if a string ends with another string
    /// @author Alan Smithee
    /// @date created 2015-01-09
    /// @param fullString the full string to check
    /// @param ending the ending to check against
    /// @return true if fullString ends with ending, false if not
    const bool EndsWith(const std::string&, const std::string&);

    /// Checks if an array of T contains a cetrain element
    /// @author Alan Smithee
    /// @date created 2015-01-09
    /// @param arr the array to check
    /// @param element the element to check for
    /// @return true if arr contains element, false if not
    template<class T>
    const bool Contains(std::vector<T> arr, const T element)
    {
        return std::find(std::begin(arr), std::end(arr), element) != std::end(arr);
    }

    /// Rounds a floating point value to n decmial places
    /// @author Alan Smithee
    /// @date created 2015-01-14
    /// @param value the value to round
    /// @param decimalPlaces the number of decimal places to round to
    /// @return the rounded value
    /// @remarks the default value for decimal places param is 5
    const float Round(const float, const unsigned int = 5);
}

#endif // UTILITY_H_INCLUDED
