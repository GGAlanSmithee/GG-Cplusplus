#ifndef IMPORT_H_INCLUDED
#define IMPORT_H_INCLUDED

#include "Graphics/Scene.h"

namespace GGResourceManager
{
    /// Indicates if a collada model was loaded
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @return true if the model was loaded, false if not
    const bool ColladaModelWasImported();

    /// Indicates if a gg model was loaded
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @return true if the model was loaded, false if not
    const bool GGModelWasImported();

    /// Imports a collada model
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @param modelName the name of the model to import
    /// @return a graphics scene
    const GGGraphics::Scene ImportColladaModel(const std::string&);

    /// Imports a gg model
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @param modelName the name of the model to import
    /// @return a graphics scene
    const GGGraphics::Scene ImportGGModel(const std::string&);
}

#endif // IMPORT_H_INCLUDED
