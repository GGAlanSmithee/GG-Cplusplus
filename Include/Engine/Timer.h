#ifndef ENGINE_TIMER_H_INCLUDED
#define ENGINE_TIMER_H_INCLUDED

#include <memory>

class GG_Timer
{
    public:
        GG_Timer();
        ~GG_Timer();

        friend const float GG_UpdateTimer(std::unique_ptr<GG_Timer> const&);
        friend const float GG_GetDelta(std::unique_ptr<GG_Timer> const&);

    private:
        float delta;
        float elapsed;
};

#endif // ENGINE_TIMER_H_INCLUDED
