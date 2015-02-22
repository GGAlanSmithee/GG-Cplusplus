#include <stdexcept>
#include <SDL.h>
#include "Timer.h"

GG_Timer::GG_Timer()
{
    elapsed = SDL_GetTicks();
}

GG_Timer::~GG_Timer()
{
    // Empty
}

const float GG_UpdateTimer(std::unique_ptr<GG_Timer> const& timer)
{
    if (!timer)
    {
        throw std::invalid_argument("timer cannot be null.");
    }

    timer->delta = SDL_GetTicks() - timer->elapsed;
    timer->elapsed = SDL_GetTicks();
}

const float GG_GetDelta(std::unique_ptr<GG_Timer> const& timer)
{
    if (!timer)
    {
        throw std::invalid_argument("timer cannot be null.");
    }

    return timer->delta / 1000;
}
