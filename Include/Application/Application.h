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
        /// Default constructor for initializing a Application instance
        /// @author Alan Smithee
        /// @date created 2014-11-25
        /// @param world the world holding enteties that live withing the scope of the application
        GG_Application(const GG_World&);

        /// Gets the applications world
        /// @author Alan Smithee
        /// @date created 2014-11-25
        /// @return the applications world
        const GG_World GetWorld() const;

    private:
        GG_World _world;
};

#endif // APPLICATION_APPLICATION_H_INCLUDED
