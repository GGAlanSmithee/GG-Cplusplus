#include <SDL.h>
#include <SDL_image.h>
#include "Factory.h"
#include "Exception.h"

std::unique_ptr<GG_Engine> GG_CreateEngine()
{
    auto result = SDL_Init(SDL_INIT_EVERYTHING);

    if (result != 0)
    {
        throw init_error(std::string("Failed to initialize SDL: ") + SDL_GetError());
    }

    result = IMG_Init(IMG_INIT_PNG);

    if (result & IMG_INIT_PNG != IMG_INIT_PNG)
    {
        throw init_error(std::string("Failed to initialize SDL: ") + IMG_GetError());
    }

    SDL_Window* window = SDL_CreateWindow("Hello, World!",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          800,
                                          600,
                                          SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr)
    {
        throw init_error(std::string("Failed to create SDL window: ") + SDL_GetError());
    }

    std::unique_ptr<GG_Engine> engine;

    try
    {
        std::unique_ptr<GG_Renderer>       renderer(new GG_Renderer(window));
        std::unique_ptr<GG_Event>          event(new GG_Event());
        std::unique_ptr<GG_Timer>          timer(new GG_Timer());
        std::unique_ptr<GG_TextureLoader>  textureLoader(new GG_TextureLoader());
        std::unique_ptr<GG_TextureManager> textureManager(new GG_TextureManager(std::move(textureLoader),
                                                                                renderer));

        engine = std::unique_ptr<GG_Engine>(new GG_Engine(window,
                                                          std::move(renderer),
                                                          std::move(event),
                                                          std::move(timer),
                                                          std::move(textureManager)));
    }
    catch (const init_error&)
    {
        throw;
    }

    return engine;
}
