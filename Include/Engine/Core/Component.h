#ifndef ENGINE_CORE_COMPONENT_H_INCLUDED
#define ENGINE_CORE_COMPONENT_H_INCLUDED

#include <string>
#include "Math/Vec2.h"

namespace GGCoreEngine
{
    /// Total number or types of components
    const long long NumbComponentTypes = 1 << 6;

    /// Enum representing the different component types
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2014-12-21
    enum class ComponentType : int
    {
        None        = 0,
        Appearance  = 1 << 0,
        Display     = 1 << 1,
        Focus       = 1 << 2,
        Physics     = 1 << 3,
        PointOfView = 1 << 4,
        Transform   = 1 << 5
    };

    /// Enables an entity to have an observable appearance in the 2D world
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2015-02-01
    typedef struct Appearance
    {
        std::string Texture;
    }
    Appearance;

    /// Enables an entity to display graphical contents to an output target
    /// @author Alan Smithee
    /// @date created 2014-12-21
    typedef struct Display
    {
        SDL_Rect Viewport;
    }
    Display;

    /// Enables an entity to focus at a target
    /// @author Alan Smithee
    /// @date created 2014-12-21
    /// @date changed 2015-02-01
    typedef struct Focus
    {
        GGMath::Vec2 Target = GGMath::Vec2(0.0f);
    }
    Focus;

    /// Enables an entity to move in, and interact with the 2D world
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2015-02-01
    typedef struct Physics
    {
        float Velocity = 2.0f;
    }
    Physics;

    /// Enables an entity to have a point of view (to observe other enteties and objects)
    /// @author Alan Smithee
    /// @date created 2014-12-21
    /// @date created 2015-02-01
    typedef struct PointOfView
    {
        float Width = 800;
        float Height = 600;
    }
    PointOfView;

    /// Enables an entity to be placed, scaled and oriented in the 2D world
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2015-02-01
    typedef struct Transform
    {
        float Scale              = 1.0f;
        float Rotation           = 0.0f;
        GGMath::Vec2 Translation = GGMath::Vec2(1.0f);
    }
    Transform;
}

#endif // ENGINE_CORE_COMPONENT_H_INCLUDED
