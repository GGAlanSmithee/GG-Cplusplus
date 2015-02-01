#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include "Game/Game.h"

namespace GGCoreEngine
{
    /// Executes the core engine
    /// @author Alan Smithee
    /// @date created 2014-12-03
    /// @param game the game using the engine
    /// @remarks runs the main loop by using other engine's functionality
    const int Execute(GGGame::Game&);
}

#endif // CORE_H_INCLUDED
