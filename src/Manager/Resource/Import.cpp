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
    bool colladaModelWasImported = false;
    bool ggModelWasImported      = false;
    bool ggShaderWasImported     = false;
    bool shaderWasCreated        = false;
    bool uniformsWereBound       = false;

    enum class SourceType
    {
        Position,
        Normal,
        Texcoord
    };

    std::map<std::string, SourceType> Sources
                                      {
                                          {"VERTEX", SourceType::Position},
                                          {"NORMAL", SourceType::Normal},
                                          {"TEXCOORD", SourceType::Texcoord},
                                      };

    typedef struct Source
    {
        int TotalCount = 0;
        int Stride     = 0;
        std::vector<float> Values;
    }
    Source;

    tinyxml2::XMLElement* Child(tinyxml2::XMLElement* el, const std::string& name)
    {
        return el->FirstChildElement(name.c_str());
    }

    tinyxml2::XMLElement* SameSibling(tinyxml2::XMLElement* el)
    {
        return el->NextSiblingElement(el->Name());
    }

    const std::map<SourceType, Source> GetAllSources(tinyxml2::XMLElement* meshNode, tinyxml2::XMLElement* polyNode)
    {
        std::map<SourceType, Source> sources;

        for (auto input = Child(polyNode, "input"); input != nullptr; input = SameSibling(input))
        {
            auto sourceName = std::string(input->Attribute("source"));
            sourceName = sourceName.substr(1);

            SourceType sourceType = Sources[input->Attribute("semantic")];

            if (sourceType == SourceType::Position)
            {
                sourceName = sourceName.substr(0, sourceName.find("vertices")) + "positions";
            }

            Source source;

            for (auto srcNode = Child(meshNode, "source"); srcNode != nullptr; srcNode = SameSibling(srcNode))
            {
                if (std::string(srcNode->Attribute("id")).compare(sourceName) == 0)
                {
                    source.TotalCount = std::stoi(srcNode->FirstChildElement("float_array")
                                                         ->Attribute("count"));

                    source.Stride = std::stoi(srcNode->FirstChildElement("technique_common")
                                                     ->FirstChildElement("accessor")
                                                     ->Attribute("stride"));

                    source.Values = GGUtility::ToFloats(srcNode->FirstChildElement("float_array")->GetText());
                }
            }

            sources[sourceType] = source;
        }

        return sources;
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

        //SetUniformMatrix4f(GGEnum::Uniform::MVP, glm::mat4(1.0));

        auto textureSamplerUniform = glGetUniformLocation(shader.Program, "TextureSampler");

        if (textureSamplerUniform == 0xFFFFFFFF)
        {
            GGLoggingManager::LogError("Unable to set TextureSampler uniform.");
            return;
        }

        shader.Uniforms[GGEnum::Uniform::TextureSampler] = textureSamplerUniform;

        //SetUniform1i(GGEnum::Uniform::TextureSampler, 0);

        uniformsWereBound = true;
    }
}

namespace GGResourceManager
{
    const bool ColladaModelWasImported()
    {
        return colladaModelWasImported;
    }

    const bool GGModelWasImported()
    {
        return ggModelWasImported;
    }

    const bool GGShaderWasImported()
    {
        return ggShaderWasImported;
    }

    const GGGraphics::Scene ImportColladaModel(const std::string& modelName)
    {
        colladaModelWasImported = false;

        GGGraphics::Scene scene;

        std::string completeModelName = GetModelPath() + modelName + GetColladaFileEnding();

        tinyxml2::XMLDocument colladaDoc;
        auto loadingResult = colladaDoc.LoadFile(completeModelName.c_str());

        if (loadingResult != tinyxml2::XML_SUCCESS)
        {
            GGLoggingManager::LogError("Could not load model");

            return scene;
        }

        auto root = colladaDoc.FirstChildElement("COLLADA");

        if (root == nullptr)
        {
            GGLoggingManager::LogError("The loaded model is not a valid collada model");

            return scene;
        }

        for (auto geosNode = Child(root, "library_geometries"); geosNode != nullptr; geosNode = SameSibling(geosNode))
        {
            for (auto geoNode = Child(geosNode, "geometry"); geoNode != nullptr; geoNode = SameSibling(geoNode))
            {
                GGGraphics::Geometry geometry(geoNode->Attribute("name"));

                for (auto meshNode = Child(geoNode, "mesh"); meshNode != nullptr; meshNode = SameSibling(meshNode))
                {
                    GGGraphics::Mesh mesh;

                    auto polyNode = Child(meshNode, "polylist");
                    auto indices = GGUtility::ToInts(polyNode->FirstChildElement("p")->GetText());
                    auto sources = GetAllSources(meshNode, polyNode);

                    auto i = 0;
                    while (i < indices.size() && sources.size() != 0)
                    {
                        mesh.Indices.push_back(static_cast<unsigned int>(indices[i]));

                        glm::vec3 position(0.0f);

                        if (sources.count(SourceType::Position))
                        {
                            if (sources[SourceType::Position].Stride == 3)
                            {
                                auto values = sources[SourceType::Position].Values;
                                position = glm::vec3(values[indices[i]], values[indices[i] + 1], values[indices[i] + 2]);
                            }

                            ++i;
                        }

                        glm::vec3 normal(0.0f);

                        if (sources.count(SourceType::Normal))
                        {
                            if (sources[SourceType::Normal].Stride == 3)
                            {
                                auto values = sources[SourceType::Normal].Values;
                                normal = glm::vec3(values[indices[i]], values[indices[i] + 1], values[indices[i] + 2]);
                            }

                            ++i;
                        }

                        glm::vec2 texcoord(0.0f);

                        if (sources.count(SourceType::Texcoord))
                        {
                            if (sources[SourceType::Texcoord].Stride == 2)
                            {
                                auto values = sources[SourceType::Texcoord].Values;
                                texcoord = glm::vec2(values[indices[i]], values[indices[i] + 1]);
                            }

                            ++i;
                        }

                        mesh.Vertices.push_back(GGGraphics::Vertex(position, normal, texcoord));
                    }

                    geometry.Meshes.push_back(mesh);
                }

                scene.Geometries.push_back(geometry);
            }
        }

        colladaModelWasImported = true;

        return scene;
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
