#include <map>
#include <tinyxml2.h>
#include <iostream>

#include "ColladaConversion.h"
#include "Manager/Resource/Core.h"
#include "Utility/Utility.h"

namespace // Private functions and variables
{
    bool colladaModelWasImported = false;

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

                    if (sourceType == SourceType::Position)
                    {
                        std::cout << srcNode->FirstChildElement("float_array")->GetText() << std::endl;
                    }

                    source.Values = GGUtility::ToFloats(srcNode->FirstChildElement("float_array")->GetText());
                }
            }

            sources[sourceType] = source;
        }

        return sources;
    }

    const bool VertexExistsInMesh(const GGGraphics::Mesh& mesh, const GGGraphics::Vertex& vertex)
    {
        for (auto v : mesh.Vertices)
        {
            if (v.Position == vertex.Position && v.Normal == vertex.Normal && v.TexCoord == vertex.TexCoord)
            {
                return true;
            }
        }

        return false;
    }

    const unsigned int GetIndexOfExistingVertex(const GGGraphics::Mesh& mesh, const GGGraphics::Vertex& vertex)
    {
        auto index = 0;
        for (auto v : mesh.Vertices)
        {
            if (v.Position == vertex.Position && v.Normal == vertex.Normal && v.TexCoord == vertex.TexCoord)
            {
                break;;
            }

            ++index;
        }

        return index;
    }
}

namespace GGColladaConversion
{
    const bool ColladaModelWasImported()
    {
        return colladaModelWasImported;
    }

    const GGGraphics::Scene ImportColladaModel(const std::string& modelName)
    {
        colladaModelWasImported = false;

        GGGraphics::Scene scene;

        std::string completeModelName = GGResourceManager::GetModelPath() +
                                        modelName +
                                        GGResourceManager::GetColladaFileEnding();

        tinyxml2::XMLDocument colladaDoc;
        auto loadingResult = colladaDoc.LoadFile(completeModelName.c_str());

        if (loadingResult != tinyxml2::XML_SUCCESS)
        {
//            GGLoggingManager::LogError("Could not load model");

            return scene;
        }

        auto root = colladaDoc.FirstChildElement("COLLADA");

        if (root == nullptr)
        {
//            GGLoggingManager::LogError("The loaded model is not a valid collada model");

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
                        glm::vec3 position(0.0f);

                        if (sources.count(SourceType::Position))
                        {
                            if (sources[SourceType::Position].Stride == 3)
                            {
                                auto index = indices[i] * sources[SourceType::Position].Stride;
                                auto values = sources[SourceType::Position].Values;

                                position = glm::vec3(values[index], values[index + 1], values[index + 2]);
                            }

                            ++i;
                        }

                        glm::vec3 normal(0.0f);

                        if (sources.count(SourceType::Normal))
                        {
                            if (sources[SourceType::Normal].Stride == 3)
                            {
                                auto index = indices[i] * sources[SourceType::Normal].Stride;
                                auto values = sources[SourceType::Normal].Values;

                                normal = glm::vec3(values[index], values[index + 1], values[index + 2]);
                            }

                            ++i;
                        }

                        glm::vec2 texcoord(0.0f);

                        if (sources.count(SourceType::Texcoord))
                        {
                            if (sources[SourceType::Texcoord].Stride == 2)
                            {
                                auto index = indices[i] * sources[SourceType::Texcoord].Stride;
                                auto values = sources[SourceType::Texcoord].Values;

                                texcoord = glm::vec2(values[index], values[index + 1]);
                            }

                            ++i;
                        }

                        auto vertex = GGGraphics::Vertex(position, normal, texcoord);

                        if (VertexExistsInMesh(mesh, vertex))
                        {
                            mesh.Indices.push_back(GetIndexOfExistingVertex(mesh, vertex));
                        }
                        else
                        {
                            std::cout << i << ": " << indices[i] << std::endl;
                            mesh.Indices.push_back(static_cast<unsigned int>(indices[i]));
                            mesh.Vertices.push_back(vertex);
                        }
                    }

                    geometry.Meshes.push_back(mesh);
                }

                scene.Geometries.push_back(geometry);
            }
        }

        colladaModelWasImported = true;

        return scene;
    }

    void ExportGGModel(const GGGraphics::Scene& scene, const std::string& modelName)
    {
        tinyxml2::XMLDocument ggDoc;

        auto ggDeclaration = ggDoc.NewDeclaration("xml version=\"1.0\"");
        ggDoc.InsertFirstChild(ggDeclaration);

        auto ggGeometries = ggDoc.NewElement("geometries");
        ggDoc.InsertEndChild(ggGeometries);

        for (auto geometry : scene.Geometries)
        {
            auto ggGeometry = ggDoc.NewElement("geometry");
            ggGeometries->InsertEndChild(ggGeometry);

            for (auto mesh : geometry.Meshes)
            {
                auto ggMesh = ggDoc.NewElement("mesh");
                ggGeometry->InsertEndChild(ggMesh);

                for (auto vertex : mesh.Vertices)
                {
                    auto ggVertex = ggDoc.NewElement("vertex");
                    ggMesh->InsertEndChild(ggVertex);

                    std::stringstream position;
                    position << vertex.Position.x << " " << vertex.Position.y << " " << vertex.Position.z;

                    auto ggPosition = ggDoc.NewElement("position");
                    ggPosition->InsertEndChild(ggDoc.NewText(position.str().c_str()));
                    ggVertex->InsertEndChild(ggPosition);

                    std::stringstream normal;
                    normal << vertex.Normal.x << " " << vertex.Normal.y << " " << vertex.Normal.z;

                    auto ggNormal = ggDoc.NewElement("normal");
                    ggNormal->InsertEndChild(ggDoc.NewText(normal.str().c_str()));
                    ggVertex->InsertEndChild(ggNormal);

                    std::stringstream texCoord;
                    texCoord << vertex.TexCoord.x << " " << vertex.TexCoord.y;

                    auto ggTexCoord = ggDoc.NewElement("texcoord");
                    ggTexCoord->InsertEndChild(ggDoc.NewText(texCoord.str().c_str()));
                    ggVertex->InsertEndChild(ggTexCoord);
                }

                std::stringstream indices;

                for (auto index : mesh.Indices)
                {
                    indices << index << " ";
                }

                auto ggIndices = ggDoc.NewElement("indices");
                ggIndices->InsertEndChild(ggDoc.NewText(indices.str().c_str()));
                ggMesh->InsertEndChild(ggIndices);
            }
        }

        ggDoc.SaveFile((GGResourceManager::GetModelPath() +
                        modelName +
                        GGResourceManager::GetGGModelFileEnding())
                       .c_str());
    }
}
