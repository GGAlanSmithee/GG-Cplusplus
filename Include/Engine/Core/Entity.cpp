#include <iostream>

#include "Entity.h"
#include "Engine/Core/Component.h"
#include "Utility/Utility.h"

namespace GGCoreEngine
{
    const unsigned int CreateEntity(GG_World& world)
    {
        for (auto i = 0; i < world.Size; ++i)
        {
            if (world.Enteties[i] == GGUtility::ToIntegral(ComponentType::None))
            {
                world.Enteties[i] = GGUtility::ToIntegral(ComponentType::Transform) |
                                    GGUtility::ToIntegral(ComponentType::Physics)   |
                                    GGUtility::ToIntegral(ComponentType::Appearance);

                world.AppearanceComponents[i].Texture = "helloword";

                return i;
            }
        }

        std::cerr << "No more enteties left in world." << std::endl;

        return world.Size;
    }

    void DestroyEntity(GG_World& world, const unsigned int entity)
    {
        world.Enteties[entity] = GGUtility::ToIntegral(ComponentType::None);
    }
}

