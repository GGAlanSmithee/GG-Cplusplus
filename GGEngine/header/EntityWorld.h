#ifndef ENTITY_WORLD_H_INCLUDED
#define ENTITY_WORLD_H_INCLUDED

#include <bitset>
#include <memory>
#include <map>
#include "Component.h"
#include "Utility.h"

namespace GGEngine
{
    namespace Entity
    {
        const unsigned int WorldSize = 2000;

        typedef struct World
                       {
                           World()
                           {
                               for (auto entity : Enteties)
                               {
                                   entity = GGUtility::ToIntegral(Component::Type::None);
                               }
                           }

                           const unsigned int Size = WorldSize;

                           std::bitset<Component::NumbTypes> Enteties[WorldSize];

                           Component::Displacement Displacement[WorldSize];
                           Component::Velocity     Velocity[WorldSize];
                           Component::Appearance   Appearance[WorldSize];
                       }
                       World;
    }
}

#endif // ENTITY_WORLD_H_INCLUDED
