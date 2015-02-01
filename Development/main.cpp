#include "Application/Application.h"
#include "Engine/Core/Core.h"

int main(int argc, char* args[])
{
    GGCoreEngine::World world(1000);

    GGApplication::Application application(world);

    return GGCoreEngine::Execute(application);

    return 0;
}
