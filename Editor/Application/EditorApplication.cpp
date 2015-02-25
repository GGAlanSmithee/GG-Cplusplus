#include "Application/System.h"
#include "EditorApplication.h"
#include "../Utility/Declarations.h"

EditorApplication::EditorApplication(std::unique_ptr<GG_Engine> const& engine,
                                     std::shared_ptr<GG_ApplicationData> data) :
    GG_Application(data)
{
    auto windowRect = GG_GetWindowSize(GG_GetRenderer(engine));

    GG_RegisterMouseEvent(GG_GetEvent(engine),
                          [&](int eventType)
                          {
                              this->OnMouseEvent(eventType,
                                                 GG_GetDelta(GG_GetTimer(engine)),
                                                 GG_GetWindowSize(GG_GetRenderer(engine)));
                          });
}

EditorApplication::~EditorApplication()
{
    // Empty
}

void EditorApplication::OnLogic(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

    /// @todo log delta
    // std::cout << GG_GetDelta(GG_GetTimer(engine)) << std::endl;

    GG_MovementSystem(data->Get<EntityManagerEntry>(), GG_GetDelta(GG_GetTimer(engine)));
}

void EditorApplication::OnRender(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

    auto entityManager = data->Get<EntityManagerEntry>();
    auto camera = data->Get<CameraEntry>();

    auto cameraPos = entityManager.TransformComponents[camera].Translation;
    auto cameraRect = entityManager.PhysicsComponents[camera].Hitbox;

    GG_RenderMap(data->Get<MapEntry>(),
                 GG_GetRenderer(engine),
                 GG_GetTextureManager(engine),
                 cameraPos,
                 cameraRect);

    GG_RenderSystem(entityManager);
}

void EditorApplication::OnMouseEvent(const unsigned int eventType,
                                     const float delta,
                                     const SDL_Rect windowRect)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    auto camera = data->Get<CameraEntry>();
    auto p = &data->Get<EntityManagerEntry>().PhysicsComponents[camera];

    auto vel = 8.0f;

    auto leftBorder = windowRect.w * 0.15f;
    auto rightBorder = windowRect.w - leftBorder;
    auto topBorder = windowRect.h * 0.15f;
    auto bottomBorder = windowRect.h - topBorder;

    p->Velocity.x = x < leftBorder ? -vel : x > rightBorder ? vel : 0.0f;
    p->Velocity.y = y < topBorder ? -vel : y > bottomBorder ? vel : 0.0f;
}
