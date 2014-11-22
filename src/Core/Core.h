#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <glm/glm.hpp>

namespace GGCore
{
    const long long NumbComponentTypes = 1 << 4;

    /// @author Alan Smithee
    /// @date 2014-11-22
    /// Contains information about a vertex position, texture coordinates, normals etc
    typedef struct Vertex
    {
        Vertex(const glm::vec3& position, const glm::vec2& texture)
        {
            Position = position;
            Texture = texture;
        }

        glm::vec3 Position;
        glm::vec2 Texture;
    }
    Vertex;
}

#endif // CORE_H_INCLUDED
