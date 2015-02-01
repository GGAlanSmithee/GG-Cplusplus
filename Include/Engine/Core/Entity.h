#ifndef ENGINE_CORE_ENTITY_H_INCLUDED
#define ENGINE_CORE_ENTITY_H_INCLUDED

#include "World.h"
#include <memory>

namespace GGCoreEngine
{
    /// Creates an entity by assigning it a mask and returning its id
    /// @author Alan Smithee
    /// @date created 2014-11-25
    const unsigned int CreateEntity (World&);

    /// Destroys an entity by assigning it an empty mask (ComponentType::None)
    /// @author Alan Smithee
    /// @date created 2014-11-25
    void DestroyEntity(World&, const unsigned int);
}


#endif // ENGINE_CORE_ENTITY_H_INCLUDED
