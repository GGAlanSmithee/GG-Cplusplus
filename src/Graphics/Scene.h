#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "Geometry.h"

namespace GGGraphics
{
    /// Contains information about a graphical scene
    /// @author Alan Smithee
    /// @date created 2015-01-09
    typedef struct Scene
    {
        /// Default constructor
        /// @author Alan Smithee
        /// @date created 2015-01-09
        Scene(const std::string& name = "") :
            Name(name)
        {
            // Empty
        }

        /// The name of the scene
        /// @author Alan Smithee
        /// @date created 2015-01-09
        std::string Name;

        /// The geometries of the scene
        /// @author Alan Smithee
        /// @date created 2015-01-09
        std::vector<Geometry> Geometries;

        /// The name of the texture of the scene
        /// @author Alan Smithee
        /// @date created 2015-01-09
        /// @date created 2015-01-11
        std::string Texture;
    }
    Scene;
}

#endif // SCENE_H_INCLUDED
