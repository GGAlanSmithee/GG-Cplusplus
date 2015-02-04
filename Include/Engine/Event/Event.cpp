#include <stdexcept>
#include "Event.h"

GG_Event* GG_CreateEvent()
{
    /// @todo instantiate maps with all keycodes to avoid costly resizing operators during runtime

    return new GG_Event();
}

void GG_DestroyEvent(GG_Event* event)
{
    if (event == nullptr)
    {
        return;
    }

    for (auto& kvp : event->_keyDownCallbacks)
    {
        if (kvp.second != nullptr)
        {
            kvp.second = nullptr;
        }
    }

    event->_keyDownCallbacks.clear();

    delete event;
    event = nullptr;
}

void GG_RegisterCallbackToKeyboardEvent(GG_Event* event, const SDL_Keycode keycode, std::function<void()> callback)
{
    if (event == nullptr)
    {
        throw std::invalid_argument("event cannot be null.");
    }
    
    if (callback == nullptr)
    {
        throw std::invalid_argument("callback cannot be null.");
    }
    
    event->_keyDownCallbacks[keycode] = callback;
}

void GG_HandleKeyDown(GG_Event* event, const SDL_Keycode keycode)
{
    if (event->_keyDownCallbacks.count(keycode) <= 0)
    {
        return;
    }

    event->_keyDownCallbacks.at(keycode)();
}

void GG_HandleKeyUp(GG_Event* event, const SDL_Keycode keycode)
{
    if (event->_keyUpCallbacks.count(keycode) <= 0)
    {
        return;
    }

    event->_keyUpCallbacks.at(keycode)();
}

void GG_HandleEvents(GG_Event* event)
{
    auto e = event->_event;
    
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_KEYDOWN:
            {
                HandleKeyDown(event, e.key.keysym.sym);
                break;
            }
            case SDL_KEYUP:
            {
                HandleKeyUp(event, e.key.keysym.sym);
                break;
            }
            case SDL_QUIT:
            {
                // Empty
            }
        }
    }
}