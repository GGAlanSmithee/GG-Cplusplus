#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "tinyxml2.h"
#include "Utility/Utility.h"
#include "Graphics/Vertex.h"
#include "Graphics/Mesh.h"

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

//typedef struct Mesh
//{
//    std::vector<int> Indices;
//    std::vector<GGGraphics::Vertex> Vertices;
//}
//Mesh;

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

const Source GetSource(tinyxml2::XMLElement* mesh, const std::string& geometryName, const std::string& sourceName)
{
    Source source;

    for (auto srcNode = Child(mesh, "source"); srcNode != nullptr; srcNode = SameSibling(srcNode))
    {
        if (std::string(srcNode->Attribute("id")).compare(geometryName + "-" + sourceName) == 0)
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
                auto VerticesPerPoly = GGUtility::ToInts(polyNode->FirstChildElement("vcount")->GetText());
                auto polyCount = std::stoi(polyNode->Attribute("count"));

                auto numbInputs = 0;

                for (auto input = Child(polyNode, "input"); input != nullptr; input = SameSibling(input))
                {
                    ++numbInputs;
                }

                auto positionSource = GetSource(meshNode, geoNode->Attribute("id"), "positions");
                auto normalSource = GetSource(meshNode, geoNode->Attribute("id"), "normals");
                auto textureSource = GetSource(meshNode, geoNode->Attribute("id"), "map-0");

                for (auto i = 0; i < indices.size(); i += numbInputs)
                {
                    mesh.Indices.push_back(static_cast<unsigned int>(indices[i]));

                    std::vector<float> vertexPositions;

                    for (auto k = 0; k < positionSource.Stride; ++k)
                    {
                        vertexPositions.push_back(positionSource.Values[indices[i] + k]);
                    }

                    std::vector<float> vertexNormals;

                    for (auto k = 0; k < normalSource.Stride; ++k)
                    {
                        vertexNormals.push_back(normalSource.Values[indices[i + 1] + k]);
                    }

                    std::vector<float> vertexTextureCoords;

                    for (auto k = 0; k < textureSource.Stride; ++k)
                    {
                        vertexTextureCoords.push_back(textureSource.Values[indices[i + 2] + k]);
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
