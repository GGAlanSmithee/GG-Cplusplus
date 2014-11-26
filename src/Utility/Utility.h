#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <string>

namespace GGUtility
{
    /// Converts an enum variable to its underlying type
    /// @author Alan Smithee
    /// @date created 2014-11-25
    template <typename E>
    typename std::underlying_type<E>::type ToUnderlying(E e)
    {
        return static_cast<typename std::underlying_type<E>::type>(e);
    }

    /// Converts an enum variable to an integral value
    /// @author Alan Smithee
    /// @date created 2014-11-25
    template<typename E>
    const int ToIntegral(E e)
    {
        return ToUnderlying(e);
    }
}

#endif // UTILITY_H_INCLUDED
