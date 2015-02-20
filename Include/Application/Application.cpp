#include "Application.h"
#include "System.h"

GG_Application::GG_Application()
{
    // Empty
}

GG_Application::~GG_Application()
{
    // Empty
}

GG_Map const& GG_GetMap(std::unique_ptr<GG_Application> const& application)
{
    if (!application)
    {
        throw std::invalid_argument("application cannot be null.");
    }

    return application->map;
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

    GG_MovementSystem(application->entityManager);
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

    SDL_Rect cameraRect = { 15, 15, 20, 15 };

    GG_RenderMap(GG_GetMap(application), GG_GetRenderer(engine), GG_GetTextureManager(engine), cameraRect);

    GG_RenderSystem(application->entityManager);
}
