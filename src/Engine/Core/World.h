#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <vector>
#include <memory>
#include <bitset>
#include "Engine/Core/Component.h"
#include "Utility/Utility.h"
#include "Enum/Enum.h"

namespace GGCoreEngine
{
    /// Represents and identifies all current enteties in a game
    /// @author Alan Smithee
    /// @date created 2014-11-25
    typedef struct World
    {
        World(const unsigned int size) :
            Size(size)
        {
            Enteties.resize(Size, GGUtility::ToIntegral(ComponentType::None));
            OrientationComponents.resize(Size, Orientation());
            PhysicsComponents.resize(Size, Physics());
            AppearanceComponents.resize(Size, Appearance());
        }

        unsigned int Size;
        std::vector<std::bitset<NumbComponentTypes>> Enteties;

        std::vector<Orientation> OrientationComponents;
        std::vector<Physics>     PhysicsComponents;
        std::vector<Appearance>  AppearanceComponents;
    }
    World;
}

#endif // WORLD_H_INCLUDED
