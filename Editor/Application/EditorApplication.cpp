#include "Application/System.h"
#include "EditorApplication.h"
#include "../Utility/Declarations.h"

EditorApplication::EditorApplication(std::unique_ptr<GG_Engine> const& engine,
                                     std::shared_ptr<GG_ApplicationData> data) :
    GG_Application(data)
{
    data->Add<CameraEntry>(GG_CreateCamera(*data->Write<EntityManagerEntry>()));

    GG_RegisterMouseEvent(GG_GetEvent(engine),
                          [&](int eventType)
                          {
                              this->OnMouseEvent(eventType, GG_GetDelta(GG_GetTimer(engine)));
                          });
}

EditorApplication::~EditorApplication()
{
    /// @todo unregister mouse event
    // Empty
}

void EditorApplication::OnLogic(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

    GG_MovementSystem(*data->Write<EntityManagerEntry>());
}

void EditorApplication::OnRender(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

    auto entityManager = data->Read<EntityManagerEntry>();
    auto camera = data->Read<CameraEntry>();

    auto cameraPos = entityManager.TransformComponents[camera].Translation;
    auto cameraRect = entityManager.PhysicsComponents[camera].Hitbox;

    GG_RenderMap(data->Read<MapEntry>(),
                 GG_GetRenderer(engine),
                 GG_GetTextureManager(engine),
                 cameraPos,
                 cameraRect);

    GG_RenderSystem(data->Read<EntityManagerEntry>());
}

void EditorApplication::OnMouseEvent(const unsigned int eventType, const float delta)
{
    int x, y;
    SDL_GetMouseState( &x, &y );

    auto camera = data->Read<CameraEntry>();
    auto p = &data->Write<EntityManagerEntry>()->PhysicsComponents[camera];

    auto vel = 75.0f * delta;

    p->Velocity.x = x < 100 ? -vel : x > 540 ? vel : 0.0f;
    p->Velocity.y = y < 100 ? -vel : y > 380 ? vel : 0.0f;
}
