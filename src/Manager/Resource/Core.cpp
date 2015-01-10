#include <dirent.h>
#include "Core.h"

namespace // Private variables and functions
{
    std::string ModelPath   = "C:/Projects/Creatio/Model/";
    std::string TexturePath = "C:/Projects/Creatio/Gfx/";

    const std::string ColladaFileEnding = ".dae";
    const std::string GGFileEnding      = ".gg";
}

namespace GGResourceManager
{
    const std::string& GetModelPath()
    {
        return ModelPath;
    }

    void SetModelPath(const std::string& modelPath)
    {
        auto dir = opendir(modelPath.c_str());

        if (dir != nullptr)
        {
            /// @todo: log error
            return;
        }

        ModelPath = modelPath;
    }

    const std::string& GetTexturePath()
    {
        return TexturePath;
    }

    void SetTexturePath(const std::string& texturePath)
    {
        auto dir = opendir(texturePath.c_str());

        if (dir != nullptr)
        {
            /// @todo: log error
            return;
        }

        TexturePath = texturePath;
    }

    const std::string& GetColladaFileEnding()
    {
        return ColladaFileEnding;
    }

    const std::string& GetGGFileEnding()
    {
        return GGFileEnding;
    }
}
