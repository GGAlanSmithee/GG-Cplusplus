#include "Application/System.h"
#include "TestApplication.h"
#include "../Utility/Declarations.h"

TestApplication::TestApplication(std::unique_ptr<GG_Engine> const& engine,
                                 std::shared_ptr<GG_ApplicationData> data) :
    GG_Application(data)
{
    auto camera = data->Get<CameraEntry>();
    auto p = &data->Get<EntityManagerEntry>().PhysicsComponents[camera];

    p->Velocity.x = 0.0f;
    p->Velocity.y = 0.0f;

    GG_UnregisterMouseEvent(GG_GetEvent(engine));
}

TestApplication::~TestApplication()
{
    // Empty
}

void TestApplication::OnLogic(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

    GG_MovementSystem(data->Get<EntityManagerEntry>(), GG_GetDelta(GG_GetTimer(engine)));
}

void TestApplication::OnRender(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

    auto entityManager = data->Get<EntityManagerEntry>();
    auto camera = data->Get<CameraEntry>();

    auto cameraPos = entityManager.TransformComponents[camera].Translation;
    auto cameraRect = entityManager.PhysicsComponents[camera].Hitbox;

    GG_Render(data->Get<MapEntry>(),
              GG_GetRenderer(engine),
              GG_GetTextureManager(engine),
              cameraPos,
              cameraRect);

    SDL_Rect rect = { 200, 100, 200, 100 };

    SDL_RenderDrawRect(GG_GetSDLRenderer(GG_GetRenderer(engine)), &rect);

    GG_RenderSystem(data->Get<EntityManagerEntry>());
}
