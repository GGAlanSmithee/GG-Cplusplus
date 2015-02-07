#include <stdexcept>
#include "Event.h"

GG_Event* const GG_CreateEvent()
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

void GG_RegisterKeyboardEvent(GG_Event* const event,
                              const SDL_Keycode keycode,
                              const std::function<void()>& callback)
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

void GG_Event::HandleKeyDown(const SDL_Keycode keycode)
{
    if (_keyDownCallbacks.count(keycode) <= 0)
    {
        return;
    }

    _keyDownCallbacks.at(keycode)();
}

void GG_Event::HandleKeyUp(const SDL_Keycode keycode)
{
    if (_keyUpCallbacks.count(keycode) <= 0)
    {
        return;
    }

    _keyUpCallbacks.at(keycode)();
}

void GG_HandleEvents(GG_Event* const event)
{
    auto e = event->_event;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_KEYDOWN:
            {
                event->HandleKeyDown(e.key.keysym.sym);
                break;
            }
            case SDL_KEYUP:
            {
                event->HandleKeyUp(e.key.keysym.sym);
                break;
            }
            case SDL_QUIT:
            {
                // Empty
            }
        }
    }
}
