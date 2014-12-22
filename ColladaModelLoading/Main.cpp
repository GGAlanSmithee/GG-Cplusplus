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

typedef struct Geometry : Node
{
    Geometry(std::string name) : Node(name)
    {
        // Empty
    }

    std::vector<GGGraphics::Mesh> Meshes;
}
Geometry;

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
    std::string colladaFileName = "crate";
//
//    std::cout << "Enter the name of the collada file to load (without .dae): ";
//    std::cin >> colladaFileName;

    tinyxml2::XMLDocument colladaDoc;
    auto loadingResult = colladaDoc.LoadFile((colladaFileName + ".dae").c_str());

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

    std::vector<Geometry> geometryList;

    for (auto geosNode = Child(root, "library_geometries"); geosNode != nullptr; geosNode = SameSibling(geosNode))
    {
        for (auto geoNode = Child(geosNode, "geometry"); geoNode != nullptr; geoNode = SameSibling(geoNode))
        {
            Geometry geometry(geoNode->Attribute("name"));

            for (auto meshNode = Child(geoNode, "mesh"); meshNode != nullptr; meshNode = SameSibling(meshNode))
            {
                GGGraphics::Mesh mesh;

                auto polyNode = Child(meshNode, "polylist");
                auto indices = GGUtility::ToInts(polyNode->FirstChildElement("p")->GetText());
                auto sources = GetAllSources(meshNode, polyNode);

                /// @todo iterate sources rather than vertices?

                std::vector<GGGraphics::Vertex> vertexList;

                for (const auto& kv : sources)
                {
                    std::cout << static_cast<std::underlying_type<SourceType>::type>(kv.first) << std::endl;

                    // switch type of source here and add to vertex n in vertex list
                }

                for (auto i = 0; i < indices.size(); i += sources.size())
                {
                    mesh.Indices.push_back(static_cast<unsigned int>(indices[i]));

                    std::vector<float> vertexPositions;

                    for (auto k = 0; k < sources[SourceType::Position].Stride; ++k)
                    {
                        vertexPositions.push_back(sources[SourceType::Position].Values[indices[i] + k]);
                    }

                    std::vector<float> vertexNormals;

                    for (auto k = 0; k < sources[SourceType::Normal].Stride; ++k)
                    {
                        vertexNormals.push_back(sources[SourceType::Normal].Values[indices[i + 1] + k]);
                    }

                    std::vector<float> vertexTextureCoords;

                    for (auto k = 0; k < sources[SourceType::Texcoord].Stride; ++k)
                    {
                        vertexTextureCoords.push_back(sources[SourceType::Texcoord].Values[indices[i + 2] + k]);
                    }

                    mesh.Vertices.push_back(GGGraphics::Vertex(glm::vec3(vertexPositions[0],
                                                                         vertexPositions[1],
                                                                         vertexPositions[2]),
                                                               glm::vec3(vertexNormals[0],
                                                                         vertexNormals[1],
                                                                         vertexNormals[2]),
                                                               glm::vec2(vertexTextureCoords[0],
                                                                         vertexTextureCoords[2])));
                }

                geometry.Meshes.push_back(mesh);
            }

            geometryList.push_back(geometry);
        }
    }

    for (auto geometry : geometryList)
    {
        std::cout << geometry.Name << std::endl;

        for (auto mesh : geometry.Meshes)
        {
            for (auto index : mesh.Vertices)
            {
                std::cout << index.Position.x  << ", " << index.Position.y  << ", " << index.Position.z << std::endl;
                std::cout << index.Normal.x  << ", " << index.Normal.y  << ", " << index.Normal.z << std::endl;
                std::cout << index.Texture.x  << ", " << index.Texture.y  << std::endl;
                std::cout << std::endl;
            }

            std::cout << std::endl;

            for (auto index : mesh.Indices)
            {
                std::cout << index << ", ";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
