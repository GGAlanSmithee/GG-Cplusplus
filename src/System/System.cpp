#include "System.h"
#include "Graphics/Graphics.h"
#include "Component/Component.h"

namespace GGSystem
{
    Mask MovementMask = GGUtility::ToIntegral(GGComponent::Type::Orientation) |
                        GGUtility::ToIntegral(GGComponent::Type::Physics);

    Mask RenderMask = GGUtility::ToIntegral(GGComponent::Type::Orientation) |
                      GGUtility::ToIntegral(GGComponent::Type::Appearance);

    void Movement(GGEntity::World& world)
    {
        GGComponent::Orientation* orientation;
        GGComponent::Physics*     physics;

        for (auto entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & MovementMask) != MovementMask)
            {
                continue;
            }

            orientation = &(world.Orientation[entity]);
            physics     = &(world.Physics[entity]);

            orientation->Scale = glm::scale(glm::mat4(0.2f), glm::vec3(0.5f, 0.5f, 0.5f));
            orientation->Rotation = glm::rotate(glm::mat4(1.0f), 76.0f, glm::vec3(0.5f, 0.38f, 1.0f));
            orientation->Translation = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.1f, 0.0f));
        }
    }

    void Render(GGEntity::World& world)
    {
        GGComponent::Orientation* orientation;
        GGComponent::Appearance*  appearance;

        GGGraphics::ClearScreen();

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & RenderMask) != RenderMask)
            {
                continue;
            }

            orientation = &(world.Orientation[entity]);
            appearance = &(world.Appearance[entity]);

            GGGraphics::DrawModel(orientation->Get(), appearance->Texture);
        }
    }
}
