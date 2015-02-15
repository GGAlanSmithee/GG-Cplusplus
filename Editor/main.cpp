#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Engine/Core.h"
#include "Utility/Exception.h"
#include <memory>

int main(int argc, char* args[])
{
    try
    {
        GG_InitializeSDL(SDL_INIT_EVENTS | SDL_INIT_VIDEO);
    }
    catch (const init_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    try
    {
        GG_InitializeSDLImage(IMG_INIT_PNG);
    }
    catch (const init_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Hello, World!",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640,
                                          480,
                                          SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr)
    {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::unique_ptr<GG_Engine> engine;

    try
    {
        engine = std::unique_ptr<GG_Engine>(new GG_Engine(window,
                                            std::unique_ptr<GG_Renderer>(new GG_Renderer(window)),
                                            std::unique_ptr<GG_Event>(new GG_Event()),
                                            std::unique_ptr<GG_TextureManager>(new GG_TextureManager(std::unique_ptr<GG_TextureLoader>(new GG_TextureLoader())))));
    }
    catch (const init_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    try
    {
        GG_SetDefaultTexture(GG_GetTextureManager(engine), GG_GetRenderer(engine), "default.png");

        auto handle = GG_AddTexture(GG_GetTextureManager(engine),
                                    GG_GetRenderer(engine),
                                    "test.png");

        auto running = true;

        GG_RegisterKeyboardEvent(GG_GetEvent(engine), SDLK_ESCAPE, [&]() { running = false; });

        while (running)
        {
            GG_HandleEvents(GG_GetEvent(engine));

            GG_RenderTexture(GG_GetRenderer(engine), GG_GetTexture(GG_GetTextureManager(engine), handle+1));

            SDL_Delay(1);
        }
    }
    catch (std::exception e)
    {
        GG_QuitSDLImage();
        GG_QuitSDL();
    }

    GG_QuitSDLImage();
    GG_QuitSDL();

    return 0;
}
