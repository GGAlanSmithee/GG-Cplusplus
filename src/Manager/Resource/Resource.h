#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <string>
#include "Graphics/Texture.h"

namespace GGResourceManager
{
    /// Loads all models from the current model path
    /// @author Alan Smithee
    /// @date created 2015-01-09
    void LoadAllModels();

    /// Loads all textures from the current texture path
    /// @author Alan Smithee
    /// @date created 2015-01-09
    void LoadAllTextures();

    /// Gets a texture by its name
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @param texture the name of the texture to get
    /// @return the texture with the name passed in
    const GGGraphics::Texture GetTexture(const std::string&);
}

#endif // RESOURCE_H_INCLUDED
