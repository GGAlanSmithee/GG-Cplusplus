#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tinyxml2.h"

const std::vector<std::string>& Split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }

    return elems;
}

std::vector<std::string> Split(const std::string &s, char delim)
{
    std::vector<std::string> elems;

    Split(s, delim, elems);

    return elems;
}

const std::vector<int> ToInts(const std::vector<std::string>& strings)
{
    std::vector<int> ints;

    for (auto s : strings)
    {
        ints.push_back(std::stoi(s));
    }

    return ints;
}

const std::vector<int> GetPolyIndices(const tinyxml2::XMLElement* element)
{
    return ToInts(Split(element->FirstChildElement("p")->GetText(), ' '));
}

const std::vector<int> GetPolyVertices(const tinyxml2::XMLElement* element)
{
    return ToInts(Split(element->FirstChildElement("vcount")->GetText(), ' '));
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

typedef struct Source : Node
{
    Source(std::string name) : Node(name)
    {
        // Empty
    }
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

tinyxml2::XMLElement* Child(tinyxml2::XMLElement* el, std::string name)
{
    return el->FirstChildElement(name.c_str());
}

tinyxml2::XMLElement* SameSibling(tinyxml2::XMLElement* el)
{
    return el->NextSiblingElement(el->Name());
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
                auto polyCount = std::stoi(polyNode->Attribute("count"));

                for (auto index : indices)
                {
                    std::cout << index << std::endl;
                }

                for (auto vertex : vertices)
                {
                    std::cout << vertex << std::endl;
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
            for (auto index : mesh.Indicies)
            {
                std::cout << index << ' ';
            }

            std::cout << std::endl;
        }
    }

//    while (colladaGeometries != nullptr)
//    {
//        auto ggGeometries = ggDoc.NewElement("geometries");
//        ggDoc.InsertEndChild(ggGeometries);
//
//        auto colladaGeometry = colladaGeometries->FirstChildElement("geometry");
//
//        while (colladaGeometry != nullptr)
//        {
//            auto geometryName = std::string(colladaGeometry->Attribute("id"));
//
//            auto ggGeometry = ggDoc.NewElement("geometry");
//            ggGeometries->InsertEndChild(ggGeometry);
//
//            auto colladaMesh = colladaGeometry->FirstChildElement("mesh");
//
//            while (colladaMesh != nullptr)
//            {
//                auto ggMesh = ggDoc.NewElement("mesh");
//                ggGeometry->InsertEndChild(ggMesh);
//
//                auto colladaSource = colladaMesh->FirstChildElement("source");
//
//                while (colladaSource != nullptr)
//                {
//                    if (std::string(colladaSource->Attribute("id")).compare(geometryName + "-positions") == 0)
//                    {
//                        auto floatArray = colladaSource->FirstChildElement("float_array");
//                        auto accessor = colladaSource->FirstChildElement("technique_common")
//                                                   ->FirstChildElement("accessor");
//
//                        auto count = floatArray->Attribute("count");
//                        auto stride = accessor->Attribute("stride");
//                        auto strideCount = accessor->Attribute("count");
//
//                        auto ggPositions = ggDoc.NewElement("positions");
//                        ggPositions->SetText(floatArray->GetText());
//                        ggPositions->SetAttribute("offset", 0);
//                        ggPositions->SetAttribute("count", count);
//                        ggPositions->SetAttribute("stride", stride);
//                        ggPositions->SetAttribute("stride-count", strideCount);
//                        ggMesh->InsertEndChild(ggPositions);
//                    }
//                    else if (std::string(colladaSource->Attribute("id")).compare(geometryName + "-normals") == 0)
//                    {
//                        auto floatArray = colladaSource->FirstChildElement("float_array");
//                        auto accessor = colladaSource->FirstChildElement("technique_common")
//                                                     ->FirstChildElement("accessor");
//
//                        auto count = floatArray->Attribute("count");
//                        auto stride = accessor->Attribute("stride");
//                        auto strideCount = accessor->Attribute("count");
//
//                        auto ggNormals = ggDoc.NewElement("normals");
//                        ggNormals->SetText(floatArray->GetText());
//                        ggNormals->SetAttribute("offset", 1);
//                        ggNormals->SetAttribute("count", count);
//                        ggNormals->SetAttribute("stride", stride);
//                        ggNormals->SetAttribute("stride-count", strideCount);
//                        ggMesh->InsertEndChild(ggNormals);
//                    }
//
//                    colladaSource = colladaSource->NextSiblingElement("source");
//                }
//
//                auto polyList = colladaMesh->FirstChildElement("polylist");
//
//                if (polyList != nullptr)
//                {
//                    auto ggIndices = ggDoc.NewElement("inidces");
//                    ggIndices->SetAttribute("count", polyList->Attribute("count"));
//                    ggIndices->SetText(polyList->FirstChildElement("p")->GetText());
//                    ggMesh->InsertEndChild(ggIndices);
//                }
//
//                colladaMesh = colladaMesh->NextSiblingElement("mesh");
//            }
//
//            colladaGeometry = colladaGeometry->NextSiblingElement("geometry");
//        }
//
//        colladaGeometries = colladaGeometries->NextSiblingElement("library_geometries");
//    }

//    tinyxml2::XMLDocument ggDoc;
//
//	auto declaration = ggDoc.NewDeclaration("xml version=\"1.0\"");
//	ggDoc.InsertFirstChild(declaration);
//
//    std::string ggModelName;
//    std::cout << "Enter the name of the file to save: ";
//    std::cin >> ggModelName;
//
//    auto result = ggDoc.SaveFile((ggModelName + ".gg").c_str());
//
//    if (result != tinyxml2::XML_SUCCESS)
//    {
//        std::cerr << "Could not save model XML data: " << result << std::endl;
//    }

    return 0;
}
