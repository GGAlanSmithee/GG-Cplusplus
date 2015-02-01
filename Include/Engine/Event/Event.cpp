#include "Event.h"

// Instance accessor
namespace GGEventEngine
{
    class InstanceAccessor
    {
        public:
            static Instance* Create();
            static void Destroy(Instance*);
            static SDL_Event& GetEvent(Instance*);
            static void RegisterCallbackToKeyboardEvent(Instance*, SDL_Keycode, std::function<void()>);
            static void HandleKeyDown(Instance*, const SDL_Keycode&);
            static void HandleKeyUp(Instance*, const SDL_Keycode&);
    };

    Instance* InstanceAccessor::Create()
    {
        /// @todo instantiate maps with all keycodes to avoid costly operators during runtime

        return new Instance();
    }

    void InstanceAccessor::Destroy(Instance* instance)
    {
        if (instance == nullptr)
        {
            return;
        }

        for (auto& kvp: instance->_keyDownCallbacks)
        {
            if (kvp.second != nullptr)
            {
                kvp.second = nullptr;
            }
        }

        instance->_keyDownCallbacks.clear();

        delete instance;
        instance = nullptr;
    }

    SDL_Event& InstanceAccessor::GetEvent(Instance* instance)
    {
        return instance->_event;
    }

    void InstanceAccessor::RegisterCallbackToKeyboardEvent(Instance* instance,
                                                           SDL_Keycode keycode,
                                                           std::function<void()> callback)
    {
        instance->_keyDownCallbacks[keycode] = callback;
    }

    void InstanceAccessor::HandleKeyDown(Instance* instance, const SDL_Keycode& keycode)
    {
        auto callback = instance->_keyDownCallbacks[keycode];

        if (callback == nullptr)
        {
            return;
        }

        callback();
    }

	void InstanceAccessor::HandleKeyUp(Instance* instance, const SDL_Keycode& keycode)
    {
        auto callback = instance->_keyUpCallbacks[keycode];

        if (callback == nullptr)
        {
            return;
        }

        callback();
    }
}

// Public interface
namespace GGEventEngine
{
    Instance* Create()
    {
        return InstanceAccessor::Create();
    }

    void Destroy(Instance* instance)
    {
        InstanceAccessor::Destroy(instance);
    }

	void HandleEvents(Instance* instance)
    {
        auto event = InstanceAccessor::GetEvent(instance);

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                {
                    InstanceAccessor::HandleKeyDown(instance, event.key.keysym.sym);
                    break;
                }
                case SDL_KEYUP:
                {
                    InstanceAccessor::HandleKeyUp(instance, event.key.keysym.sym);
                    break;
                }
                case SDL_QUIT:
                {
                    // Empty
                }
            }
        }
    }

	void RegisterCallbackToKeyboardEvent(Instance* instance,
                                         const SDL_Keycode keycode,
                                         std::function<void()> callback)
    {
        if (instance == nullptr || callback == nullptr)
        {
            return;
        }

        InstanceAccessor::RegisterCallbackToKeyboardEvent(instance, keycode, callback);
    }
}
