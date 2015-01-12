#include <iostream>
#include <fstream>
#include <map>
#include <tinyxml2.h>

#include "Core.h"
#include "Import.h"
#include "Manager/Logging/Logging.h"
#include "Utility/Utility.h"

namespace // Private variables and functions
{
    bool ggModelWasImported      = false;
    bool ggShaderWasImported     = false;
    bool shaderWasCreated        = false;
    bool uniformsWereBound       = false;

    /// @todo refactor this to GGResourceManager Core
    tinyxml2::XMLElement* Child(tinyxml2::XMLElement* el, const std::string& name)
    {
        return el->FirstChildElement(name.c_str());
    }

    /// @todo refactor this to GGResourceManager Core
    tinyxml2::XMLElement* SameSibling(tinyxml2::XMLElement* el)
    {
        return el->NextSiblingElement(el->Name());
    }

    const std::string GetShaderSource(const std::string& name)
    {
        auto completeName = GGResourceManager::GetShaderSourcePath() + name;

        std::ifstream stream(completeName.c_str());
        std::string file;

        if (!stream.is_open())
        {
            GGLoggingManager::LogError("Could not open file with path ", GGResourceManager::GetShaderSourcePath() + name);
            return "";
        }

        std::string line;

        while (getline(stream, line))
        {
            file.append(line);
            file.append("\n");
        }

        stream.close();

        return file;
    }

    const GLuint CompileShader(const GLenum type, const std::string& fileName)
    {
        auto shader = glCreateShader(type);

        if (shader == 0)
        {
            GGLoggingManager::LogError("Could not create shader of type ", type);
            return shader;
        }

        auto shaderSource = GetShaderSource(fileName);

        if (shaderSource == "")
        {
            GGLoggingManager::LogError("Could not read shader source for shader with name ", fileName);
            return static_cast<GLuint>(-1);
        }

        auto source = (const GLchar*)shaderSource.c_str();
        glShaderSource(shader, 1, &source, 0);

        glCompileShader(shader);

        GLint isCompiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

        if (isCompiled == GL_FALSE)
        {
            GGLoggingManager::LogError("Could not compile vertex shader: ", GGLoggingManager::GetShaderInfoLog(shader));
            glDeleteShader(shader);
            return 0;
        }

        return shader;
    }

    void CreatePhongShader(GGGraphics::Shader& shader,
                           const std::string& vertexShaderName,
                           const std::string& fragmentShaderName)
    {
        shaderWasCreated = false;

        auto vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderName);

        if (vertexShader <= 0)
        {
            return;
        }

        auto fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderName);

        if (fragmentShader <= 0)
        {
            glDeleteShader(vertexShader);

            return;
        }

        shader.Program = glCreateProgram();

        glAttachShader(shader.Program, vertexShader);
        glAttachShader(shader.Program, fragmentShader);

        glLinkProgram(shader.Program);

        GLint isLinked = 0;
        glGetProgramiv(shader.Program, GL_LINK_STATUS, (int*)&isLinked);

        if (isLinked == GL_FALSE)
        {
            GGLoggingManager::LogError("Could not link program: ", GGLoggingManager::GetProgramInfoLog(shader.Program));

            glDeleteProgram(shader.Program);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            return;
        }

        glDetachShader(shader.Program, vertexShader);
        glDetachShader(shader.Program, fragmentShader);

        glValidateProgram(shader.Program);

        GLint isValid = 0;
        glGetProgramiv(shader.Program, GL_VALIDATE_STATUS, &isValid);

        if (isValid == GL_FALSE)
        {
            GGLoggingManager::LogError("Program is not valid: ", GGLoggingManager::GetProgramInfoLog(shader.Program));

            glDeleteProgram(shader.Program);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            return;
        }

        shaderWasCreated = true;

        glUseProgram(shader.Program);
    }

    void BindUniforms(GGGraphics::Shader& shader)
    {
        uniformsWereBound = false;

        auto mvpUniform = glGetUniformLocation(shader.Program, "MVP");

        if (mvpUniform == 0xFFFFFFFF)
        {
            GGLoggingManager::LogError("Unable to set MVP uniform.");
            return;
        }

        shader.Uniforms[GGEnum::Uniform::MVP] = mvpUniform;

        auto textureSamplerUniform = glGetUniformLocation(shader.Program, "TextureSampler");

        if (textureSamplerUniform == 0xFFFFFFFF)
        {
            GGLoggingManager::LogError("Unable to set TextureSampler uniform.");
            return;
        }

        shader.Uniforms[GGEnum::Uniform::TextureSampler] = textureSamplerUniform;

        uniformsWereBound = true;
    }
}

