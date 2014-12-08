#include <iostream>
#include "tinyxml2.h"

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

    for (auto geometries = Child(root, "library_geometries"); geometries != nullptr; geometries = SameSibling(geometries))
    {
        std::cout << "hej" << std::endl;
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
