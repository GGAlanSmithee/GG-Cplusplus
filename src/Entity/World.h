#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <vector>
#include <memory>
#include <bitset>
#include "Core/Core.h"
#include "Component/Component.h"
#include "Utility/Utility.h"

namespace GGEntity
{
    typedef struct World
    {
        World(const unsigned int size) :
            Size(size)
        {
            Enteties.resize(Size, GGUtility::ToIntegral(GGComponent::Type::None));
            Orientation.resize(Size, GGComponent::Orientation());
            Physics.resize(Size, GGComponent::Physics());
            Appearance.resize(Size, GGComponent::Appearance());
        }

        unsigned int Size;
        std::vector<std::bitset<GGCore::NumbComponentTypes>> Enteties;

        std::vector<GGComponent::Orientation> Orientation;
        std::vector<GGComponent::Physics>     Physics;
        std::vector<GGComponent::Appearance>  Appearance;
    };
}

#endif // WORLD_H_INCLUDED
