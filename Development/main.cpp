#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Application/Application.h"
#include "Engine/Core/Core.h"
#include "Utility/Exception.h"

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

    GG_Engine* engine = nullptr;

    try
    {
        engine = GG_CreateEngine(window,
                                 GG_CreateRenderer(window),
                                 GG_CreateEvent(),
                                 GG_CreateTextureManager(GG_CreateTextureLoader()));
    }
    catch (const init_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    auto application = GG_CreateApplication(GG_World(2000));

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
        GG_DestroyApplication(application);
        GG_DestroyEngine(engine);
        GG_QuitSDLImage();
        GG_QuitSDL();
    }

    GG_DestroyApplication(application);
    GG_DestroyEngine(engine);
    GG_QuitSDLImage();
    GG_QuitSDL();

    return 0;
}
