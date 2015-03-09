#ifndef APPLICATION_APPLICATION_H_INCLUDED
#define APPLICATION_APPLICATION_H_INCLUDED

#include <memory>
#include "Engine/Core.h"
#include "Entity.h"
#include "Map.h"
#include "ApplicationData.h"

/// Abstract base class for an application using the GG Engine
/// @author Alan Smithee
/// @date created 2015-03-09
/// @remarks All apllications intending to use the engine should inherit this class, the applications can share data through the application data that is passed in to the constructor
class GG_Application
{
    public:
        /// Constructs an application
        /// @author Alan Smithee
        /// @date created 2015-03-09
        /// @param applicationData the shared data to use in the application
        GG_Application(std::shared_ptr<GG_ApplicationData>);
        virtual ~GG_Application() = 0;

        /// Executes the logic related systems of the \a application
        /// @author Alan Smithee
        /// @date created 2015-02-10
        /// @date changed 2015-02-22
        /// @param engine the GG_Engine used by the applications systems
        /// @exception throws a std::invalid_argument if \a engine is null
        virtual void OnLogic(std::unique_ptr<GG_Engine> const&) = 0;

        /// Executes the rendering related systems of the \a application
        /// @author Alan Smithee
        /// @date created 2015-02-10
        /// @date changed 2015-02-22
        /// @param engine the GG_Engine used by the applications systems
        /// @exception throws a std::invalid_argument if \a engine is null
        virtual void OnRender(std::unique_ptr<GG_Engine> const&) = 0;

    protected:
        std::shared_ptr<GG_ApplicationData> data;
};

#endif // APPLICATION_APPLICATION_H_INCLUDED
