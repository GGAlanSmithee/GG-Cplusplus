#ifndef APPLICATION_APPLICATIONDATA_H_INCLUDED
#define APPLICATION_APPLICATIONDATA_H_INCLUDED

#include <unordered_map>

using GG_Type = unsigned;

template<GG_Type NAME, typename T>
struct GG_ApplicationDataEntry
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
        inline decltype(T::value_type) & Read()
        {
            return data<T>()[id].value_type;
        }

        template<typename T>
        inline decltype(T::value_type)* Write()
        {
            return &data<T>()[id].value_type;
        }

        template<typename T>
        inline void Add(decltype(T::value_type) t)
        {
            data<T>()[id].value_type = t;
        }

        static GG_Type Count()
        {
            static GG_Type applicationDataCount = 0;
            return applicationDataCount++;
        }

    private:
        const GG_Type id;

        template<typename T>
        static std::unordered_map<GG_Type, T>& data()
        {
            static std::unordered_map<GG_Type, T> objects;
            return objects;
        }
};

#endif // APPLICATION_APPLICATIONDATA_H_INCLUDED
