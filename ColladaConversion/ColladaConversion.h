#ifndef COLLADACONVERSTION_H_INCLUDED
#define COLLADACONVERSTION_H_INCLUDED

#include <string>

#include "Graphics/Scene.h"

namespace GGColladaConversion
{
    /// Indicates if a collada model was loaded
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @return true if the model was loaded, false if not
    const bool ColladaModelWasImported();

    /// Imports a collada model
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @param modelName the name of the model to import
    /// @return a graphics scene
    const GGGraphics::Scene ImportColladaModel(const std::string&);

    /// Exports a gg model
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @param scene the scene to export
    /// @param modelName the name to save the exported model as
    void ExportGGModel(const GGGraphics::Scene&, const std::string&);
}

#endif // COLLADACONVERSTION_H_INCLUDED
