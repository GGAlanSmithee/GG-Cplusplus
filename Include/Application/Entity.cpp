#include <iostream>

#include "Entity.h"
#include "Application/Component.h"

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

const unsigned int GG_CreateCamera(GG_EntityManager& entityManager)
{
    auto entity = GG_CreateEntity(entityManager);

    if (entity < entityManager.Size)
    {
        entityManager.Enteties[entity] = GG_Utility::ToIntegral(GG_ComponentType::Transform) |
                                         GG_Utility::ToIntegral(GG_ComponentType::Physics);

        entityManager.TransformComponents[entity].Translation.x = 15.0f;
        entityManager.TransformComponents[entity].Translation.y = 15.0f;

        entityManager.PhysicsComponents[entity].Velocity.x = 0.0f;
        entityManager.PhysicsComponents[entity].Velocity.y = 0.0f;

        entityManager.PhysicsComponents[entity].Hitbox.x = 0.0f;
        entityManager.PhysicsComponents[entity].Hitbox.y = 0.0f;

        /// @todo set width and height from actual window size
        entityManager.PhysicsComponents[entity].Hitbox.w = 20.0f;
        entityManager.PhysicsComponents[entity].Hitbox.h = 15.0f;
    }

    return entity;
}
