#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <memory>

namespace GGInputEngine
{
	/// Polls for events and dispatches them to an event manager
	/// @author Alan Smithee
	/// @date created 2014-12-08
	/// @param eventMananger user defined event manager to be invoked on each event
	void HandleEvents(const std::unique_ptr<GGCoreEngine::EventManager>);
}

#endif // INPUT_H_INCLUDED
