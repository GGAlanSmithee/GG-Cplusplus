#ifndef APPLICATION_APPLICATIONDATA_H_INCLUDED
#define APPLICATION_APPLICATIONDATA_H_INCLUDED

#include <unordered_map>

using type = unsigned;

struct GG_IApplicationDataEntry
{
    virtual ~GG_IApplicationDataEntry() {}
};

template<type NAME, typename T>
struct GG_ApplicationDataEntry : GG_IApplicationDataEntry
{
    T value_type;
};

class GG_ApplicationData
{
    public:
        GG_ApplicationData() :
            id(GG_ApplicationData::Count())
        {
            // Empty
        }

        template<typename T>
        inline decltype(T::value_type)& Get()
        {
            return data<T>()[id].value_type;
        }

        template<typename T>
        inline void Add(decltype(T::value_type) t)
        {
            data<T>()[id].value_type = t;
        }

        static type Count()
        {
            static type applicationDataCount = 0;
            return applicationDataCount++;
        }

    private:
        const type id;

        template<typename T>
        static std::unordered_map<type, T>& data()
        {
            static std::unordered_map<type, T> objects;
            return objects;
        }
};

#endif // APPLICATION_APPLICATIONDATA_H_INCLUDED
