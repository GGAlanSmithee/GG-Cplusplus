#ifndef ENGINE_CORE_CORE_H_INCLUDED
#define ENGINE_CORE_CORE_H_INCLUDED

#include "Application/Application.h"

class GG_Engine
{
    public:
        friend GG_Engine* const GG_CreateEngine(const std::string&,
                                                const unsigned int,
                                                const unsigned int,
                                                const unsigned int,
                                                const unsigned int,
                                                const unsigned int);
        friend void GG_DestroyEngine(GG_Engine*);
        friend SDL_Window* const GG_GetWindow(GG_Engine* const);

    private:
        GG_Engine() { };
        ~GG_Engine() { };

        SDL_Window* _window;
};

/// Creates an instance of the core engine
/// @author Alan Smithee
/// @date created 2015-02-07
/// @return a pointer to a newly created engine
/// @param title the title of the window
/// @param x the x position of the window
/// @param y the y position of the window
/// @param w the widht of the window
/// @param h the height of the window
/// @param flags flags to use when creating the SDL_Window*
/// @remarks friend of GG_Engine
GG_Engine* const GG_CreateEngine(const std::string&,
                                 const unsigned int,
                                 const unsigned int,
                                 const unsigned int,
                                 const unsigned int,
                                 const unsigned int);

/// Destroys an instance of the core engine by freeing the memory used
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param event a pointer to the event to destroy
/// @remarks friend of GG_Engine
void GG_DestroyEngine(GG_Engine*);

/// Gets the window that the engine is currently using
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param engine the engine to get the window from
/// @return the window, or null if no window is set
/// @remarks friend of GG_Engine
SDL_Window* const GG_GetWindow(GG_Engine* const);

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

/// Executes the core engine
/// @author Alan Smithee
/// @date created 2014-12-03
/// @date changed 2015-02-07
/// @param engine the engine to execute
/// @remarks runs the main loop by using other engine's functionality
const int GG_Execute(GG_Engine* const);

#endif // ENGINE_CORE_CORE_H_INCLUDED
