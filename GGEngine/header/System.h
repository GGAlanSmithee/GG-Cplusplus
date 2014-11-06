#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <bitset>

#include "EntityWorld.h"
#include "Component.h"

namespace GGEngine
{
    namespace System
    {
        std::bitset<Component::total_numb> MovementMask = (GGUtility::ToIntegral(Component::Type::Displacement) |
                                                           GGUtility::ToIntegral(Component::Type::Velocity));

        void Movement(Entity::World&, const float) const;

    private:
      std::bitset<Component::total_numb> _movementMask = (
        Utility::to_integral(Component::Type::displacement) |
        Utility::to_integral(Component::Type::velocity)
      );
    };
}

#endif // SYSTEM_H_INCLUDED
