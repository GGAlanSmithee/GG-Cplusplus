#include <iostream>
#include "Utility/Exception.h"
#include "Utility/Factory.h"
#include "Application/ApplicationData.h"

int main(int argc, char* args[])
{
    /// @todo remove when done testing
    using IntEntry = GG_ApplicationDataEntry<'int', int>;
    using StrEntry = GG_ApplicationDataEntry<'str', std::string>;

    GG_ApplicationData applicationData;
    applicationData.Add<IntEntry>(12321);
    applicationData.Add<StrEntry>("sdasdasd");

    auto i = applicationData.Get<IntEntry>();
    std::cout << i << std::endl;

    auto s = applicationData.Get<StrEntry>();
    std::cout << s << std::endl;

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
