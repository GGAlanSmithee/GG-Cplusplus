#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tinyxml2.h"
#include "Utility/Utility.h"

const std::vector<int> GetPolyIndices(const tinyxml2::XMLElement* element)
{
    return GGUtility::ToInts(element->FirstChildElement("p")->GetText());
}

const std::vector<int> GetPolyVertices(const tinyxml2::XMLElement* element)
{
    return GGUtility::ToInts(element->FirstChildElement("vcount")->GetText());
}

typedef struct Node
{
    Node(std::string name) : Name(name)
    {
        // Empty
    }

    std::string Name;
}
Node;

typedef struct Polylist
{
    std::vector<int> Indicies;
}
Polylist;

typedef struct Source
{
    int TotalCount = 0;
    int Stride     = 0;
    std::vector<float> Values;
}
Source;

typedef struct Mesh
{
    std::vector<int> Indicies;
    std::vector<Source> Sources;
}
Mesh;

typedef struct Geometry : Node
{
    Geometry(std::string name) : Node(name)
    {
        // Empty
    }

    std::vector<Mesh> Meshes;
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
                Mesh mesh;

                auto polyNode = Child(meshNode, "polylist");
                auto indices = GetPolyIndices(polyNode);
                auto vertices = GetPolyVertices(polyNode);
                auto vertexCount = std::stoi(polyNode->Attribute("count"));
                auto positionSource = GetSource(meshNode, geoNode->Attribute("id"), "positions");
                auto normalSource = GetSource(meshNode, geoNode->Attribute("id"), "normals");

                int accumilatedIndexCount = 0;
                for (int i = 0; i < vertexCount; ++i)
                {
                    auto vertex = vertices.at(i);

                    std::cout << "Vertex: ";

                    for (int j = accumilatedIndexCount; j < accumilatedIndexCount+vertex; ++j)
                    {
                        std::cout << indices[j] << " ";
                    }

                    std::cout << std::endl;

                    accumilatedIndexCount += vertex;
                }

                for (auto index : indices)
                {
                    std::cout << index << std::endl;
                }

                for (auto vertex : vertices)
                {
                    std::cout << vertex << std::endl;
                }

                std::cout << "position total count: " << positionSource.TotalCount << std::endl;
                std::cout << "position stride: " << positionSource.Stride << std::endl;
                std::cout << "position values: " << std::endl;

                for (auto positionValue : positionSource.Values)
                {
                    std::cout << positionValue << " ";
                }

                std::cout << std::endl;

                std::cout << "normal total count: " << normalSource.TotalCount << std::endl;
                std::cout << "normal stride: " << normalSource.Stride << std::endl;
                std::cout << "normal values: " << std::endl;

                for (auto normalValue : normalSource.Values)
                {
                    std::cout << normalValue << " ";
                }

                std::cout << std::endl;

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
            for (auto index : mesh.Indicies)
            {
                std::cout << index << ' ';
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
