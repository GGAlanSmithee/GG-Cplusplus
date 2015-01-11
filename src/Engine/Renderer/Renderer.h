#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include "Pipeline.h"
#include "Manager/Logging/Logging.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/Vertex.h"
#include "Enum/Enum.h"

namespace GGRendererEngine
{
    /// Initializes SDL video and OpenGL
    /// @author Alan Smithee
    /// @date 2014-11-19
    void Initialize();

    /// Binds all uniforms for the passed in shader
    /// @author Alan Smithee
    /// @date created 2014-11-22
    /// @date changed 2015-01-11
    /// @param shader the shader to bind the uniforms for
    void BindUniforms(GGGraphics::Shader&);

    /// Sets the swap interval of the screen
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @param interval the new swap interval
    /// @remarks 1.0 will sync the swap interval with the screens refresh rate
    void SetSwapInterval(const int);

    /// Sets the screen clear color
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @param r red value
    /// @param g green value
    /// @param b blue value
    /// @param a alpha value
    void SetClearColor(const float, const float, const float, const float);

    /// Clears the screen
    /// @author Alan Smithee
    /// @date 2014-11-19
    void ClearScreen();

    /// Updates the screen by swapping it according to the set swap interval
    /// @author Alan Smithee
    /// @date created 2014-11-19
    void UpdateScreen();

    /// Draws a model to the screen using current context
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @date changed 2015-01-10
    /// @param transform the transform of the scene to draw
    /// @param scene the name of the scene to draw
    /// @param shader the name of the shader to use to draw the scene
    void DrawModel(const glm::mat4&, const std::string&, const std::string&);

    /// Cleans up used resources by destroying the glContext and deleting the SDL_Window* used
    /// @author Alan Smithee
    /// @date created 2014-11-19
    void CleanUp();

    /// Returns a boolean value indicating if SDL video and OpenGL was initialized
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @return true if initialized succesfully, false if not
    const bool WasInitialized();

    /// Creates a vertex buffer with passed in vertex data
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param vertices the vertex data used to bind the buffer
    void CreateVertexBuffer(std::vector<GGGraphics::Vertex>&);

    /// Creates a index buffer with passed in index data
    /// @author Alan Smithee
    /// @date created 2015-01-11
    /// @param indices the index data used to bind the buffer
    void CreateIndexBuffer(std::vector<unsigned int>&);
}

#endif // RENDERER_H_INCLUDED
