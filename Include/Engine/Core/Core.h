#ifndef ENGINE_CORE_CORE_H_INCLUDED
#define ENGINE_CORE_CORE_H_INCLUDED

#include "Application/Application.h"

namespace GGCoreEngine
{
    /// Executes the core engine
    /// @author Alan Smithee
    /// @date created 2014-12-03
    /// @date changed 2015-02-01
    /// @param application the application that is using the engine
    /// @remarks runs the main loop by using other engine's functionality
    const int Execute(GGApplication::Application&);
}

#endif // ENGINE_CORE_CORE_H_INCLUDED
