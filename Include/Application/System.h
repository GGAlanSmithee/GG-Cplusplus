#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <memory>
#include "Entity.h"

/// Applies movement to enteties identified by the movement mask
/// @author Alan Smithee
/// @date created 2014-11-25
void GG_MovementSystem(GG_EntityManager&);

/// Renders enteties identified by the render mask
/// @author Alan Smithee
/// @date created 2014-11-25
void GG_RenderSystem(GG_EntityManager&);

#endif // SYSTEM_H_INCLUDED
