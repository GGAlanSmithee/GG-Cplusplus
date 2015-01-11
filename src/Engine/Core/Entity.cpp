#include <iostream>

#include "Entity.h"
#include "Engine/Core/Component.h"
#include "Utility/Utility.h"
#include "Enum/Enum.h"
#include "Manager/Resource/Resource.h"

namespace GGCoreEngine
{
    const unsigned int CreateEntity(World& world)
    {
        for (auto i = 0; i < world.Size; ++i)
        {
            if (world.Enteties[i] == GGUtility::ToIntegral(ComponentType::None))
            {
                world.Enteties[i] = GGUtility::ToIntegral(ComponentType::Transform)  |
                                    GGUtility::ToIntegral(ComponentType::Physics) |
                                    GGUtility::ToIntegral(ComponentType::Appearance);

                world.AppearanceComponents[i].Scene = "test";
                world.AppearanceComponents[i].Shader = "phong";

                return i;
            }
        }

        std::cerr << "No more enteties left in world." << std::endl;

        return world.Size;
    }

    void DestroyEntity(World& world, const unsigned int entity)
    {
        world.Enteties[entity] = GGUtility::ToIntegral(ComponentType::None);
    }
}