namespace GGResourceManager
{
    const bool GGModelWasImported()
    {
        return ggModelWasImported;
    }

    const bool GGShaderWasImported()
    {
        return ggShaderWasImported;
    }

    const GGGraphics::Scene ImportGGModel(const std::string& modelName)
    {
        ggModelWasImported = false;

        GGGraphics::Scene scene;

        std::string completeModelName = GetModelPath() + modelName;

        tinyxml2::XMLDocument ggDoc;
        auto loadingResult = ggDoc.LoadFile(completeModelName.c_str());

        if (loadingResult != tinyxml2::XML_SUCCESS)
        {
            std::cerr << "Could not load model" << std::endl;

            return scene;
        }

        for (auto geometries = ggDoc.FirstChildElement("geometries"); geometries != nullptr; geometries = SameSibling(geometries))
        {
            for (auto geoNode = Child(geometries, "geometry"); geoNode != nullptr; geoNode = SameSibling(geoNode))
            {
                GGGraphics::Geometry geometry("test");

                for (auto meshNode = Child(geoNode, "mesh"); meshNode != nullptr; meshNode = SameSibling(meshNode))
                {
                    GGGraphics::Mesh mesh;

                    auto indices = GGUtility::ToInts(Child(meshNode, "indices")->GetText());

                    for (auto index : indices)
                    {
                        mesh.Indices.push_back(static_cast<unsigned int>(index));
                    }

                    for (auto vertNode = Child(meshNode, "vertex"); vertNode != nullptr; vertNode = SameSibling(vertNode))
                    {
                        auto positionData = GGUtility::ToInts(Child(vertNode, "position")->GetText());
                        auto normalData = GGUtility::ToInts(Child(vertNode, "normal")->GetText());
                        auto texCoordData = GGUtility::ToInts(Child(vertNode, "texcoord")->GetText());

                        glm::vec3 position;
                        glm::vec3 normal;
                        glm::vec2 texCoord;

                        if (positionData.size() == 3)
                        {
                            position = glm::vec3(positionData[0], positionData[1], positionData[2]);
                        }

                        if (normalData.size() == 3)
                        {
                            normal = glm::vec3(normalData[0], normalData[1], normalData[2]);
                        }

                        if (texCoordData.size() == 2)
                        {
                            texCoord = glm::vec2(texCoordData[0], texCoordData[1]);
                        }

                        mesh.Vertices.push_back(GGGraphics::Vertex(position, normal, texCoord));
                    }

                    geometry.Meshes.push_back(mesh);
                }

                scene.Geometries.push_back(geometry);
            }
        }

        scene.Texture = "crate";

        ggModelWasImported = true;

        return scene;
    }

    const GGGraphics::Shader ImportGGShader(const std::string& shaderName)
    {
        ggShaderWasImported = false;

        GGGraphics::Shader shader;

        std::string completeShaderName = GetShaderPath() + shaderName;

        tinyxml2::XMLDocument ggShaderDoc;
        auto loadingResult = ggShaderDoc.LoadFile(completeShaderName.c_str());

        if (loadingResult != tinyxml2::XML_SUCCESS)
        {
            GGLoggingManager::LogError("Could not load shader.");

            return shader;
        }

        auto shaderNode = ggShaderDoc.FirstChildElement("shader");

        if (shaderNode == nullptr)
        {
            GGLoggingManager::LogError("Shader is formatted in the wrong way.");

            return shader;
        }

        shader.Name = shaderNode->Attribute("name");

        if (shader.Name.compare(GetPhongShaderName()) == 0)
        {
            auto vertexShaderName = Child(shaderNode, "vertex")->Attribute("name") + GetVertexShaderFileEnding();
            auto fragmentShaderName = Child(shaderNode, "fragment")->Attribute("name") + GetFragmentShaderFileEnding();

            CreatePhongShader(shader, vertexShaderName, fragmentShaderName);

            if (!shaderWasCreated)
            {
                return shader;
            }

            BindUniforms(shader);

            if (!uniformsWereBound)
            {
                return shader;
            }
        }

        ggShaderWasImported = true;

        return shader;
    }
}
