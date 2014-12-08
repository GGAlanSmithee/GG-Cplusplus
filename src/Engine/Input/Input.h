#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <SDL.h>
#include <memory>

namespace GGInputEngine
{
	/// Listens to and polls events
	/// @author Alan Smithee
	/// @date created 2014-12-08
	extern SDL_Event* event;
	
	/// Polls for events and dispatches them to an event manager
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on each event
	void HandleEvents(const std::unique_ptr<GGCoreEngine::EventManager>&);
	
	/// Catches and dispatches all key down events
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on key down events
	void OnKeyDown(const std::unique_ptr<GGCoreEngine::EventManager>&);
	
	/// Catches and dispatches all key down events
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on key down events
	void OnKeyUp(const std::unique_ptr<GGCoreEngine::EventManager>&);
}

#endif // INPUT_H_INCLUDED
