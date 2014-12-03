#include <iostream>
#include <SDL.h>
#include "Engine/Core/Core.h"
#include "Engine/Core/Entity.h"
#include "Game/Game.h"

int main(int argc, char* args[])
{
    GGCoreEngine::World world(1000);
    GGCoreEngine::CreateEntity(world);

    GGGame::Game game(world);

    return GGCoreEngine::Execute(game);
}

