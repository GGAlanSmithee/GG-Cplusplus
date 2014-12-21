#include "System.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/Component.h"

namespace GGCoreEngine
{
    Mask CameraMask = GGUtility::ToIntegral(ComponentType::Transform) |
                      GGUtility::ToIntegral(ComponentType::Focus) |
                      GGUtility::ToIntegral(ComponentType::PointOfView) |
                      GGUtility::ToIntegral(ComponentType::Display);

    Mask MovementMask = GGUtility::ToIntegral(ComponentType::Transform) |
                        GGUtility::ToIntegral(ComponentType::Physics);

    Mask RenderMask = GGUtility::ToIntegral(ComponentType::Transform) |
                      GGUtility::ToIntegral(ComponentType::Appearance);

    void Camera(World& world)
    {
        Display*     d;
        Focus*       f;
        PointOfView* p;
        Transform*   t;

        GGRendererEngine::ClearScreen();

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & CameraMask) != CameraMask)
            {
                continue;
            }

            d = &(world.DisplayComponents[entity]);
            f = &(world.FocusComponents[entity]);
            p = &(world.PointOfViewComponents[entity]);
            t = &(world.TransformComponents[entity]);

            /// @todo use camera here
        }
    }

    void Movement(World& world)
    {
        Transform* transform;
        Physics*     physics;

        for (auto entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & MovementMask) != MovementMask)
            {
                continue;
            }

            transform = &(world.TransformComponents[entity]);
            physics     = &(world.PhysicsComponents[entity]);

            transform->Scale = glm::scale(glm::mat4(0.2f), glm::vec3(0.5f, 0.5f, 0.5f));
            transform->Rotation = glm::rotate(glm::mat4(1.0f), 76.0f, glm::vec3(0.5f, 0.38f, 1.0f));
            transform->Translation = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.1f, 0.0f));
        }
    }

    void Render(World& world)
    {
        Transform*  t;
        Appearance* a;

        GGRendererEngine::ClearScreen();

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & RenderMask) != RenderMask)
            {
                continue;
            }

            t = &(world.TransformComponents[entity]);
            a = &(world.AppearanceComponents[entity]);

            GGRendererEngine::DrawModel(t->Get(), a->Texture);
        }
    }
}
