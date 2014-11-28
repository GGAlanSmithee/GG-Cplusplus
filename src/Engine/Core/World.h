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
    /// @remarks The world is made up of a list of enteties and lits of the different components available
    typedef struct World
    {
        /// Initializes a world object
        /// @author Alan Smithee
        /// @date created 2014-11-28
        /// @param size the inital size of the world
        World(const unsigned int size) :
            Size(size)
        {
            Enteties.resize(Size, GGUtility::ToIntegral(ComponentType::None));
            OrientationComponents.resize(Size, Orientation());
            PhysicsComponents.resize(Size, Physics());
            AppearanceComponents.resize(Size, Appearance());
        }

        /// Worldsize
        /// @author Alan Smithee
        /// @date created 2014-11-28
        unsigned int Size;
        
        /// List of enteties
        /// @author Alan Smithee
        /// @date created 2014-11-28
        /// @remarks an entity is idetified with a mask that specifies what components the entety is made up of
        std::vector<std::bitset<NumbComponentTypes>> Enteties;

        /// List of orientation components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<Orientation> OrientationComponents;
        
        /// List of physics components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<Physics> PhysicsComponents;
        
        /// List of appearance components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<Appearance> AppearanceComponents;
    }
    World;
}

#endif // WORLD_H_INCLUDED
