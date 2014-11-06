#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <vector>
#include <memory>
#include <bitset>
#include "GGCore/include/Export.h"
#include "GGCore/include/Core.h"
#include "GGComponent/include/Component.h"
#include "GGUtility/include/Utility.h"

namespace GGEntity
{
    EXPORT typedef struct World
    {
        World(const unsigned int size) :
            Size(size)
        {
            //Enteties.resize(Size, 0);
            Model.resize(Size, GGComponent::Model());
            Physics.resize(Size, GGComponent::Physics());
            Appearance.resize(Size, GGComponent::Appearance());
        }

        const unsigned int Size;
        std::bitset<GGCore::NumbComponentTypes> Enteties;

        std::vector<GGComponent::Model>      Model;
        std::vector<GGComponent::Physics>    Physics;
        std::vector<GGComponent::Appearance> Appearance;
    };
}

#endif // WORLD_H_INCLUDED
