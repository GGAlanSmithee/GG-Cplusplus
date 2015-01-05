#include <SDL_image.h>
#include <glm/glm.hpp>
#include "Renderer.h"
#include "Graphics/Texture.h"
#include "Graphics/Vertex.h"

namespace GGRendererEngine
{
    bool wasInitialized = false;

    ShaderManager shaderManager;
    Pipeline pipeline;

    SDL_Window* window = nullptr;
    SDL_GLContext glContext;

    GLuint VBO;
    GLuint IBO;

    void Initialize()
    {
        wasInitialized = false;

        if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
        {
            if (SDL_Init(SDL_INIT_VIDEO) != 0)
            {
                SetError("Failed to initialize SDL Video: ", SDL_GetError());
                return;
            }
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        window = SDL_CreateWindow("Graphics Test",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  pipeline.GetScreenDimensions().x,
                                  pipeline.GetScreenDimensions().y,
                                  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

        glContext = SDL_GL_CreateContext(window);

        if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
        {
            SetError("Failed to initialize SDL_image: ", IMG_GetError());
            return;
        }

        GLenum status = glewInit();

        if (status != GLEW_OK)
        {
            SetError("Failed to initialize GLEW: ", glewGetErrorString(status));
            return;
        }

        SetSwapInterval(1);

        SetClearColor(0.6f, 0.8f, 0.92f, 1.0f);

        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);

        shaderManager.CreateProgram();

        if (!shaderManager.ProgramWasCreated())
        {
            return;
        }

        shaderManager.BindUniforms();

        if (!shaderManager.UniformsWereBound())
        {
            return;
        }

        shaderManager.LoadTextures();

        if (!shaderManager.TexturesWereLoaded())
        {
            return;
        }

        wasInitialized = true;
    }

    void CreateVertexBuffer()
    {
        GGGraphics::Vertex vertices[] =
                           {
                               // Front face
                               GGGraphics::Vertex(glm::vec3(-1.0, -1.0,  1.0), glm::vec3(1.0f), glm::vec2(0.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0, -1.0,  1.0), glm::vec3(1.0f), glm::vec2(1.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0,  1.0,  1.0), glm::vec3(1.0f), glm::vec2(1.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0,  1.0,  1.0), glm::vec3(1.0f), glm::vec2(0.0, 1.0)),

                               // Back face
                               GGGraphics::Vertex(glm::vec3(-1.0, -1.0, -1.0), glm::vec3(1.0f), glm::vec2(1.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0,  1.0, -1.0), glm::vec3(1.0f), glm::vec2(1.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0,  1.0, -1.0), glm::vec3(1.0f), glm::vec2(0.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0, -1.0, -1.0), glm::vec3(1.0f), glm::vec2(0.0, 0.0)),

                               // Top face
                               GGGraphics::Vertex(glm::vec3(-1.0,  1.0, -1.0), glm::vec3(1.0f), glm::vec2(0.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0,  1.0,  1.0), glm::vec3(1.0f), glm::vec2(0.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0,  1.0,  1.0), glm::vec3(1.0f), glm::vec2(1.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0,  1.0, -1.0), glm::vec3(1.0f), glm::vec2(1.0, 1.0)),

                               // Bottom face
                               GGGraphics::Vertex(glm::vec3(-1.0, -1.0, -1.0), glm::vec3(1.0f), glm::vec2(1.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0, -1.0, -1.0), glm::vec3(1.0f), glm::vec2(0.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0, -1.0,  1.0), glm::vec3(1.0f), glm::vec2(0.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0, -1.0,  1.0), glm::vec3(1.0f), glm::vec2(1.0, 0.0)),

                               // Right face
                               GGGraphics::Vertex(glm::vec3( 1.0, -1.0, -1.0), glm::vec3(1.0f), glm::vec2(1.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0,  1.0, -1.0), glm::vec3(1.0f), glm::vec2(1.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0,  1.0,  1.0), glm::vec3(1.0f), glm::vec2(0.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3( 1.0, -1.0,  1.0), glm::vec3(1.0f), glm::vec2(0.0, 0.0)),

                               // Left face
                               GGGraphics::Vertex(glm::vec3(-1.0, -1.0, -1.0), glm::vec3(1.0f), glm::vec2(0.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0, -1.0,  1.0), glm::vec3(1.0f), glm::vec2(1.0, 0.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0,  1.0,  1.0), glm::vec3(1.0f), glm::vec2(1.0, 1.0)),
                               GGGraphics::Vertex(glm::vec3(-1.0,  1.0, -1.0), glm::vec3(1.0f), glm::vec2(0.0, 1.0))
                           };

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }

    void CreateIndexBuffer()
    {
        unsigned int Indices[] =
                     {
                         0,  1,  2,    0,  2,  3, // Front face
                         4,  5,  6,    4,  6,  7, // Back face
                         8,  9, 10,    8, 10, 11, // Top face
                        12, 13, 14,   12, 14, 15, // Bottom face
                        16, 17, 18,   16, 18, 19, // Right face
                        20, 21, 22,   20, 22, 23  // Left face
                     };

        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
    }

    void DrawModel(const glm::mat4& model, const GGEnum::Texture texture)
    {
        shaderManager.SetUniformMatrix4f(GGEnum::Uniform::MVP, pipeline.GetMVPMatrix(model));

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GGGraphics::Vertex), (const GLvoid*)offsetof(GGGraphics::Vertex, Position));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GGGraphics::Vertex), (const GLvoid*)offsetof(GGGraphics::Vertex, TexCoord));

        shaderManager.ActivateTexture(texture);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }

    void ClearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void UpdateScreen()
    {
        SDL_GL_SwapWindow(window);
    }

    void SetSwapInterval(const int interval)
    {
        SDL_GL_SetSwapInterval(interval);
    }

    void SetClearColor(const float r, const float g, const float b, const float a)
    {
        glClearColor(r, g, b, a);
    }

    void CleanUp()
    {
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    const bool WasInitialized()
    {
        return wasInitialized;
    }
}
