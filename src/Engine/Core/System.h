#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <memory>
#include "Engine/Core/Component.h"
#include "Engine/Core/Entity.h"

namespace GGCoreEngine
{
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
