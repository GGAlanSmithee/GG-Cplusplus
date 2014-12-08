#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <SDL.h>
#include <memory>

namespace GGInputEngine
{
	/// Polls for events and dispatches them to an event manager
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on each event
	/// @param event SDL event poller variable
	void HandleEvents(const std::unique_ptr<GGCoreEngine::EventManager>&, SDL_Event&);
	
	/// Catches and dispatches all key down events
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on key down events
	/// @param keycode the key that was pressed
	void OnKeyDown(const std::unique_ptr<GGCoreEngine::EventManager>&, const SDL_Keycode);
	
	/// Catches and dispatches all key up events
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on key down events
	/// @param keycode the key that was released
	void OnKeyUp(const std::unique_ptr<GGCoreEngine::EventManager>&, const SDL_Keycode);
}

#endif // INPUT_H_INCLUDED
