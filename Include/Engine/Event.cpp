#include <stdexcept>
#include <memory>
#include "Event.h"

GG_Event::GG_Event()
{
    /// @todo instantiate maps with all keycodes to avoid costly resizing operators during runtime
}

GG_Event::~GG_Event()
{
    for (auto& kvp : _keyDownCallbacks)
    {
        if (kvp.second != nullptr)
        {
            kvp.second = nullptr;
        }
    }

    _keyDownCallbacks.clear();
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

void GG_RegisterKeyDownEvent(std::unique_ptr<GG_Event> const& event,
                             const SDL_Keycode keycode,
                             std::function<void()> const& callback)
{
    if (!event)
    {
        throw std::invalid_argument("event cannot be null.");
    }

    if (callback == nullptr)
    {
        throw std::invalid_argument("callback cannot be null.");
    }

    event->_keyDownCallbacks[keycode] = callback;
}

void GG_RegisterMouseEvent(std::unique_ptr<GG_Event> const& event, std::function<void(int)> const& callback)
{
    if (!event)
    {
        throw std::invalid_argument("event cannot be null.");
    }

    if (callback == nullptr)
    {
        throw std::invalid_argument("callback cannot be null.");
    }

    event->_mouseEventCallback = callback;
}

void GG_UnregisterMouseEvent(std::unique_ptr<GG_Event> const& event)
{
    if (!event)
    {
        throw std::invalid_argument("event cannot be null.");
    }

    if (event->_mouseEventCallback == nullptr)
    {
        return;
    }

    event->_mouseEventCallback = nullptr;
}

void GG_HandleEvents(std::unique_ptr<GG_Event> const& event)
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
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            {
                if (event->_mouseEventCallback != nullptr)
                {
                    event->_mouseEventCallback(e.type);
                }

                break;
            }
            case SDL_QUIT:
            {
                // Empty
            }
        }
    }
}
