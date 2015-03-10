#ifndef APPLICATION_COMPONENT_H_INCLUDED
#define APPLICATION_COMPONENT_H_INCLUDED

#include <string>
#include "Math/Vec2.h"
#include "Math/Rect.h"

/// Enum representing the different component types
/// @author Alan Smithee
/// @date created 2014-11-19
/// @date changed 2015-02-17
enum GG_ComponentType
{
    None        = 0,
    Appearance  = 1 << 0,
    Physics     = 1 << 1,
    Transform   = 1 << 2,
    Total       = 1 << 3
};

/// Enables an entity to have an observable appearance in the 2D world
/// @author Alan Smithee
/// @date created 2014-11-19
/// @date changed 2015-02-17
typedef struct GG_AppearanceComponent
{
    int textureId;
}
GG_AppearanceComponent;

/// Enables an entity to move in, and interact with the 2D world
/// @author Alan Smithee
/// @date created 2014-11-19
/// @date changed 2015-02-17
typedef struct GG_PhysicsComponent
{
    GG_Vec2f Velocity;
    GG_Rect Hitbox;
}
GG_PhysicsComponent;

/// Enables an entity to be placed and oriented in the 2D world
/// @author Alan Smithee
/// @date created 2014-11-19
/// @date changed 2015-02-17
typedef struct GG_TransformComponent
{
    GG_Vec2f Scale;
    GG_Vec2f Rotation;
    GG_Vec2f Translation;
}
GG_TransformComponent;

#endif // APPLICATION_COMPONENT_H_INCLUDED
