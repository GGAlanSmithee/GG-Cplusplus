#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include "ShaderManager.h"
#include "Pipeline.h"
#include "Logging.h"

namespace GGGraphics
{
    extern bool wasInitialized;

    extern ShaderManager shaderManager;
    extern Pipeline pipeline;

    extern SDL_Window* window;
    extern SDL_GLContext glContext;

    extern GLuint VBO;
    extern GLuint IBO;

    /// @author Alan Smithee
    /// Initializes SDL video and OpenGL
    void Initialize();

    /// @author Alan Smithee
    /// Creates a vertexbuffer by generating and binding a buffer with vertex data
    void CreateVertexBuffer();

    /// @author Alan Smithee
    /// Creates an indexbuffer by generating and binding a buffer with index data
    void CreateIndexBuffer();

    /// @author Alan Smithee
    /// Sets the swap interval of the screen
    /// @param interval the new swap interval
    /// @remarks 1.0 will sync the swap interval with the screens refresh rate
    void SetSwapInterval(const int);

    /// @author Alan Smithee
    /// Sets the screen clear color
    /// @param r red value
    /// @param g green value
    /// @param b blue value
    /// @param a alpha value
    void SetClearColor(const float, const float, const float, const float);

    /// @author Alan Smithee
    /// Sets the scale of the next object to be processed
    /// @param scale the new scale
    void SetScale(const float);

    void DrawModel(const glm::mat4&);

    void ClearScreen();

    void UpdateScreen();

    /// @author Alan Smithee
    /// Cleans up used resources by destroying the glContext and deleting the SDL_Window* used
    void CleanUp();

    /// @author Alan Smithee
    /// Returns a boolean value indicating if SDL video and OpenGL was initialized
    /// @return true if initialized succesfully, false if not
    const bool WasInitialized();
}

#endif // GRAPHICS_H
