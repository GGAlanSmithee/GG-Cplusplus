#include "../header/EntityManager.h"

#include <iostream>
#include "Component.h"
#include "Utility.h"

namespace GGEngine
{
    namespace Entity
    {
        Manager::Manager()
        {
        }

        Manager::~Manager()
        {
        }

        const unsigned int Manager::CreateEntity(World& world)
        {
            for (auto i = 0; i < world.Size; ++i)
            {
                auto entity = world.Enteties[i];

                if (entity == GGUtility::ToIntegral(Component::Type::None))
                {
                    return i;
                }
            }

            std::cerr << "No more enteties left in world." << std::endl;

            return world.Size;
        }

        void Manager::DestroyEntity(World& world, const unsigned int entity)
        {
            world.Enteties[entity] = GGUtility::ToIntegral(Component::Type::None);
        }

        const unsigned int Manager::CreatePlayer(World&             world,
                                                 std::string const& id,
                                                 std::string const& path,
                                                 const float        x,
                                                 const float        y)
        {
            const unsigned int entity = CreateEntity(world);

            if (entity >= world.Size)
            {
                world.Size;
            }

            world.Enteties[entity] = GGUtility::ToIntegral(Component::Type::Displacement) |
                                     GGUtility::ToIntegral(Component::Type::Velocity)     |
                                     GGUtility::ToIntegral(Component::Type::Appearance);

            world.Velocity[entity].Value       = 0.0f;
            world.Displacement[entity].Value   = glm::vec4(glm::vec3(0.0), 1.0);
            world.Appearance[entity].TextureId = id;

            int width = 0;
            int height = 0;
//            SDL_QueryTexture(world.texture[id], nullptr, nullptr, &width, &height);

            world.Appearance[entity].ClippingRect = {0, 0, width, height };

            return entity;
        }
    }
}
