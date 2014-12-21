#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include "ShaderManager.h"
#include "Pipeline.h"
#include "Logging.h"
#include "Graphics/Texture.h"
#include "Enum/Enum.h"

namespace GGRendererEngine
{
    /// Flag indicating if the rendering system was initialized
    /// @author Alan Smithee
    /// @date created 2014-11-28
    extern bool wasInitialized;

    /// Instance of the (for now) only shadermanager (shader) in the render engine
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @todo remove this when refactored shader functionality
    extern ShaderManager shaderManager;

    /// Instance of the rendering pipeline
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @todo consider removing this - is there a use for multiple pipelines?
    extern Pipeline pipeline;

    /// The game window
    /// @author Alan Smithee
    /// @date created 2014-11-28
    extern SDL_Window* window;

    /// The GL context, maanged via SDL
    /// @author Alan Smithee
    /// @date created 2014-11-28
    extern SDL_GLContext glContext;

    /// Vertex Buffer Object, used to upload vertex data to the graphics card
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @todo should this be moved to the shader or pipeline?
    extern GLuint VBO;

    /// Index Buffer Object, used to upload index data to the graphics card
    /// @author Alan Smithee
    /// @date created 2014-11-28
    /// @todo should this be moved to the shader or pipeline?
    extern GLuint IBO;

    /// Initializes SDL video and OpenGL
    /// @author Alan Smithee
    /// @date 2014-11-19
    void Initialize();

    /// Creates a vertexbuffer by generating and binding a buffer with vertex data
    /// @author Alan Smithee
    /// @date created 2014-11-19
    void CreateVertexBuffer();

    /// Creates an indexbuffer by generating and binding a buffer with index data
    /// @author Alan Smithee
    /// @date created 2014-11-19
    void CreateIndexBuffer();

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

    /// Sets the scale of the next object to be processed
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @param scale the new scale
    void SetScale(const float);

    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// Draws a model to the screen using current context
    /// @param model the model to draw
    /// @param texture the texture to use when drawing the model
    void DrawModel(const glm::mat4&, const GGEnum::Texture);

    /// Clears the screen
    /// @author Alan Smithee
    /// @date 2014-11-19
    void ClearScreen();

    /// Updates the screen by swapping it according to the set swap interval
    /// @author Alan Smithee
    /// @date created 2014-11-19
    void UpdateScreen();

    /// Cleans up used resources by destroying the glContext and deleting the SDL_Window* used
    /// @author Alan Smithee
    /// @date created 2014-11-19
    void CleanUp();

    /// Returns a boolean value indicating if SDL video and OpenGL was initialized
    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// @return true if initialized succesfully, false if not
    const bool WasInitialized();
}

#endif // RENDERER_H_INCLUDED
