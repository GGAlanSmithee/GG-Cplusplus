#include <iostream>
#include "Utility/Exception.h"
#include "Utility/Factory.h"

int main(int argc, char* args[])
{
    GG_Factory factory;

    try
    {
        auto engine = factory.GG_CreateEngine();

        GG_SetDefaultTexture(GG_GetTextureManager(engine), GG_GetRenderer(engine), "default.png");

        auto handle = GG_AddTexture(GG_GetTextureManager(engine),
                                    GG_GetRenderer(engine),
                                    "tileset.png");

        auto running = true;

        GG_RegisterKeyboardEvent(GG_GetEvent(engine), SDLK_ESCAPE, [&]() { running = false; });

        SDL_Rect source = { 100, 50, 0, 0 };
        SDL_Rect clipRect = { 30, 30, 30, 30 };

        while (running)
        {
            GG_HandleEvents(GG_GetEvent(engine));

            GG_RenderTexture(GG_GetRenderer(engine),
                             GG_GetTexture(GG_GetTextureManager(engine), handle),
                             source,
                             clipRect
                             );

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
