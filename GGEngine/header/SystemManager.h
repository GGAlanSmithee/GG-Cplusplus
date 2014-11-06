#ifndef SYSTEM_MANAGER_H_INCLUDED
#define SYSTEM_MANAGER_H_INCLUDED

#include <memory>

#include <SDL.h>

#include "EntityWorld.h"

namespace GGEngine
{
    namespace System
    {
        using Mask = std::bitset<Component::NumbTypes>;

        Mask MovementMask = GGUtility::ToIntegral(Component::Type::Displacement) |
                            GGUtility::ToIntegral(Component::Type::Velocity);

        Mask RenderMask = GGUtility::ToIntegral(Component::Type::Displacement) |
                          GGUtility::ToIntegral(Component::Type::Appearance);

        void RenderSystem  (Entity::World&, SDL_Renderer* const&);
        void MovementSystem(Entity::World&, const float);

        void OnEvent  (Entity::World&, SDL_Event* const&);
        void OnLogic  (Entity::World&, const float);
        void OnRender (Entity::World&, SDL_Renderer* const&);
    }
}

#endif // SYSTEM_MANAGER_H_INCLUDED
