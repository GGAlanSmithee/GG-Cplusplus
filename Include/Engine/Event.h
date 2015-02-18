#ifndef ENGINE_EVENT_H_INCLUDED
#define ENGINE_EVENT_H_INCLUDED

#include <SDL.h>
#include <unordered_map>
#include <functional>
#include <memory>

class GG_Event
{
    public:
        GG_Event();
        ~GG_Event();

        /// Polls for events and dispatches them to registered callbacks (if any)
        /// @author Alan Smithee
        /// @date created 2014-12-08
        /// @date changed 2015-02-01
        /// @param event the event used to handle events
        friend void GG_HandleEvents(std::unique_ptr<GG_Event> const&);

        /// Registers a callback to a keyboard event
        /// @author Alan Smithee
        /// @date created 2015-02-01
        /// @param event the event used to handle events
        /// @param keycode the keycode to bind the callback to
        /// @param callback the callback to invoke when this event occours
        friend void GG_RegisterKeyboardEvent(std::unique_ptr<GG_Event> const&,
                                             const SDL_Keycode,
                                             std::function<void()> const&);

    private:
        void HandleKeyDown(const SDL_Keycode);
        void HandleKeyUp(const SDL_Keycode);

        SDL_Event _event;

        std::unordered_map<SDL_Keycode, std::function<void()>> _keyDownCallbacks;
        std::unordered_map<SDL_Keycode, std::function<void()>> _keyUpCallbacks;
};

#endif // ENGINE_EVENT_H_INCLUDED
