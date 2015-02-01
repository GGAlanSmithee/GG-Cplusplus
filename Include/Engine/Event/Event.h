#ifndef ENGINE_EVENT_EVENT_H_INCLUDED
#define ENGINE_EVENT_EVENT_H_INCLUDED

#include <SDL.h>
#include <unordered_map>
#include <functional>

namespace GGEventEngine
{
    class Instance
    {
        friend class InstanceAccessor;

        Instance() { };

        SDL_Event _event;

        std::unordered_map<SDL_Keycode, std::function<void()>> _keyDownCallbacks;
        std::unordered_map<SDL_Keycode, std::function<void()>> _keyUpCallbacks;
    };

    /// Creates an instance of the event engine
    /// @author Alan Smithee
    /// @date created 2015-02-01
    /// @return a pointer to a instance object
    Instance* Create();

    /// Destroys an instance by freeing the memory used
    /// @author Alan Smithee
    /// @date created 2015-02-01
    /// @param a pointer to the instance to destroy
    void Destroy(Instance*);

	/// Polls for events and dispatches them to registered callbacks (if any)
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @date changed 2015-02-01
	/// @param instance the event engine instance used to handle events
	void HandleEvents(Instance* instance);

	/// Registers a callback to a keyboard event
	/// @author Alan Smithee
	/// @date created 2015-02-01
	/// @param instance the event engine instance used to handle events
	/// @param keycode the keycode to bind the callback to
	/// @param callback the callback to invoke when this event occours
	void RegisterCallbackToKeyboardEvent(Instance*, const SDL_Keycode, std::function<void()>);
}

#endif // ENGINE_EVENT_EVENT_H_INCLUDED
