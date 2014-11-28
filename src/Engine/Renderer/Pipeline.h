#ifndef PIPELINE_H_INCLUDED
#define PIPELINE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Core/Component.h"

namespace GGRendererEngine
{
    /// A rendering pipeline that controls the MVP matrix and camera
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @remarks is there a need for representing the pipeline as a class or should it be re-written as functions?
    class Pipeline
    {
        public:
            /// Gets the screens (main viewports) dimensions
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @return a 2d vector where x is screen width and y screen height
            const glm::vec2 GetScreenDimensions() const;
            
            /// Sets the screens (main viewports) dimensions
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @param screenDimensions the new dimensions value
            void SetScreenDimensions(const glm::vec2&);

            /// Gets the projection matrix
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @return the projection matrix as a 4d matrix 
            const glm::mat4 GetProjectionMatrix() const;
            
            /// Sets the projection matrix
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @param projectionMatrix the new projection matrix value
            void SetProjectionMatrix(const glm::mat4&);

            /// Gets the view matrix
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @return the view matrix as a 4d matrix
            const glm::mat4 GetViewMatrix() const;
            
            /// Sets the view matrix
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @param viewMatrix the new view matrix value
            void SetViewMatrix(const glm::mat4&);

            /// Gets the MVP (Model, View, Projection) matrix
            /// @author Alan Smithee
            /// @date created 2014-11-28
            /// @return the MVP matrix as a 4d matrix
            /// @param modelMatrix the matrix of the current model
            /// @remark the MVP matrix is calculated by multiplying the matricies (Projection * View * Model)
            const glm::mat4 GetMVPMatrix(const glm::mat4&) const;

        private:
            glm::vec2 _screenDimensions = glm::vec2(800.0f, 600.0f);

            glm::mat4 _projectionMatrix = glm::perspective(45.0f,
                                                           _screenDimensions.x / _screenDimensions.y,
                                                           0.1f,
                                                           100.0f);

            glm::mat4 _viewMatrix = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
    };
}

#endif // PIPELINE_H_INCLUDED
