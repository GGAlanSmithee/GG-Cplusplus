#ifndef ENGINE_EVENT_EVENT_H_INCLUDED
#define ENGINE_EVENT_EVENT_H_INCLUDED

#include <SDL.h>
#include <unordered_map>
#include <functional>


class GG_Event
{
    public:
        /// Creates an instance of the event engine
        /// @author Alan Smithee
        /// @date created 2015-02-01
        /// @return a pointer to an event
        friend GG_Event* Create();

        /// Destroys an instance by freeing the memory used
        /// @author Alan Smithee
        /// @date created 2015-02-01
        /// @param event a pointer to the event to destroy
        friend void Destroy(GG_Event*);

        /// Polls for events and dispatches them to registered callbacks (if any)
        /// @author Alan Smithee
        /// @date created 2014-12-08
        /// @date changed 2015-02-01
        /// @param event the event used to handle events
        friend void HandleEvents(GG_Event*);

        /// Registers a callback to a keyboard event
        /// @author Alan Smithee
        /// @date created 2015-02-01
        /// @param event the event used to handle events
        /// @param keycode the keycode to bind the callback to
        /// @param callback the callback to invoke when this event occours
        friend void RegisterKeyboardEvent(GG_Event*, const SDL_Keycode, std::function<void()>);
            
        friend const SDL_Event GetEvent(GG_Event*);
            
    private:
        GG_Event() { };
        ~GG_Event() { };
            
        void HandleKeyDown(GG_Event*, const SDL_Keycode);
        void HandleKeyUp(GG_Event*, const SDL_Keycode);
            
        SDL_Event _event;

        std::unordered_map<SDL_Keycode, std::function<void()>> _keyDownCallbacks;
        std::unordered_map<SDL_Keycode, std::function<void()>> _keyUpCallbacks;
};

#endif // ENGINE_EVENT_EVENT_H_INCLUDED
