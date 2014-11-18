#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <string>

namespace GGUtility
{
    template <typename E>
    typename std::underlying_type<E>::type ToUnderlying(E e)
    {
        return static_cast<typename std::underlying_type<E>::type>(e);
    }

    template <typename E>
    const std::string& ToString(E e)
    {
        return ToUnderlying(e);
    }

    template<typename E>
    const int ToIntegral(E e)
    {
        return ToUnderlying(e);
    }
}

#endif // UTILITY_H_INCLUDED
