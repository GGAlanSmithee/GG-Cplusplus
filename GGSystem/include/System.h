#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <memory>
#include "GGEntity/include/Entity.h"
#include "GGCore/include/Core.h"

namespace GGSystem
{
    using Mask = std::bitset<GGCore::NumbComponentTypes>;

    Mask MovementMask = GGUtility::ToIntegral(GGComponent::Type::Model) |
                        GGUtility::ToIntegral(GGComponent::Type::Physics);

    Mask RenderMask = GGUtility::ToIntegral(GGComponent::Type::Model) |
                      GGUtility::ToIntegral(GGComponent::Type::Appearance);

    EXPORT void Movement(GGEntity::World&);
    EXPORT void Render  (GGEntity::World&);
}

#endif // SYSTEM_H_INCLUDED
