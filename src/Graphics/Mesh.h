#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <vector>
#include "Vertex.h"

namespace GGGraphics
{
    /// Contains information about a graphical mesh
    /// @author Alan Smithee
    /// @date created 2014-12-21
    typedef struct Mesh
    {
        /// The vertices of the mesh
        /// @author Alan Smithee
        /// @date created 2014-12-21
        std::vector<Vertex> Vertices;

        /// The indices of the mesh
        /// @author Alan Smithee
        /// @date created 2014-12-21
        std::vector<unsigned int> Indices;
    }
    Mesh;
}

#endif // MESH_H_INCLUDED
