#include "../Utility/Declarations.h"
#include "Application/System.h"
#include "EditorApplication.h"
#include "Gui/Element.h"

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

    guiContext = new GG_GUI_Context(GG_GetWindowLogicalSize(GG_GetRenderer(engine)));

    GG_AddChild(guiContext, new GG_GUI_Element(true,
                                               GG_GUI_Style::Relative,
                                               { 74, 74, 25, 25 },
                                               { 120, 200, 200, 255 }));
}

EditorApplication::~EditorApplication()
{
    if (guiContext == nullptr)
    {
        return;
    }

    delete guiContext;
    guiContext = nullptr;
}

void EditorApplication::OnLogic(std::unique_ptr<GG_Engine> const& engine)
{
    if (!engine)
    {
        throw std::invalid_argument("engine cannot be null.");
    }

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

    GG_Render(data->Get<MapEntry>(),
              GG_GetRenderer(engine),
              GG_GetTextureManager(engine),
              cameraPos,
              cameraRect);

    GG_RenderSystem(entityManager);

    GG_Render(guiContext, GG_GetRenderer(engine));
}

void EditorApplication::OnMouseEvent(const unsigned int eventType,
                                     const float delta,
                                     const GG_Rect windowRect)
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

    auto xVelocity = x < leftBorder ? -vel : x > rightBorder ? vel : 0.0f;
    auto yVelocity = y < topBorder ? -vel : y > bottomBorder ? vel : 0.0f;

    if (xVelocity > 0.0f && yVelocity > 0.0f || xVelocity < 0.0f && yVelocity < 0.0f)
    {
        xVelocity -= (xVelocity / 6.0f);
        yVelocity -= (yVelocity / 6.0f);
    }

    p->Velocity.x = xVelocity;
    p->Velocity.y = yVelocity;
}
