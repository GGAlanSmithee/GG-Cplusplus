#include <iostream>
#include <SDL.h>
#include "Engine/Core/Core.h"
#include "Engine/Core/System.h"
#include "Engine/Renderer/Renderer.h"
#include "Manager/Resource/Resource.h"

namespace GGCoreEngine
{
    const int Execute(GGGame::Game& game)
    {
        if (SDL_Init(SDL_INIT_EVENTS) != 0)
        {
            std::cerr << "Failed to initialize SDL Events." << std::endl;

            return -1;
        }

        GGRendererEngine::Initialize();

        if (!GGRendererEngine::WasInitialized())
        {
            return -1;
        }

        GGResource::LoadAllTextures();
        GGResource::LoadAllModels();
        GGResource::LoadAllShaders();

        GGGraphics::Scene scene = GGResource::GetScene("test");
        GGGraphics::Geometry geometry = scene.Geometries[0];
        GGGraphics::Mesh mesh = geometry.Meshes[0];
        std::vector<GGGraphics::Vertex> vertices = mesh.Vertices;
        std::vector<unsigned int> indices = mesh.Indices;

        GGRendererEngine::CreateVertexBuffer(vertices);
        GGRendererEngine::CreateIndexBuffer(indices);

        SDL_Event event;

        bool running = true;
        float scale = 1.0f;

        while (running)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_KEYDOWN:
                    {
                        switch (event.key.keysym.sym)
                        {

                        }
                    }
                    case SDL_KEYUP:
                    {
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                            {
                                running = false;
                                break;
                            }
                        }

                        break;
                    }
                    case SDL_QUIT:
                    {
                        running = false;
                        break;
                    }
                }
            }

            auto world = game.GetWorld();

            GGCoreEngine::Movement(world);

            GGRendererEngine::ClearScreen();

            GGCoreEngine::Render(world);

            GGRendererEngine::UpdateScreen();
        }

        GGRendererEngine::CleanUp();
        SDL_Quit();

        return 0;
    }
}
