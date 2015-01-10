#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

#include <vector>
#include <string>
#include "Mesh.h"

namespace GGGraphics
{
    /// Contains information about a graphical geometry
    /// @author Alan Smithee
    /// @date created 2014-12-21
    typedef struct Geometry
    {
        /// Default constructor
        /// @author Alan Smithee
        /// @date created 2015-01-04
        Geometry(const std::string& name) :
            Name(name)
        {
            // Empty
        }

        /// The name of the geometry
        /// @author Alan Smithee
        /// @date created 2015-01-04
        std::string Name;

        /// The meshes of the geometry
        /// @author Alan Smithee
        /// @date created 2015-01-04
        std::vector<Mesh> Meshes;
    }
    Geometry;
}

#endif // GEOMETRY_H_INCLUDED
