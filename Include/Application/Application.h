#ifndef APPLICATION_APPLICATION_H_INCLUDED
#define APPLICATION_APPLICATION_H_INCLUDED

#include "Engine/Core/World.h"

/// Represents an application instance and serves as the main starting point of any application using the GGEngine
/// @author Alan Smithee
/// @date created 2014-11-25
/// @date changed 2015-02-04
class GG_Application
{
    public:
        friend GG_Application* const GG_CreateApplication(const GG_World&);
        friend void GG_DestroyApplication(GG_Application*);
        friend const GG_World GG_GetWorld(GG_Application* const);

    private:
        /// Default constructor for initializing a Application instance
        /// @author Alan Smithee
        /// @date created 2014-11-25
        /// @param world the world holding enteties that live withing the scope of the application
        GG_Application(const GG_World&);

        GG_World _world;
};

/// Creates a GG_Application* instance
/// @author Alan Smithee
/// @date created 2015-02-10
/// @param world the entity world of the \a application
/// @return the newly created GG_Application*
/// @remarks friend of GG_Application
GG_Application* const GG_CreateApplication(const GG_World&);

/// Destroys a GG_Application* instance
/// @author Alan Smithee
/// @date created 2015-02-10
/// @param application the GG_Application* to destroy
/// @remarks friend of GG_Application
void GG_DestroyApplication(GG_Application*);

/// Gets the applications world
/// @author Alan Smithee
/// @date created 2014-11-25
/// @date changed 2015-02-10
/// @param application the GG_Application to get the world from
/// @return the world of the \a application
/// @exception throws a std::invalid_argument if \a application is null
/// @remarks friend of GG_Application
const GG_World GG_GetWorld(GG_Application* const);

#endif // APPLICATION_APPLICATION_H_INCLUDED
