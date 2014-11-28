#include <iostream>
#include "tinyxml2.h"

int main()
{
    tinyxml2::XMLDocument colladaDoc;
    colladaDoc.LoadFile("crate.dae");

    auto colladaRoot = colladaDoc.FirstChildElement("COLLADA");

    if (colladaRoot == nullptr)
    {
        std::cerr << "Could not load model" << std::endl;

        return -1;
    }

    tinyxml2::XMLDocument ggDoc;

	auto declaration = ggDoc.NewDeclaration("xml version=\"1.0\"");
	ggDoc.InsertFirstChild(declaration);

    auto result = ggDoc.SaveFile("model.gg");

    if (result != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "Could not save model XML data: " << result << std::endl;
    }

    auto libraryGeometries = colladaRoot->FirstChildElement("library_geometries");

    while (libraryGeometries != nullptr)
    {
//        tinyxml2::XMLElement* geometriesElement = new tinyxml2::XMLElement("geometries");
//        ggDoc.InsertFirstChild(geometriesElement);

        auto geometry = libraryGeometries->FirstChildElement("geometry");

        while (geometry != nullptr)
        {
//            tinyxml2::XMLElement* geometryElement = new tinyxml2::XMLElement("geometries");
//            geometriesElement->InsertFirstChild(geometryElement);

            auto mesh = geometry->FirstChildElement("mesh");

            while (mesh != nullptr)
            {
                auto source = mesh->FirstChildElement("source");

                while (source != nullptr)
                {
                    std::cout << "Source id: " << source->Attribute("id") << std::endl;

                    source = source->NextSiblingElement("source");
                }

                auto polyList = mesh->FirstChildElement("polylist");

                if (polyList != nullptr)
                {
                    std::cout << "Number of indicies: " << polyList->Attribute("count") << std::endl;
                }

                mesh = mesh->NextSiblingElement("mesh");
            }

            geometry = geometry->NextSiblingElement("geometry");
        }

        libraryGeometries = libraryGeometries->NextSiblingElement("library_geometries");
    }

    return 0;
}
