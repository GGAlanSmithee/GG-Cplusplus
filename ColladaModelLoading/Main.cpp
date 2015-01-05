#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "tinyxml2.h"
#include "Utility/Utility.h"
#include "Graphics/Vertex.h"
#include "Graphics/Mesh.h"
#include "Graphics/Geometry.h"

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

typedef struct Node
{
    Node(std::string name) : Name(name)
    {
        // Empty
    }

    std::string Name;
}
Node;

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

        Source source;

        SourceType sourceType = Sources[input->Attribute("semantic")];

        if (sourceType == SourceType::Position)
        {
            sourceName = sourceName.substr(0, sourceName.find("vertices")) + "positions";
        }

        sources[sourceType] = GetSource(meshNode, sourceName);
    }

    return sources;
}

const unsigned int GetNumberOfChilds(tinyxml2::XMLElement* parent, const std::string& childName)
{
    auto numbChilds = 0;

    for (auto child = Child(parent, childName); child != nullptr; child = SameSibling(child))
    {
        ++numbChilds;
    }

    return numbChilds;
}

int main()
{
    std::string fileName;

    std::cout << "Enter the name of the collada file to load (without .dae): ";
    std::cin >> fileName;

    tinyxml2::XMLDocument colladaDoc;
    auto loadingResult = colladaDoc.LoadFile((fileName + ".dae").c_str());

    if (loadingResult != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "Could not load model" << std::endl;

        return -1;
    }

    auto root = colladaDoc.FirstChildElement("COLLADA");

	if (root == nullptr)
    {
        std::cerr << "The loaded model is not a valid collada model" << std::endl;

        return -1;
    }

    std::vector<GGGraphics::Geometry> geometryList;

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

            geometryList.push_back(geometry);
        }
    }

    tinyxml2::XMLDocument ggDoc;

    auto ggDeclaration = ggDoc.NewDeclaration("xml version=\"1.0\"");
	ggDoc.InsertFirstChild(ggDeclaration);

    auto ggGeometries = ggDoc.NewElement("geometries");
    ggDoc.InsertEndChild(ggGeometries);

    for (auto geometry : geometryList)
    {
        auto ggGeometry = ggDoc.NewElement("geometry");
        ggGeometries->InsertEndChild(ggGeometry);

        for (auto mesh : geometry.Meshes)
        {
            auto ggMesh = ggDoc.NewElement("mesh");
            ggGeometry->InsertEndChild(ggMesh);

            for (auto vertex : mesh.Vertices)
            {
                auto ggVertex = ggDoc.NewElement("Vertex");
                ggMesh->InsertEndChild(ggVertex);

                std::stringstream position;
                position << vertex.Position.x << " " << vertex.Position.y << " " << vertex.Position.z;

                auto ggPosition = ggDoc.NewElement("Position");
                ggPosition->InsertEndChild(ggDoc.NewText(position.str().c_str()));
                ggVertex->InsertEndChild(ggPosition);

                std::stringstream normal;
                normal << vertex.Normal.x << " " << vertex.Normal.y << " " << vertex.Normal.z;

                auto ggNormal = ggDoc.NewElement("Normal");
                ggNormal->InsertEndChild(ggDoc.NewText(normal.str().c_str()));
                ggVertex->InsertEndChild(ggNormal);

                std::stringstream texCoord;
                texCoord << vertex.TexCoord.x << " " << vertex.TexCoord.y;

                auto ggTexCoord = ggDoc.NewElement("TexCoord");
                ggTexCoord->InsertEndChild(ggDoc.NewText(texCoord.str().c_str()));
                ggVertex->InsertEndChild(ggTexCoord);
            }

            std::stringstream indices;

            for (auto index : mesh.Indices)
            {
                indices << index << " ";
            }

            auto ggIndices = ggDoc.NewElement("Indices");
            ggIndices->InsertEndChild(ggDoc.NewText(indices.str().c_str()));
            ggMesh->InsertEndChild(ggIndices);
        }
    }

    ggDoc.SaveFile((fileName + ".gg").c_str());

    return 0;
}
