#include <iostream>
#include "Manager/Resource/Import.h"
#include "Manager/Resource/Export.h"

int main()
{
    std::string modelName;

    std::cout << "Enter the name of the collada file to load (without file ending): ";
    std::cin >> modelName;

    auto scene = GGResourceManager::ImportColladaModel(modelName);

    if (!GGResourceManager::ColladaModelWasImported())
    {
        return -1;
    }

    GGResourceManager::ExportGGModel(scene, modelName);

    std::cout << "Model converted succesfully!" << std::endl;

    return 0;
}
