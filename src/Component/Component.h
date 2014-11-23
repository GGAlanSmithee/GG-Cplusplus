#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <string>
#include <glm/glm.hpp>
#include "Enum/Enum.h"

namespace GGComponent
{
    /// @author Alan Smithee
    /// @date 2014-11-19
    /// @date last updated 2014-11-23
    /// Enum representing the different component types
    enum class Type : int
    {
        None        = 0,
        Orientation = 1 << 0,
        Physics     = 1 << 1,
        Appearance  = 1 << 2
    };

    /// @author Alan Smithee
    /// @date 2014-11-19
    /// Contains information of the appearance of any entity using this component
    typedef struct Appearance
    {
        GGEnum::Texture Texture;
    }
    Appearance;

    /// @author Alan Smithee
    /// @date 2014-11-19
    /// @date last updated 2014-11-23
    /// Contains information about the orientation of an entity
    typedef struct Orientation
    {
        glm::mat4 Scale       = glm::mat4(1.0);
        glm::mat4 Rotation    = glm::mat4(1.0);
        glm::mat4 Translation = glm::mat4(1.0);

        glm::mat4 Get()
        {
            return Translation * Rotation * Scale;
        }
    }
    Model;

    /// @author Alan Smithee
    /// @date 2014-11-19
    /// Contains information of the physical attributes of any entity using this component
    typedef struct Physics
    {
        glm::vec2 Velocity = glm::vec2(1.0f);
    }
    Physics;
}

#endif // COMPONENT_H_INCLUDED
