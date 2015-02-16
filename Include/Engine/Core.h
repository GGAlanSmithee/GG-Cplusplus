#ifndef ENGINE_CORE_H_INCLUDED
#define ENGINE_CORE_H_INCLUDED

#include "Engine/Renderer.h"
#include "Engine/Event.h"
#include "Manager/Texture.h"

class GG_Engine
{
    public:
        GG_Engine(SDL_Window*,
                  std::unique_ptr<GG_Renderer>,
                  std::unique_ptr<GG_Event>,
                  std::unique_ptr<GG_TextureManager>);
        ~GG_Engine();

        friend std::unique_ptr<GG_Renderer> const& GG_GetRenderer(std::unique_ptr<GG_Engine> const&);
        friend std::unique_ptr<GG_Event> const& GG_GetEvent(std::unique_ptr<GG_Engine> const&);
        friend std::unique_ptr<GG_TextureManager> const& GG_GetTextureManager(std::unique_ptr<GG_Engine> const&);

    private:
        SDL_Window*                        _window;
        std::unique_ptr<GG_Renderer>       _renderer;
        std::unique_ptr<GG_Event>          _event;
        std::unique_ptr<GG_TextureManager> _textureManager;
};

/// Gets the renderer engine that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param engine the engine to get the renderer engine from
/// @return the renderer engine, or null if no renderer engine is set
/// @exception throws std::invalid_argument exception if \a engine is null
/// @remarks friend of GG_Engine
std::unique_ptr<GG_Renderer> const& GG_GetRenderer(std::unique_ptr<GG_Engine> const&);

/// Gets the event handler that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-08
/// @date changed 2015-02-09
/// @param engine the engine to get the event handler from
/// @return the event handler, or null if no event handler is set
/// @exception throws std::invalid_argument exception if \a engine is null
/// @remarks friend of GG_Engine
std::unique_ptr<GG_Event> const& GG_GetEvent(std::unique_ptr<GG_Engine> const&);

/// Gets the texture manager that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param engine the engine to get the renderer engine from
/// @return the texture manager, or null if no texture manager is set
/// @exception throws std::invalid_argument exception if \a engine is null
/// @remarks friend of GG_Engine
std::unique_ptr<GG_TextureManager> const& GG_GetTextureManager(std::unique_ptr<GG_Engine> const&);

#endif // ENGINE_CORE_H_INCLUDED
