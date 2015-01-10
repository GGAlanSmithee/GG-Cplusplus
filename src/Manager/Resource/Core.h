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

    /// Returns the file ending of collada models
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @return the file ending
    const std::string& GetColladaFileEnding();

    /// Returns the file ending of gg models
    /// @author Alan Smithee
    /// @date created 2015-01-10
    /// @return the file ending
    const std::string& GetGGFileEnding();
}

#endif // CORE_H_INCLUDED
