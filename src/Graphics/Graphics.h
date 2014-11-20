#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include "ShaderManager.h"
#include "Pipeline.h"
#include "Logging.h"
#include "Texture.h"

namespace GGGraphics
{
    extern bool wasInitialized;
    extern bool textureWasLoaded;

    extern ShaderManager shaderManager;
    extern Pipeline pipeline;

    extern SDL_Window* window;
    extern SDL_Renderer* renderer;
    extern SDL_GLContext glContext;

    extern GLuint VBO;
    extern GLuint IBO;

    /// Initializes SDL video and OpenGL
    /// @author Alan Smithee
    /// @date 2014-11-19
    void Initialize();

    /// Loads a texture
    /// @author Alan Smithee
    /// @date 2014-11-20
    /// @param path the path to the image to load
    const Texture LoadTexture(const std::string&);

    /// Creates a vertexbuffer by generating and binding a buffer with vertex data
    /// @author Alan Smithee
    /// @date 2014-11-19
    void CreateVertexBuffer();

    /// Creates an indexbuffer by generating and binding a buffer with index data
    /// @author Alan Smithee
    /// @date 2014-11-19
    void CreateIndexBuffer();

    /// Sets the swap interval of the screen
    /// @author Alan Smithee
    /// @date 2014-11-19
    /// @param interval the new swap interval
    /// @remarks 1.0 will sync the swap interval with the screens refresh rate
    void SetSwapInterval(const int);

    /// Sets the screen clear color
    /// @author Alan Smithee
    /// @date 2014-11-19
    /// @param r red value
    /// @param g green value
    /// @param b blue value
    /// @param a alpha value
    void SetClearColor(const float, const float, const float, const float);

    /// Sets the scale of the next object to be processed
    /// @author Alan Smithee
    /// @date 2014-11-19
    /// @param scale the new scale
    void SetScale(const float);

    /// @author Alan Smithee
    /// @date 2014-11-19
    /// Draws a model to the screen using current context
    /// @param model the model to draw
    void DrawModel(const glm::mat4&);

    /// Clears the screen
    /// @author Alan Smithee
    /// @date 2014-11-19
    void ClearScreen();

    /// Updates the screen by swapping it according to the set swap interval
    /// @author Alan Smithee
    /// @date 2014-11-19
    void UpdateScreen();

    /// Cleans up used resources by destroying the glContext and deleting the SDL_Window* used
    /// @author Alan Smithee
    /// @date 2014-11-19
    void CleanUp();

    /// Returns a boolean value indicating if SDL video and OpenGL was initialized
    /// @author Alan Smithee
    /// @date 2014-11-19
    /// @return true if initialized succesfully, false if not
    const bool WasInitialized();
}

#endif // GRAPHICS_H
