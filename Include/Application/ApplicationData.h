#ifndef APPLICATION_APPLICATIONDATA_H_INCLUDED
#define APPLICATION_APPLICATIONDATA_H_INCLUDED

#include <unordered_map>

using GG_Type = unsigned;

/// An dataentry struct user for applicationdata
/// @author Alan Smithee
/// @date created 2015-03-16
/// @tparam NAME identifier for the data entry
/// @tparam T type of dataentry
template<GG_Type NAME, typename T>
struct GG_ApplicationDataEntry
{
    T value_type;
};

/// Used to store application data that is to be shared between different applications
/// @author Alan Smithee
/// @date created 2015-03-16
/// @remarks the applicationdata class is more or less a wrapper of a collection of data entries
class GG_ApplicationData
{
    public:
        /// Default constructor
        /// @author Alan Smithee
        /// @date created 2015-03-16
        GG_ApplicationData() :
            id(GG_ApplicationData::Count())
        {
            // Empty
        }

        /// Gets a applicationdata entry by type
        /// @author Alan Smithee
        /// @date created 2015-03-16
        /// @remarks usage: data->Get<CameraEntry>();
        template<typename T>
        inline decltype(T::value_type)& Get()
        {
            return data<T>().at(id).value_type;
        }

        /// Adds a applicationdata entry by type
        /// @author Alan Smithee
        /// @date created 2015-03-16
        /// @remarks usage: data->Add<CameraEntry>(camera);
        template<typename T>
        inline void Add(decltype(T::value_type) t)
        {
            data<T>()[id].value_type = t;
        }

        /// Gets the number of application datas created
        /// @author Alan Smithee
        /// @date created 2015-03-16
        /// @todo: make this private!
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
