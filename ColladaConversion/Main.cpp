#include <iostream>
#include "ColladaConversion.h"

int main()
{
    std::string modelName;

    std::cout << "Enter the name of the collada file to load (without file ending): ";
    std::cin >> modelName;

    auto scene = GGColladaConversion::ImportColladaModel(modelName);

    if (!GGColladaConversion::ColladaModelWasImported())
    {
        return -1;
    }

    GGColladaConversion::ExportGGModel(scene, modelName);

    std::cout << "Model converted succesfully!" << std::endl;

    return 0;
}
