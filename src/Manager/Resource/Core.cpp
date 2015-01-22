#include <dirent.h>
#include "Core.h"

namespace // Private variables and functions
{
    std::string ModelPath         = "C:/Projects/Creatio/Content/Model/";
    std::string TexturePath       = "C:/Projects/Creatio/Content/Gfx/";
    std::string ShaderPath        = "C:/Projects/Creatio/Content/Shader/";
    std::string ShaderSourcePath  = "C:/Projects/Creatio/Content/Shader/Source/";

    const std::string ColladaFileEnding        = ".dae";
    const std::string GGModelFileEnding        = ".ggmodel";
    const std::string GGShaderFileEnding       = ".ggshader";
    const std::string VertexShaderFileEnding   = ".vs";
    const std::string FragmentShaderFileEnding = ".fs";

    const std::string PhongShaderName = "phong";
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

    const std::string& GetShaderPath()
    {
        return ShaderPath;
    }

    void SetShaderPath(const std::string& shaderPath)
    {
        auto dir = opendir(shaderPath.c_str());

        if (dir != nullptr)
        {
            /// @todo: log error
            return;
        }

        ShaderPath = shaderPath;
    }

    const std::string& GetShaderSourcePath()
    {
        return ShaderSourcePath;
    }

    void SetShaderSourcePath(const std::string& shaderSourcePath)
    {
        auto dir = opendir(shaderSourcePath.c_str());

        if (dir != nullptr)
        {
            /// @todo: log error
            return;
        }

        ShaderSourcePath = shaderSourcePath;
    }

    const std::string& GetColladaFileEnding()
    {
        return ColladaFileEnding;
    }

    const std::string& GetGGModelFileEnding()
    {
        return GGModelFileEnding;
    }

    const std::string& GetGGShaderFileEnding()
    {
        return GGShaderFileEnding;
    }

    const std::string& GetVertexShaderFileEnding()
    {
        return VertexShaderFileEnding;
    }

    const std::string& GetFragmentShaderFileEnding()
    {
        return FragmentShaderFileEnding;
    }

    const std::string& GetPhongShaderName()
    {
        return PhongShaderName;
    }
}
