#include "Application.h"

GG_Application::GG_Application()
{
    // Empty
}

GG_Application::~GG_Application()
{
    // Empty
}

void GG_OnLogic(std::unique_ptr<GG_Application> const& application, std::unique_ptr<GG_Engine> const& engine)
{
    if (!application)
    {
        throw std::invalid_argument("application cannot be null.");
    }

    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }
}

void GG_OnRender(std::unique_ptr<GG_Application> const& application, std::unique_ptr<GG_Engine> const& engine)
{
    if (!application)
    {
        throw std::invalid_argument("application cannot be null.");
    }

    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }
}
