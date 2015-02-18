#include <iostream>

#include "Entity.h"
#include "Application/Component.h"
#include "Utility/Utility.h"

GG_EntityManager::GG_EntityManager(const unsigned int size) :
    Size(size)
{
    Enteties.resize(Size, GG_Utility::ToIntegral(GG_ComponentType::None));

    AppearanceComponents.resize(Size, GG_AppearanceComponent());
    PhysicsComponents.resize(Size, GG_PhysicsComponent());
    TransformComponents.resize(Size, GG_TransformComponent());
}

const unsigned int GG_CreateEntity(GG_EntityManager& entityManager)
{
    for (auto i = 0; i < entityManager.Size; ++i)
    {
        if (entityManager.Enteties[i] == GG_Utility::ToIntegral(GG_ComponentType::None))
        {
            entityManager.Enteties[i] = GG_Utility::ToIntegral(GG_ComponentType::Transform)  |
                                GG_Utility::ToIntegral(GG_ComponentType::Physics) |
                                GG_Utility::ToIntegral(GG_ComponentType::Appearance);

            if (i > entityManager.maxEntityAlive)
            {
                entityManager.maxEntityAlive = i;
            }

            return i;
        }
    }

    std::cerr << "No more enteties left in entity manager." << std::endl;

    return entityManager.Size;
}

void GG_DestroyEntity(GG_EntityManager& entityManager, const unsigned int entity)
{
    if (entity > entityManager.Size)
    {
        return;
    }

    if (entity >= entityManager.maxEntityAlive)
    {
        for (auto i = entity; i >= 0; --i)
        {
            if (entityManager.Enteties[i] != GG_Utility::ToIntegral(GG_ComponentType::None))
            {
                entityManager.maxEntityAlive = i;
                break;
            }
        }
    }

    entityManager.Enteties[entity] = GG_Utility::ToIntegral(GG_ComponentType::None);
}


