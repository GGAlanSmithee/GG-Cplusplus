#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <string>
#include <glm/glm.hpp>
#include "Enum/Enum.h"

namespace GGCoreEngine
{
    /// Total number or types of components
    const long long NumbComponentTypes = 1 << 4;

    /// Enum representing the different component types
    /// @author Alan Smithee
    /// @date created 2014-11-19
    enum class ComponentType : int
    {
        None       = 0,
        Transform  = 1 << 0,
        Physics    = 1 << 1,
        Appearance = 1 << 2
    };

    /// Contains information of the appearance of an entity
    /// @author Alan Smithee
    /// @date created 2014-11-19
    typedef struct Appearance
    {
        GGEnum::Texture Texture;
    }
    Appearance;

    /// Contains information about the scale, rotation and translation of an entity
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2014-12-20
    typedef struct Transform
    {
        glm::mat4 Scale       = glm::mat4(1.0);
        glm::mat4 Rotation    = glm::mat4(1.0);
        glm::mat4 Translation = glm::mat4(1.0);

        glm::mat4 Get()
        {
            return Translation * Rotation * Scale;
        }
    }
    Transform;

    /// Contains information of the physical attributes of an entity
    /// @author Alan Smithee
    /// @date created 2014-11-19
    typedef struct Physics
    {
        glm::vec2 Velocity = glm::vec2(1.0f);
    }
    Physics;
}

#endif // COMPONENT_H_INCLUDED
