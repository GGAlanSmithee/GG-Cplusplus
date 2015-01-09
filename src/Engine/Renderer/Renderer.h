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
    /// Initializes SDL video and OpenGL
    /// @author Alan Smithee
    /// @date 2014-11-19
    void Initialize();

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

    /// @author Alan Smithee
    /// @date created 2014-11-19
    /// Draws a model to the screen using current context
    /// @param model the model to draw
    /// @param texture the texture to use when drawing the model
    void DrawModel(const glm::mat4&, const GGEnum::Texture);

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
