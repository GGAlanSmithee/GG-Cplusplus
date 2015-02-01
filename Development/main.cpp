#include "Application/Application.h"
#include "Engine/Core/Core.h"

int main(int argc, char* args[])
{
    GGCoreEngine::World world(1000);

    GGApplication::Game game(world);

    return GGCoreEngine::Execute(game);

    return 0;
}
