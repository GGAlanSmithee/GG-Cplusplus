#include "Application/Application.h"

GG_Application::GG_Application(const GGCoreEngine::World& world) :
    _world(world)
{
    // Empty
}

const GG_World GG_Application::GetWorld() const
{
    return _world;
}
