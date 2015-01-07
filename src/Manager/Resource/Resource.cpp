#include "Resource.h"
#include <iostream>
#include <fstream>

namespace // private functions
{
    const std::string ModelPath         = "../Model/";
    const std::string ColladaFileEnding = ".dae";
    const std::string GGFileEnding      = ".gg";

    bool colladaModelWasImported = false;
    bool ggModelWasImported = false;

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

    const Source GetSource(tinyxml2::XMLElement* mesh, const std::string& name)
    {
        Source source;

        for (auto srcNode = Child(mesh, "source"); srcNode != nullptr; srcNode = SameSibling(srcNode))
        {
            if (std::string(srcNode->Attribute("id")).compare(name) == 0)
            {
                source.TotalCount = std::stoi(srcNode->FirstChildElement("float_array")
                                                     ->Attribute("count"));

                source.Stride = std::stoi(srcNode->FirstChildElement("technique_common")
                                                 ->FirstChildElement("accessor")
                                                 ->Attribute("stride"));

                source.Values = GGUtility::ToFloats(srcNode->FirstChildElement("float_array")->GetText());
            }
        }

        return source;
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

            sources[sourceType] = GetSource(meshNode, sourceName);
        }

        return sources;
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

    const std::vector<GGGraphics::Geometry> ImportColladaModel(const std::string& modelName)
    {
        colladaModelWasImported = true;

        std::vector<GGGraphics::Geometry> geometries;

        std::string completeModelName = ModelPath + modelName + ColladaFileEnding;

        tinyxml2::XMLDocument colladaDoc;
        auto loadingResult = colladaDoc.LoadFile(completeModelName.c_str());

        if (loadingResult != tinyxml2::XML_SUCCESS)
        {
            std::cerr << "Could not load model" << std::endl;

            colladaModelWasImported = false;

            return geometries;
        }

        auto root = colladaDoc.FirstChildElement("COLLADA");

        if (root == nullptr)
        {
            std::cerr << "The loaded model is not a valid collada model" << std::endl;

            colladaModelWasImported = false;

            return geometries;
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

                geometries.push_back(geometry);
            }
        }

        return geometries;
    }

    const std::vector<GGGraphics::Geometry> ImportGGModel(const std::string& modelName)
    {
        ggModelWasImported = true;

        std::vector<GGGraphics::Geometry> geometryList;

        std::string completeModelName = ModelPath + modelName + GGFileEnding;

        tinyxml2::XMLDocument ggDoc;
        auto loadingResult = ggDoc.LoadFile(completeModelName.c_str());

        if (loadingResult != tinyxml2::XML_SUCCESS)
        {
            std::cerr << "Could not load model" << std::endl;

            ggModelWasImported = false;

            return geometryList;
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

                geometryList.push_back(geometry);
            }
        }

        return geometryList;
    }

    void ExportGGModel(const std::vector<GGGraphics::Geometry>& geometries, const std::string& modelName)
    {
        tinyxml2::XMLDocument ggDoc;

        auto ggDeclaration = ggDoc.NewDeclaration("xml version=\"1.0\"");
        ggDoc.InsertFirstChild(ggDeclaration);

        auto ggGeometries = ggDoc.NewElement("geometries");
        ggDoc.InsertEndChild(ggGeometries);

        for (auto geometry : geometries)
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

        ggDoc.SaveFile((ModelPath + modelName + GGFileEnding).c_str());
    }
}
