#ifndef RENDER_SYSTEM_H_INCLUDED
#define RENDER_SYSTEM_H_INCLUDED

#include <bitset>
#include <SDL.h>
#include "Utility.h"


namespace System
{
  class Render
  {
    public:
      Render();
      ~Render();

      void on_run(SDL_Renderer* const&, Entity::World&, const Game::Camera&) const;

    private:
      std::bitset<Component::total_numb> _renderMask = (
        Utility::to_integral(Component::Type::displacement) |
        Utility::to_integral(Component::Type::appearance)
      );
  };
}

#endif // RENDER_SYSTEM_H_INCLUDED
