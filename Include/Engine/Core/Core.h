#ifndef ENGINE_CORE_CORE_H_INCLUDED
#define ENGINE_CORE_CORE_H_INCLUDED

#include "Engine/Renderer/Renderer.h"
#include "Engine/Event/Event.h"
#include "Manager/Texture/Texture.h"

class GG_Engine
{
    public:
        friend GG_Engine* const GG_CreateEngine(SDL_Window*,
                                                GG_Renderer*,
                                                std::unique_ptr<GG_Event>,
                                                GG_TextureManager*);
        friend void GG_DestroyEngine(GG_Engine*);

        friend GG_Renderer* const GG_GetRenderer(GG_Engine* const);
        friend std::unique_ptr<GG_Event> const& GG_GetEvent(GG_Engine* const);
        friend GG_TextureManager* const GG_GetTextureManager(GG_Engine* const);

    private:
        GG_Engine(SDL_Window*,
                  GG_Renderer*,
                  std::unique_ptr<GG_Event>,
                  GG_TextureManager*);

        ~GG_Engine();

        SDL_Window*               _window;
        GG_Renderer*              _renderer;
        std::unique_ptr<GG_Event> _event;
        GG_TextureManager*        _textureManager;
};

/// Creates an instance of the core engine
/// @author Alan Smithee
/// @date created 2015-02-07
/// @date changed 2015-02-08
/// @return a pointer to a newly created engine
/// @param window the engines window
/// @param renderer the engines renderer
/// @param event the engines event
/// @param textureManager the engines textureManager
/// @remarks friend of GG_Engine
GG_Engine* const GG_CreateEngine(SDL_Window* const,
                                 GG_Renderer* const,
                                 std::unique_ptr<GG_Event>,
                                 GG_TextureManager* const);

/// Destroys an instance of the core engine by freeing the memory used
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param event a pointer to the event to destroy
/// @remarks friend of GG_Engine
void GG_DestroyEngine(GG_Engine*);

/// Gets the renderer engine that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param engine the engine to get the renderer engine from
/// @return the renderer engine, or null if no renderer engine is set
/// @exception throws std::invalid_argument exception if \a engine is null
/// @remarks friend of GG_Engine
GG_Renderer* const GG_GetRenderer(GG_Engine* const);

/// Gets the event handler that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-08
/// @date changed 2015-02-09
/// @param engine the engine to get the event handler from
/// @return the event handler, or null if no event handler is set
/// @exception throws std::invalid_argument exception if \a engine is null
/// @remarks friend of GG_Engine
std::unique_ptr<GG_Event> const& GG_GetEvent(GG_Engine* const);

/// Gets the texture manager that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param engine the engine to get the renderer engine from
/// @return the texture manager, or null if no texture manager is set
/// @exception throws std::invalid_argument exception if \a engine is null
/// @remarks friend of GG_Engine
GG_TextureManager* const GG_GetTextureManager(GG_Engine* const);

/// Initialized SDL
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param flags the flags used to initialize SDL
/// @exception init_error could not initialize SDL
void GG_InitializeSDL(const int);

/// Initialized SDL image
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param flags the flags used to initialize SDL image
/// @exception init_error could not initialize SDL image
void GG_InitializeSDLImage(const int);

/// Quits SDL
/// @author Alan Smithee
/// @date created 2015-02-07
void GG_QuitSDL();

/// Quits SDL
/// @author Alan Smithee
/// @date created 2015-02-07
void GG_QuitSDLImage();

#endif // ENGINE_CORE_CORE_H_INCLUDED
