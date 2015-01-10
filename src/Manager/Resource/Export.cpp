#include <tinyxml2.h>
#include <sstream>
#include "Core.h"
#include "Export.h"

namespace GGResourceManager
{
    void ExportGGModel(const GGGraphics::Scene& scene, const std::string& modelName)
    {
        tinyxml2::XMLDocument ggDoc;

        auto ggDeclaration = ggDoc.NewDeclaration("xml version=\"1.0\"");
        ggDoc.InsertFirstChild(ggDeclaration);

        auto ggGeometries = ggDoc.NewElement("geometries");
        ggDoc.InsertEndChild(ggGeometries);

        for (auto geometry : scene.Geometries)
        {
            auto ggGeometry = ggDoc.NewElement("geometry");
            ggGeometries->InsertEndChild(ggGeometry);

            for (auto mesh : geometry.Meshes)
            {
                auto ggMesh = ggDoc.NewElement("mesh");
                ggGeometry->InsertEndChild(ggMesh);

                for (auto vertex : mesh.Vertices)
                {
                    auto ggVertex = ggDoc.NewElement("vertex");
                    ggMesh->InsertEndChild(ggVertex);

                    std::stringstream position;
                    position << vertex.Position.x << " " << vertex.Position.y << " " << vertex.Position.z;

                    auto ggPosition = ggDoc.NewElement("position");
                    ggPosition->InsertEndChild(ggDoc.NewText(position.str().c_str()));
                    ggVertex->InsertEndChild(ggPosition);

                    std::stringstream normal;
                    normal << vertex.Normal.x << " " << vertex.Normal.y << " " << vertex.Normal.z;

                    auto ggNormal = ggDoc.NewElement("normal");
                    ggNormal->InsertEndChild(ggDoc.NewText(normal.str().c_str()));
                    ggVertex->InsertEndChild(ggNormal);

                    std::stringstream texCoord;
                    texCoord << vertex.TexCoord.x << " " << vertex.TexCoord.y;

                    auto ggTexCoord = ggDoc.NewElement("texcoord");
                    ggTexCoord->InsertEndChild(ggDoc.NewText(texCoord.str().c_str()));
                    ggVertex->InsertEndChild(ggTexCoord);
                }

                std::stringstream indices;

                for (auto index : mesh.Indices)
                {
                    indices << index << " ";
                }

                auto ggIndices = ggDoc.NewElement("indices");
                ggIndices->InsertEndChild(ggDoc.NewText(indices.str().c_str()));
                ggMesh->InsertEndChild(ggIndices);
            }
        }

        ggDoc.SaveFile((GetModelPath() + modelName + GetGGFileEnding()).c_str());
    }
}
