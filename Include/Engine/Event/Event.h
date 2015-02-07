#ifndef ENGINE_EVENT_EVENT_H_INCLUDED
#define ENGINE_EVENT_EVENT_H_INCLUDED

#include <SDL.h>
#include <unordered_map>
#include <functional>

class GG_Event
{
    public:
        friend GG_Event* const GG_CreateEvent();
        friend void GG_DestroyEvent(GG_Event* const);
        friend void GG_HandleEvents(GG_Event* const);
        friend void GG_RegisterKeyboardEvent(GG_Event* const, const SDL_Keycode, const std::function<void()>&);

    private:
        GG_Event() { };
        ~GG_Event() { };

        void HandleKeyDown(const SDL_Keycode);
        void HandleKeyUp(const SDL_Keycode);

        SDL_Event _event;

        std::unordered_map<SDL_Keycode, std::function<void()>> _keyDownCallbacks;
        std::unordered_map<SDL_Keycode, std::function<void()>> _keyUpCallbacks;
};

/// Creates an instance of the event engine
/// @author Alan Smithee
/// @date created 2015-02-01
/// @return a pointer to an event
/// @remarks friend of GG_Event
GG_Event* const GG_CreateEvent();

/// Destroys an instance of the event engine by freeing the memory used
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param event a pointer to the event to destroy
/// @remarks friend of GG_Event
void GG_DestroyEvent(GG_Event*);

/// Polls for events and dispatches them to registered callbacks (if any)
/// @author Alan Smithee
/// @date created 2014-12-08
/// @date changed 2015-02-01
/// @param event the event used to handle events
/// @remarks friend of GG_Event
void GG_HandleEvents(GG_Event* const);

/// Registers a callback to a keyboard event
/// @author Alan Smithee
/// @date created 2015-02-01
/// @param event the event used to handle events
/// @param keycode the keycode to bind the callback to
/// @param callback the callback to invoke when this event occours
/// @remarks friend of GG_Event
void GG_RegisterKeyboardEvent(GG_Event* const, const SDL_Keycode, const std::function<void()>&);

#endif // ENGINE_EVENT_EVENT_H_INCLUDED
