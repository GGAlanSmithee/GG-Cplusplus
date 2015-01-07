#include <iostream>
#include "Manager/Resource/Resource.h"

int main()
{
    std::string modelName;

    std::cout << "Enter the name of the collada file to load (without .dae): ";
    std::cin >> modelName;

    auto geometries = GGResourceManager::ImportColladaModel(modelName);

    if (!GGResourceManager::ColladaModelWasImported())
    {
        return -1;
    }

    GGResourceManager::ExportGGModel(geometries, modelName);

    std::cout << "Model converted succesfully!" << std::endl;

    return 0;
}
