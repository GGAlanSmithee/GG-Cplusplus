#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <string>

namespace GGResourceManager
{
    /// Returns the active model path
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @return the model path
    const std::string& GetModelPath();

    /// Sets the active model path
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @param modelPath the new model path
    /// @remark the path should be absolute and use forward slashes
    void SetModelPath(const std::string&);

    /// Returns the active texture path
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @return the texture path
    const std::string& GetTexturePath();

    /// Sets the active texture path
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @param texturePath the new texture path
    /// @remark the path should be absolute and use forward slashes
    void SetTexturePath(const std::string&);

    /// Returns the active shader path
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @return the shader path
    const std::string& GetShaderPath();

    /// Sets the active shader path
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param shaderPath the new shader path
    /// @remark the path should be absolute and use forward slashes
    void SetShaderPath(const std::string&);

    /// Returns the active shader source path
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @return the shader source path
    const std::string& GetShaderSourcePath();

    /// Sets the active shader source path
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param shaderSourcePath the new shader source path
    /// @remark the path should be absolute and use forward slashes
    void SetShaderSourcePath(const std::string&);

    /// Returns the file ending of collada models
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @return the file ending
    const std::string& GetColladaFileEnding();

    /// Returns the file ending of gg models
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @return the file ending
    const std::string& GetGGModelFileEnding();

    /// Returns the file ending of gg shaders
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @return the file ending
    const std::string& GetGGShaderFileEnding();

    /// Returns the file ending of vertex shaders
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @return the file ending
    const std::string& GetVertexShaderFileEnding();

    /// Returns the file ending of fragment shaders
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @return the file ending
    const std::string& GetFragmentShaderFileEnding();

    /// Returns the name of the phong shader
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @return the name of the shader
    const std::string& GetPhongShaderName();
}

#endif // CORE_H_INCLUDED
