#include <iostream>
#include "Utility/Exception.h"
#include "Utility/Factory.h"

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

        auto application = GG_CreateApplication(engine);

        while (running)
        {
            GG_HandleEvents(GG_GetEvent(engine));

            GG_OnLogic(application, engine);

            GG_ClearScreen(GG_GetRenderer(engine));

            GG_OnRender(application, engine);

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
