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

        GG_RegisterKeyboardEvent(GG_GetEvent(engine), SDLK_ESCAPE, [&]() { running = false; });

        SDL_Rect source = { 32, 32, 32, 32 };
        SDL_Rect dest   = { 100, 50, 0, 0 };
        SDL_Rect dest2  = { 130, 50, 0, 0 };
        SDL_Rect dest3  = { 130, 80, 0, 0 };
        SDL_Rect dest4  = { 100, 80, 0, 0 };

        auto application = GG_CreateApplication();

        while (running)
        {
            GG_HandleEvents(GG_GetEvent(engine));

            GG_OnLogic(application, engine);

            GG_ClearScreen(GG_GetRenderer(engine));

            GG_RenderTexture(GG_GetRenderer(engine),
                             GG_GetTexture(GG_GetTextureManager(engine), handle),
                             source,
                             dest);

            GG_RenderTexture(GG_GetRenderer(engine),
                             GG_GetTexture(GG_GetTextureManager(engine), handle),
                             source,
                             dest2);

            GG_RenderTexture(GG_GetRenderer(engine),
                             GG_GetTexture(GG_GetTextureManager(engine), handle),
                             source,
                             dest3);

            GG_RenderTexture(GG_GetRenderer(engine),
                             GG_GetTexture(GG_GetTextureManager(engine), handle),
                             source,
                             dest4);

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
