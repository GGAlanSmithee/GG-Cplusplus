#include "Application/Application.h"

namespace GGApplication
{
    Editor::Editor(GGCoreEngine::World& world) :
        _world(world)
    {
        // Empty
    }

    const GGCoreEngine::World Editor::GetWorld() const
    {
        return _world;
    }

    Game::Game(GGCoreEngine::World& world) :
        _world(world)
    {
        // Empty
    }

    const GGCoreEngine::World Game::GetWorld() const
    {
        return _world;
    }
}
