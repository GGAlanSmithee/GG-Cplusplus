#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

    /// Enables an entity to have an observable appearance in the 3D world
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2015-01-11
    typedef struct Appearance
    {
        std::string Scene;
        std::string Shader;
    }
    Appearance;

    /// Enables an entity to display graphical contents to an output target
    /// @author Alan Smithee
    /// @date created 2014-12-21
    typedef struct Display
    {
        GLuint Target = static_cast<GLuint>(0);
        bool IsOrtho  = false;
    }
    Display;

    /// Enables an entity to focus at a target
    /// @author Alan Smithee
    /// @date created 2014-12-21
    typedef struct Focus
    {
        glm::mat4 Target = glm::mat4(1.0);
    }
    Focus;

    /// Enables an entity to move in, and interact with the 3D world
    /// @author Alan Smithee
    /// @date created 2014-11-19
    typedef struct Physics
    {
        glm::vec2 Velocity = glm::vec2(1.0f);
    }
    Physics;

    /// Enables an entity to have a point of view (to observe other enteties and objects)
    /// @author Alan Smithee
    /// @date created 2014-12-21
    typedef struct PointOfView
    {
        float FoV         = 45.0f;
        float AspectRatio = 800.0f / 600.0f;
        float Near        = 0.1f;
        float Far         = 200.0f;

        const glm::mat4 Get()
        {
            return glm::perspective(FoV, AspectRatio, Near, Far);
        }
    }
    PointOfView;

    /// Enables an entity to be placed and oriented in the 3D world
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
}

#endif // COMPONENT_H_INCLUDED
