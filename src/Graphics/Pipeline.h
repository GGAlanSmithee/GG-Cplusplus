#ifndef PIPELINE_H_INCLUDED
#define PIPELINE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Component/Component.h"

namespace GGGraphics
{
    class Pipeline
    {
        public:
            const glm::vec2 GetScreenDimensions() const;
            void SetScreenDimensions(const glm::vec2&);

            const glm::mat4 GetProjectionMatrix() const;
            void SetProjectionMatrix(const glm::mat4&);

            const glm::mat4 GetViewMatrix() const;
            void SetViewMatrix(const glm::mat4&);

            const glm::mat4 GetMVPMatrix(const glm::mat4&) const;

        private:
            glm::vec2 _screenDimensions = glm::vec2(800.0f, 600.0f);

            glm::mat4 _projectionMatrix = glm::perspective(45.0f,
                                                           _screenDimensions.x / _screenDimensions.y,
                                                           1.0f,
                                                           200.0f);

            glm::mat4 _viewMatrix = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
    };
}

#endif // PIPELINE_H_INCLUDED
