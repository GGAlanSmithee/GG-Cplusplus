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
    /// @date changed 2014-12-21
    /// @remarks The world is made up of a list of enteties and lits of the different components available
    typedef struct World
    {
        /// Initializes a world object
        /// @author Alan Smithee
        /// @date created 2014-11-28
        /// @date changed 2014-12-21
        /// @param size the inital size of the world
        World(const unsigned int size) :
            Size(size)
        {
            Enteties.resize(Size, GGUtility::ToIntegral(ComponentType::None));

            AppearanceComponents.resize(Size, Appearance());
            DisplayComponents.resize(Size, Display());
            FocusComponents.resize(Size, Focus());
            PhysicsComponents.resize(Size, Physics());
            PointOfViewComponents.resize(Size, PointOfView());
            TransformComponents.resize(Size, Transform());
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

        /// List of appearance components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<Appearance> AppearanceComponents;

        /// List of display components
        /// @author Alan Smithee
        /// @date created 2014-12-21
        std::vector<Display> DisplayComponents;

        /// List of focus components
        /// @author Alan Smithee
        /// @date created 2014-12-21
        std::vector<Focus> FocusComponents;

        /// List of physics components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<Physics> PhysicsComponents;

        /// List of point of view components
        /// @author Alan Smithee
        /// @date created 2014-12-21
        std::vector<PointOfView> PointOfViewComponents;

        /// List of transform components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<Transform> TransformComponents;
    }
    World;
}

#endif // WORLD_H_INCLUDED
