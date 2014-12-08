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
	/// @param event SDL event poller variable
	void OnKeyDown(const std::unique_ptr<GGCoreEngine::EventManager>&, SDL_Event&);
	
	/// Catches and dispatches all key down events
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on key down events
	/// @param event SDL event poller variable
	void OnKeyUp(const std::unique_ptr<GGCoreEngine::EventManager>&, SDL_Event&);
}

#endif // INPUT_H_INCLUDED
