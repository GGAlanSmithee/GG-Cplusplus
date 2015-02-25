#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <memory>
#include "Entity.h"

/// Applies movement to enteties identified by the movement mask
/// @author Alan Smithee
/// @date created 2014-11-25
/// @date changed 2015-02-25
/// @param entityManager entity manager to use movement system on
/// @param delta delta time (time since last update)
void GG_MovementSystem(GG_EntityManager&, const float);

/// Renders enteties identified by the render mask
/// @author Alan Smithee
/// @date created 2014-11-25
void GG_RenderSystem(GG_EntityManager const&);

#endif // SYSTEM_H_INCLUDED
