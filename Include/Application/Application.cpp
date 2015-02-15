#include "Application.h"

GG_Application::GG_Application()
{
    // Empty
}

GG_Application::~GG_Application()
{
    // Empty
}

GG_Application* const GG_CreateApplication()
{
    return new GG_Application();
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

void GG_OnEvent(GG_Application* const application, std::unique_ptr<GG_Engine> const& engine)
{
    // Empty
}

void GG_OnLogic(GG_Application* const application, std::unique_ptr<GG_Engine> const& engine)
{
    // Empty
}

void GG_OnRender(GG_Application* const application, std::unique_ptr<GG_Engine> const& engine)
{
    // Empty
}
