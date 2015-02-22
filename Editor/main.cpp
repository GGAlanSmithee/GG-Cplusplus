#include <iostream>
#include "Utility/Exception.h"
#include "Utility/Factory.h"
#include "Application/Application.h"
#include "Application/ApplicationData.h"
#include "Application/EditorApplication.h"
#include "Application/TestApplication.h"
#include "Utility/Declarations.h"

int main(int argc, char* args[])
{
    try
    {
        auto engine = GG_CreateEngine();

        GG_SetDefaultTexture(GG_GetTextureManager(engine), GG_GetRenderer(engine), "default.png");

        auto handle = GG_AddTexture(GG_GetTextureManager(engine),
                                    GG_GetRenderer(engine),
                                    "tileset.png");

        auto running = true;
        GG_RegisterKeyDownEvent(GG_GetEvent(engine), SDLK_ESCAPE, [&]() { running = false; });

        auto data = std::make_shared<GG_ApplicationData>();
        data->Add<EntityManagerEntry>(GG_EntityManager());
        data->Add<MapEntry>(GG_Map());
        data->Add<CameraEntry>(GG_CreateCamera(*data->Write<EntityManagerEntry>()));

        std::shared_ptr<GG_Application> application(new EditorApplication(engine, data));

        auto state = 0;
        GG_RegisterKeyDownEvent(GG_GetEvent(engine), SDLK_1, [&]()
                                {
                                    if (state == 0)
                                    {
                                        application = std::make_shared<TestApplication>(engine, data);
                                        state = 1;
                                    }
                                    else if (state == 1)
                                    {
                                        application = std::make_shared<EditorApplication>(engine, data);
                                        state = 0;
                                    }
                                });

        while (running)
        {
            GG_HandleEvents(GG_GetEvent(engine));
            GG_UpdateTimer(GG_GetTimer(engine));

            application->OnLogic(engine);

            GG_ClearScreen(GG_GetRenderer(engine));

            application->OnRender(engine);

            GG_UpdateScreen(GG_GetRenderer(engine));

            SDL_Delay(1);
        }
    }
    /// @todo refactor this
    catch (const init_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
