#include "Application/Application.h"

namespace GGApplication
{
    Application::Application(const GGCoreEngine::World& world) :
        _world(world)
    {
        // Empty
    }

    const GGCoreEngine::World Application::GetWorld() const
    {
        return _world;
    }
}
