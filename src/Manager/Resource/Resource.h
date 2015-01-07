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
    const bool ColladaModelWasImported();
    const bool GGModelWasImported();

    const std::vector<GGGraphics::Geometry> ImportColladaModel(const std::string&);
    const std::vector<GGGraphics::Geometry> ImportGGModel(const std::string&);
    void ExportGGModel(const std::vector<GGGraphics::Geometry>&, const std::string&);
}

#endif // RESOURCE_H_INCLUDED
