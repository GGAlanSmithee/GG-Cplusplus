#include "Game/Game.h"

namespace GGGame
{
    Game::Game(GGCoreEngine::World& world) :
        _world(world)
    {
        // Empty
    }

    /// Gets the games world
    /// @author Alan Smithee
    /// @date created 2014-11-25
    /// @return the games world
    const GGCoreEngine::World Game::GetWorld() const
    {
        return _world;
    }
}
