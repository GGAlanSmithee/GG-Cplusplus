#include "System.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/Component.h"

namespace GGCoreEngine
{
    Mask MovementMask = GGUtility::ToIntegral(ComponentType::Transform) |
                        GGUtility::ToIntegral(ComponentType::Physics);

    Mask RenderMask = GGUtility::ToIntegral(ComponentType::Transform) |
                      GGUtility::ToIntegral(ComponentType::Appearance);

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
        Transform* transform;
        Appearance*  appearance;

        GGRendererEngine::ClearScreen();

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & RenderMask) != RenderMask)
            {
                continue;
            }

            transform = &(world.TransformComponents[entity]);
            appearance = &(world.AppearanceComponents[entity]);

            GGRendererEngine::DrawModel(transform->Get(), appearance->Texture);
        }
    }
}
