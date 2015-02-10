#include "Application/Application.h"

GG_Application::GG_Application(const GG_World& world) :
    _world(world)
{
    // Empty
}

GG_Application* const GG_CreateApplication(const GG_World& world)
{
    return new GG_Application(world);
}

void GG_DestroyApplication(GG_Application* application)
{
    if (application == nullptr)
    {
        return;
    }

    delete application;
    application = nullptr;
}

const GG_World GG_GetWorld(GG_Application* const application)
{
    if (application == nullptr)
    {
        throw std::invalid_argument("application cannot be null.");
    }

    return application->_world;
}
