#include <SDL_image.h>
#include <glm/glm.hpp>
#include "Graphics.h"
#include "Texture.h"

namespace GGGraphics
{
    bool wasInitialized = false;
    bool textureWasLoaded = false;

    ShaderManager shaderManager;
    Pipeline pipeline;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
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

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr)
        {
            SetError("Failed to create renderer: ", SDL_GetError());
            return;
        }

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

        wasInitialized = true;
    }

    const Texture LoadTexture(const std::string& path)
    {
        textureWasLoaded = false;

        Texture texture(GL_TEXTURE_2D, path);

        SDL_Surface* surface = IMG_Load(path.c_str());

        if (!surface)
        {
            SetError("Failed to load surface: ", IMG_GetError());
            return texture;
        }

        int mode;

        if (surface->format->BytesPerPixel == 3) // RGB 24bit
        {
            mode = GL_RGB;
        }
        else if (surface->format->BytesPerPixel == 4) // RGBA 32bit
        {
            mode = GL_RGBA;
        }
        else
        {
            SetError("Loaded image was of wrong format: ", path.c_str());
            SDL_FreeSurface(surface);

            return texture;
        }

        GLuint textureId;

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        SDL_FreeSurface(surface);

        textureWasLoaded = true;

        texture.Target = GL_TEXTURE_2D;
        texture.Id = textureId;

        return texture ;
    }

    void CreateVertexBuffer()
    {
        glm::vec3 Vertices[] =
                  {
                      glm::vec3(-1.0f, -1.0f, 0.0f),
                      glm::vec3(0.0f, -1.0f, 1.0f),
                      glm::vec3(1.0f, -1.0f, 0.0f),
                      glm::vec3(0.0f, 1.0f, 0.0f)
                  };

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    }

    void CreateIndexBuffer()
    {
        unsigned int Indices[] =
                     {
                         0, 3, 1,
                         1, 3, 2,
                         2, 3, 0,
                         0, 1, 2
                     };

        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
    }

    void DrawModel(const glm::mat4& model)
    {
        shaderManager.SetUniformMatrix4f(Uniform::MVP, pipeline.GetMVPMatrix(model));

        glClear(GL_COLOR_BUFFER_BIT);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
    }

    void ClearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT);
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
