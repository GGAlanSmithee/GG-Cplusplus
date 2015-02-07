#ifndef ENGINE_CORE_WORLD_H_INCLUDED
#define ENGINE_CORE_WORLD_H_INCLUDED

#include <vector>
#include <memory>
#include <bitset>
#include "Engine/Core/Component.h"
#include "Utility/Utility.h"


/// Represents and identifies all current enteties in a game
/// @author Alan Smithee
/// @date created 2014-11-25
/// @date changed 2015-02-07
/// @remarks The world is made up of a list of enteties and lits of the different components available
typedef struct GG_World
{
    /// Initializes a world object
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @date changed 2015-02-07
    /// @param size the inital size of the world
    GG_World(const unsigned int size) :
        Size(size)
    {
        Enteties.resize(Size, GGUtility::ToIntegral(GGCoreEngine::ComponentType::None));

        AppearanceComponents.resize(Size, GGCoreEngine::Appearance());
        DisplayComponents.resize(Size, GGCoreEngine::Display());
        FocusComponents.resize(Size, GGCoreEngine::Focus());
        PhysicsComponents.resize(Size, GGCoreEngine::Physics());
        PointOfViewComponents.resize(Size, GGCoreEngine::PointOfView());
        TransformComponents.resize(Size, GGCoreEngine::Transform());
    }

    /// Worldsize
    /// @author Alan Smithee
    /// @date created 2014-11-28
    unsigned int Size;

    /// List of enteties
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @remarks an entity is idetified with a mask that specifies what components the entety is made up of
    std::vector<std::bitset<GGCoreEngine::NumbComponentTypes>> Enteties;

    /// List of appearance components
    /// @author Alan Smithee
    /// @date created 2014-11-28
    std::vector<GGCoreEngine::Appearance> AppearanceComponents;

    /// List of display components
    /// @author Alan Smithee
    /// @date created 2014-12-21
    std::vector<GGCoreEngine::Display> DisplayComponents;

    /// List of focus components
    /// @author Alan Smithee
    /// @date created 2014-12-21
    std::vector<GGCoreEngine::Focus> FocusComponents;

    /// List of physics components
    /// @author Alan Smithee
    /// @date created 2014-11-28
    std::vector<GGCoreEngine::Physics> PhysicsComponents;

    /// List of point of view components
    /// @author Alan Smithee
    /// @date created 2014-12-21
    std::vector<GGCoreEngine::PointOfView> PointOfViewComponents;

    /// List of transform components
    /// @author Alan Smithee
    /// @date created 2014-11-28
    std::vector<GGCoreEngine::Transform> TransformComponents;
}
GG_World;

#endif // ENGINE_CORE_WORLD_H_INCLUDED
