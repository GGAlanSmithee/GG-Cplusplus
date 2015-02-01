#include <SDL.h>
#include <SDL_image.h>
#include "Application/Application.h"
#include "Engine/Core/Core.h"

int main(int argc, char* args[])
{
    if (!GGCoreEngine::InitializeSDL(SDL_INIT_EVENTS | SDL_INIT_VIDEO))
    {
        return -1;
    }

    if (!GGCoreEngine::InitializeSDLImage(IMG_INIT_PNG))
    {
        return -1;
    }

    GGCoreEngine::World world(1000);

    GGApplication::Application application(world);

    return GGCoreEngine::Execute(application);
}
