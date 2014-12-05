#include "Engine/Core/manager.h"

namespace GGCoreEngine
{
    Manager::Manager()
    {
        // Empty
    }

    Manager::~Manager()
    {
        // Pure virtual
    }

    void Manager::OnUpdate()
    {
        // Virtual
    }

    void Manager::OnFixedUpdate()
    {
        // Virtual
    }
    
    InputManager::InputManager()
    {
        //Empty
    }

    InputManager::~InputManager()
    {
        //Empty
    }
    
    void InputManager::OnUpdate()
    {
        //Empty
    }
    
    void InputManager::OnFixedUpdate()
    {
        //Empty
    }
}
