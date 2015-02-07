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

    GG_Engine* engine = nullptr;

    try
    {
        engine = GG_CreateEngine("Hello, World!",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 640,
                                 480,
                                 SDL_WINDOW_ALLOW_HIGHDPI);
    }
    catch (const init_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    auto result = GG_Execute(engine);

    GG_DestroyEngine(engine);
    GG_QuitSDLImage();
    GG_QuitSDL();

    return result;
}
