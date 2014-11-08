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
        World()
        {
            for (unsigned int i = 0; i < Size; ++i)
            {
                Enteties[i] = GGUtility::ToIntegral(GGComponent::Type::None);
            }
        }

        const static unsigned int Size = 2000;
        std::bitset<GGCore::NumbComponentTypes> Enteties[Size];

        GGComponent::Model      Model[Size];
        GGComponent::Physics    Physics[Size];
        GGComponent::Appearance Appearance[Size];
    };
}

#endif // WORLD_H_INCLUDED
