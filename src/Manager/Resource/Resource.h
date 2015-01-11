#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <string>
#include "Graphics/Scene.h"
#include "Graphics/Shader.h"
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

    /// Loads all shaders from the current shader path
    /// @author Alan Smithee
    /// @date created 2015-01-11
    void LoadAllShaders();

    /// Gets a texture by its name
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @param texture the name of the texture to get
    /// @return the texture with the name that was passed in
    const GGGraphics::Texture GetTexture(const std::string&);

    /// Gets a scene by its name
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param scene the name of the scene to get
    /// @return the scene with the name that was passed in
    const GGGraphics::Scene GetScene(const std::string&);

    /// Gets a shader by its name
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param shader the name of the shader to get
    /// @return the shader with the name that was passed in
    const GGGraphics::Shader GetShader(const std::string&);

    /// Uses a shader
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param shader the shader to use
    void UseShader(GGGraphics::Shader&);

    /// Activates a texture on the shader
    /// @author Alan Smithee
    /// @date created 2014-11-22
    /// @date changed 2015-01-10
    /// @param texture the texture to activate
    void ActivateTexture(const std::string&);

    /// Sets the mvp uniform
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param shader the shader to set the uniform on
    /// @param mvp the new mvp uniform
    void SetMVPUniform(GGGraphics::Shader&, const glm::mat4&);
}

#endif // RESOURCE_H_INCLUDED
