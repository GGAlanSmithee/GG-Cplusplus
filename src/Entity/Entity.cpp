#include <iostream>
#include "Entity.h"
#include "Component/Component.h"
#include "Utility/Utility.h"

namespace GGEntity
{
    const unsigned int CreateEntity(World& world)
    {
        for (auto i = 0; i < world.Size; ++i)
        {
            if (world.Enteties[i] == GGUtility::ToIntegral(GGComponent::Type::None))
            {
                world.Enteties[i] = GGUtility::ToIntegral(GGComponent::Type::Model)  |
                                    GGUtility::ToIntegral(GGComponent::Type::Physics) |
                                    GGUtility::ToIntegral(GGComponent::Type::Appearance);

//                world.Model[i].Scale       = glm::mat4(1.0);
//                world.Model[i].Rotation    = glm::mat4(1.0);
//                world.Model[i].Translation = glm::mat4(1.0);
//
//                world.Physics[i].Velocity = glm::vec2(1.0f);

                return i;
            }
        }

        std::cerr << "No more enteties left in world." << std::endl;

        return world.Size;
    }

    void DestroyEntity(World& world, const unsigned int entity)
    {
        world.Enteties[entity] = GGUtility::ToIntegral(GGComponent::Type::None);
    }
////
////        const unsigned int Manager::CreatePlayer(World&             world,
////                                                 std::string const& id,
////                                                 std::string const& path,
////                                                 const float        x,
////                                                 const float        y)
////        {
////            const unsigned int entity = CreateEntity(world);
////
////            if (entity >= world.Size)
////            {
////                world.Size;
////            }
////
////            world.Enteties[entity] = GGUtility::ToIntegral(Component::Type::Model) |
////                                     GGUtility::ToIntegral(Component::Type::Physics)     |
////                                     GGUtility::ToIntegral(Component::Type::Appearance);
////
////            world.Model[entity].Value       = 0.0f;
////            world.Physics[entity].Value   = glm::vec4(glm::vec3(0.0), 1.0);
////            world.Appearance[entity].TextureId = id;
////
////            int width = 0;
////            int height = 0;
////             SDL_QueryTexture(world.texture[id], nullptr, nullptr, &width, &height);
////
////            return entity;
////        }
}

