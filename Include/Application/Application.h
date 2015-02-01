#ifndef APPLICATION_APPLICATION_H_INCLUDED
#define APPLICATION_APPLICATION_H_INCLUDED

#include <memory>
#include "Engine/Core/World.h"

namespace GGApplication
{
     /// Represents an application instance and serves as the main starting point of any application using the GGEngine
    /// @author Alan Smithee
    /// @date created 2014-11-25
    /// @date changed 2014-12-03
    class Application
    {
        public:
            /// Default constructor for initializing a Application instance
            /// @author Alan Smithee
            /// @date created 2014-11-25
            /// @param world the world holding enteties that live withing the scope of the application
            Application(const GGCoreEngine::World&);

            /// Gets the applications world
            /// @author Alan Smithee
            /// @date created 2014-11-25
            /// @return the applications world
            const GGCoreEngine::World GetWorld() const;

        private:
            GGCoreEngine::World _world;
    };
}

#endif // APPLICATION_APPLICATION_H_INCLUDED
