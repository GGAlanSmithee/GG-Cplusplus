#include "Application.h"
#include "System.h"

GG_Application::GG_Application(std::unique_ptr<GG_Engine> const& engine)
{
    camera = GG_CreateCamera(entityManager);

    GG_RegisterMouseEvent(GG_GetEvent(engine), [=](int eventType) { this->OnMouseEvent(eventType); });
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

    auto cameraPos = application->entityManager.TransformComponents[application->camera].Translation;
    auto cameraRect = application->entityManager.PhysicsComponents[application->camera].Hitbox;

    GG_RenderMap(GG_GetMap(application),
                 GG_GetRenderer(engine),
                 GG_GetTextureManager(engine),
                 cameraPos,
                 cameraRect);

    GG_RenderSystem(application->entityManager);
}

void GG_Application::OnMouseEvent(const unsigned int eventType)
{
    int x, y;
    SDL_GetMouseState( &x, &y );

    auto p = &this->entityManager.PhysicsComponents[this->camera];

    auto vel = 0.2f;
    p->Velocity.x = x < 100 ? -vel : x > 540 ? vel : 0.0f;
    p->Velocity.y = y < 100 ? -vel : y > 380 ? vel : 0.0f;
}
