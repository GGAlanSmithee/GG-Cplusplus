#include "movement.h"

#include <iostream>

namespace System
{
  Movement::Movement()
  {
    // Empty
  }

  Movement::~Movement()
  {
    // Empty
  }

  void Movement::on_run(Entity::World& world, const float delta) const
  {
    Component::Displacement* d;
    Component::Velocity*     v;

    for (unsigned int entity = 0; entity < world.size; ++entity)
    {
      if ((world.mask[entity] & _movementMask) == _movementMask)
      {
        d = &(world.displacement[entity]);
        v = &(world.velocity[entity]);

        d->value.x += v->value.x * delta;
      }
    }
  }
}
