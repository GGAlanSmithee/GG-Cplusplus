#include "SystemManager.h"

namespace GGEngine
{
    namespace System
    {
        void RenderSystem(Entity::World& world, SDL_Renderer* const& renderer)
        {
            Component::Displacement* d;
            Component::Appearance*   a;

            for (auto entity = 0; entity < world.Size; ++entity)
            {
                if ((world.Enteties[entity] & RenderMask) != RenderMask)
                {
                    return;
                }

                d = &(world.Displacement[entity]);
                a = &(world.Appearance[entity]);

//                Math::Vector2f viewPos = camera.to_view(d->value);
//
//                SDL_Rect source = {
//                  a->clippingRect.x,
//                  a->clippingRect.y,
//                  a->clippingRect.w,
//                  a->clippingRect.h
//                };
//
//                SDL_Rect dest = {
//                  static_cast<int>(viewPos.x),
//                  static_cast<int>(viewPos.y),
//                  a->clippingRect.w,
//                  a->clippingRect.h
//                };
//
//                SDL_RenderCopy(renderer, world.texture[a->textureId], &source, &dest);
            }
        }

        void MovementSystem(Entity::World& world, const float delta)
        {
            Component::Displacement* d;
            Component::Velocity*     v;

            for (auto entity = 0; entity < world.Size; ++entity)
            {
                if ((world.Enteties[entity] & MovementMask) != MovementMask)
                {
                    return;
                }

                d = &(world.Displacement[entity]);
                v = &(world.Velocity[entity]);

//                d->Value.x += v->Value.x * delta;
            }
        }

        void OnEvent  (Entity::World& world, SDL_Event* const& event)
        {
            // Event
        }

        void OnLogic  (Entity::World& world, const float delta)
        {
            MovementSystem(world, delta);
        }

        void OnRender (Entity::World& world, SDL_Renderer* const& renderer)
        {
            RenderSystem(world, renderer);
        }
    }
}
