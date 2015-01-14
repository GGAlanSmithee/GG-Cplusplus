#include "System.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/Component.h"

namespace // Private varaibles and functions
{
    using Mask = std::bitset<GGCoreEngine::NumbComponentTypes>;

    Mask CameraMask = GGUtility::ToIntegral(GGCoreEngine::ComponentType::Transform) |
                      GGUtility::ToIntegral(GGCoreEngine::ComponentType::Focus) |
                      GGUtility::ToIntegral(GGCoreEngine::ComponentType::PointOfView) |
                      GGUtility::ToIntegral(GGCoreEngine::ComponentType::Display);

    Mask MovementMask = GGUtility::ToIntegral(GGCoreEngine::ComponentType::Transform) |
                        GGUtility::ToIntegral(GGCoreEngine::ComponentType::Physics);

    Mask RenderMask = GGUtility::ToIntegral(GGCoreEngine::ComponentType::Transform) |
                      GGUtility::ToIntegral(GGCoreEngine::ComponentType::Appearance);
}

namespace GGCoreEngine
{
    void Camera(World& world)
    {
        Display*     d;
        Focus*       f;
        PointOfView* p;
        Transform*   t;

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
            transform->Rotation = glm::rotate(glm::mat4(1.0f), 76.0f, glm::vec3(0.75f, 1.0f, 0.302f));
            transform->Translation = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.1f, 0.0f));
        }
    }

    void Render(World& world)
    {
        Transform*  t;
        Appearance* a;

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & RenderMask) != RenderMask)
            {
                continue;
            }

            t = &(world.TransformComponents[entity]);
            a = &(world.AppearanceComponents[entity]);

            GGRendererEngine::DrawModel(t->Get(), a->Scene, a->Shader);
        }
    }
}
