#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <glm/glm.hpp>

namespace GGRendererEngine
{
    /// Contains information about a vertex position, texture coordinates, normals etc
    /// @author Alan Smithee
    /// @date created 2014-11-22
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

#endif // VERTEX_H_INCLUDED
