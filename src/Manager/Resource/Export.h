#ifndef EXPORT_H_INCLUDED
#define EXPORT_H_INCLUDED

#include "Graphics/Scene.h"
namespace GGResourceManager
{
    /// Exports a gg model
    /// @author Alan Smithee
    /// @date created 2015-01-08
    /// @param scene the scene to export
    /// @param modelName the name to save the exported model as
    void ExportGGModel(const GGGraphics::Scene&, const std::string&);
}

#endif // EXPORT_H_INCLUDED
