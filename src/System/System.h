#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <memory>
#include "Entity/Entity.h"
#include "Core/Core.h"

namespace GGSystem
{
    using Mask = std::bitset<GGCore::NumbComponentTypes>;

    extern Mask MovementMask;
    extern Mask RenderMask;

    void Movement(GGEntity::World&);
    void Render  (GGEntity::World&);
}

#endif // SYSTEM_H_INCLUDED
