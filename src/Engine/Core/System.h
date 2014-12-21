#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <memory>
#include "Engine/Core/Component.h"
#include "Engine/Core/Entity.h"

namespace GGCoreEngine
{
    using Mask = std::bitset<NumbComponentTypes>;

    /// Identifies entities that can move
    /// @author Alan Smithee
    /// @date created 2014-11-25
    extern Mask MovementMask;

    /// Identifies entities that can be rendered
    /// @author Alan Smithee
    /// @date created 2014-11-25
    extern Mask RenderMask;

    /// Identifies entities that contains all components needed to allow them to act as a camera
    /// @author Alan Smithee
    /// @date created 2014-12-21
    extern Mask CameraMask;

    /// Controls enteties identified by the camera mask
    /// @author Alan Smithee
    /// @date created 2014-12-21
    void Camera(World&);

    /// Applies movement to enteties identified by the movement mask
    /// @author Alan Smithee
    /// @date created 2014-11-25
    void Movement(World&);

    /// Renders enteties identified by the render mask
    /// @author Alan Smithee
    /// @date created 2014-11-25
    void Render(World&);
}

#endif // SYSTEM_H_INCLUDED
