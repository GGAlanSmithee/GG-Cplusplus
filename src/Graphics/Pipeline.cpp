#include "Pipeline.h"

namespace GGGraphics
{
    const glm::vec2 Pipeline::GetScreenDimensions() const
    {
        return _screenDimensions;
    }

    void Pipeline::SetScreenDimensions(const glm::vec2& screenDimensions)
    {
        _screenDimensions = screenDimensions;
    }

    const glm::mat4 Pipeline::GetProjectionMatrix() const
    {
        return _projectionMatrix;
    }

    void Pipeline::SetProjectionMatrix(const glm::mat4& projectionMatrix)
    {
        _projectionMatrix = projectionMatrix;
    }

    const glm::mat4 Pipeline::GetViewMatrix() const
    {
        return _viewMatrix;
    }

    void Pipeline::SetViewMatrix(const glm::mat4& viewMatrix)
    {
        _viewMatrix = viewMatrix;
    }

    const glm::mat4 Pipeline::GetModelMatrix() const
    {
        return _modelMatrix;
    }

    void Pipeline::SetModelMatrix(const glm::mat4& modelMatrix)
    {
        _modelMatrix = modelMatrix;
    }

    const glm::mat4 Pipeline::GetMVPMatrix() const
    {
        return _projectionMatrix * _viewMatrix * _modelMatrix;;
    }
}
