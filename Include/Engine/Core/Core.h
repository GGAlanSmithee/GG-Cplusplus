#ifndef ENGINE_CORE_CORE_H_INCLUDED
#define ENGINE_CORE_CORE_H_INCLUDED

#include "Application/Application.h"

/// Initialized SDL
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param flags the flags used to initialize SDL
/// @exception init_error could not initialize SDL
void GG_InitializeSDL(const int);

/// Initialized SDL image
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param flags the flags used to initialize SDL image
/// @exception init_error could not initialize SDL image
void GG_InitializeSDLImage(const int);

/// Executes the core engine
/// @author Alan Smithee
/// @date created 2014-12-03
/// @date changed 2015-02-01
/// @param application the application that is using the engine
/// @remarks runs the main loop by using other engine's functionality
const int GG_Execute(GG_Application&);

#endif // ENGINE_CORE_CORE_H_INCLUDED
