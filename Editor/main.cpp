#include <iostream>
#include "Utility/Exception.h"
#include "Utility/Factory.h"
#include "Application/Application.h"
#include "Application/ApplicationData.h"
#include "Application/EditorApplication.h"
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

        auto editor = std::make_shared<EditorApplication>(engine, data);

        while (running)
        {
            GG_HandleEvents(GG_GetEvent(engine));

            editor->OnLogic(engine);

            GG_ClearScreen(GG_GetRenderer(engine));

            editor->OnRender(engine);

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
