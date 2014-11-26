#include <iostream>
#include "tinyxml2.h"

int main()
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile("crate.dae");

    auto root = doc.FirstChildElement("COLLADA");

    if (root == nullptr)
    {
        std::cout << "is null" << std::endl;
    }

    auto e = root->FirstChildElement("library_geometries");

    while (e != nullptr)
    {
        std::cout << "library geometries" << std::endl;
        e = e->NextSiblingElement("library_geometries");
    }

    return 0;
}
