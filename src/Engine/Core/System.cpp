#include "System.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/Component.h"

namespace GGCoreEngine
{
    Mask MovementMask = GGUtility::ToIntegral(ComponentType::Orientation) |
                        GGUtility::ToIntegral(ComponentType::Physics);

    Mask RenderMask = GGUtility::ToIntegral(ComponentType::Orientation) |
                      GGUtility::ToIntegral(ComponentType::Appearance);

    void Movement(World& world)
    {
        Orientation* orientation;
        Physics*     physics;

        for (auto entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & MovementMask) != MovementMask)
            {
                continue;
            }

            orientation = &(world.OrientationComponents[entity]);
            physics     = &(world.PhysicsComponents[entity]);

            orientation->Scale = glm::scale(glm::mat4(0.2f), glm::vec3(0.5f, 0.5f, 0.5f));
            orientation->Rotation = glm::rotate(glm::mat4(1.0f), 76.0f, glm::vec3(0.5f, 0.38f, 1.0f));
            orientation->Translation = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.1f, 0.0f));
        }
    }

    void Render(World& world)
    {
        Orientation* orientation;
        Appearance*  appearance;

        GGRendererEngine::ClearScreen();

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & RenderMask) != RenderMask)
            {
                continue;
            }

            orientation = &(world.OrientationComponents[entity]);
            appearance = &(world.AppearanceComponents[entity]);

            GGRendererEngine::DrawModel(orientation->Get(), appearance->Texture);
        }
    }
}
