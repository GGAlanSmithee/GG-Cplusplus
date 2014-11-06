#include "render.h"

#include "Component.h"

namespace System
{
  Render::Render()
  {
    // Empty
  }

  Render::~Render()
  {
    // Empty
  }

  void Render::on_run(SDL_Renderer* const& renderer, Entity::World& world, const Game::Camera& camera) const
  {
    Component::Displacement* d;
    Component::Appearance*   a;

    for (unsigned int entity = 0; entity < world.size; ++entity)
    {
      if ((world.mask[entity] & _renderMask) == _renderMask)
      {
        d = &(world.displacement[entity]);
        a = &(world.appearance[entity]);

        Math::Vector2f viewPos = camera.to_view(d->value);

        SDL_Rect source = {
          a->clippingRect.x,
          a->clippingRect.y,
          a->clippingRect.w,
          a->clippingRect.h
        };

        SDL_Rect dest = {
          static_cast<int>(viewPos.x),
          static_cast<int>(viewPos.y),
          a->clippingRect.w,
          a->clippingRect.h
        };

        SDL_RenderCopy(renderer, world.texture[a->textureId], &source, &dest);
      }
    }
  }
}
