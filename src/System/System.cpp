#include "System.h"
#include "Graphics/Graphics.h"
#include "Component/Component.h"

namespace GGSystem
{
    Mask MovementMask = GGUtility::ToIntegral(GGComponent::Type::Model) |
                        GGUtility::ToIntegral(GGComponent::Type::Physics);

    Mask RenderMask = GGUtility::ToIntegral(GGComponent::Type::Model) |
                      GGUtility::ToIntegral(GGComponent::Type::Appearance);

    void Render(GGEntity::World& world)
    {
        GGComponent::Model*      model;
        GGComponent::Appearance* appearance;

        GGGraphics::ClearScreen();

        for (unsigned int entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & RenderMask) != RenderMask)
            {
                continue;
            }

            model = &(world.Model[entity]);
            appearance = &(world.Appearance[entity]);

            GGGraphics::DrawModel(model->Translation * model->Rotation * model->Scale);
        }

        GGGraphics::UpdateScreen();
    }

    void Movement(GGEntity::World& world)
    {
        GGComponent::Model*   model;
        GGComponent::Physics* physics;

        for (auto entity = 0; entity < world.Size; ++entity)
        {
            if ((world.Enteties[entity] & MovementMask) == MovementMask)
            {
                model   = &(world.Model[entity]);
                physics = &(world.Physics[entity]);

                model->Scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 1.0f));
                model->Rotation = glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f));
                model->Translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.0f));
            }
        }
    }
}
