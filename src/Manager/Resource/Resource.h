#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "tinyxml2.h"
#include "Utility/Utility.h"
#include "Graphics/Vertex.h"
#include "Graphics/Mesh.h"
#include "Graphics/Geometry.h"

namespace GGResourceManager
{
    /// Indicates if a collada model was loaded
    /// @author Alan Smithee
    /// @date created 20154-01-08
    /// @return true if the model was loaded, false if not
    const bool ColladaModelWasImported();
    
    /// Indicates if a gg model was loaded
    /// @author Alan Smithee
    /// @date created 20154-01-08
    /// @return true if the model was loaded, false if not
    const bool GGModelWasImported();

    /// Imports a collada model
    /// @author Alan Smithee
    /// @date created 20154-01-08
    /// @param modelName the name of the model to import
    /// @return a vector of geometries
    const std::vector<GGGraphics::Geometry> ImportColladaModel(const std::string&);
    
    /// Imports a gg model
    /// @author Alan Smithee
    /// @date created 20154-01-08
    /// @param modelName the name of the model to import
    /// @return a vector of geometries
    const std::vector<GGGraphics::Geometry> ImportGGModel(const std::string&);
    
    /// Exports a gg model
    /// @author Alan Smithee
    /// @date created 20154-01-08
    /// @param geometries vector of geometries to export
    /// @param modelName the name to save the exported model as
    void ExportGGModel(const std::vector<GGGraphics::Geometry>&, const std::string&);
}

#endif // RESOURCE_H_INCLUDED
