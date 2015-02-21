#include "System.h"
#include "Component.h"
#include "Utility/Utility.h"

namespace // Private varaibles and functions
{
    using Mask = std::bitset<GG_ComponentType::Total>;

    Mask MovementMask = GG_Utility::ToIntegral(GG_ComponentType::Transform) |
                        GG_Utility::ToIntegral(GG_ComponentType::Physics);

    Mask RenderMask = GG_Utility::ToIntegral(GG_ComponentType::Transform) |
                      GG_Utility::ToIntegral(GG_ComponentType::Appearance);
}

void GG_MovementSystem(GG_EntityManager& entityManager)
{
    GG_TransformComponent* t;
    GG_PhysicsComponent*   p;

    for (auto entity = 0; entity < entityManager.Size; ++entity)
    {
        if ((entityManager.Enteties[entity] & MovementMask) != MovementMask)
        {
            continue;
        }

        t = &(entityManager.TransformComponents[entity]);
        p = &(entityManager.PhysicsComponents[entity]);

        /// @todo use actual deltatime
        t->Translation.x += p->Velocity.x * 0.16f;
        t->Translation.y += p->Velocity.y * 0.16f;
    }
}

void GG_RenderSystem(GG_EntityManager& entityManager)
{
    GG_TransformComponent*  t;
    GG_AppearanceComponent* a;

    for (unsigned int entity = 0; entity < entityManager.Size; ++entity)
    {
        if ((entityManager.Enteties[entity] & RenderMask) != RenderMask)
        {
            continue;
        }

        t = &(entityManager.TransformComponents[entity]);
        a = &(entityManager.AppearanceComponents[entity]);
    }
}
