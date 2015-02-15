#ifndef UTILITY_FACTORY_H_INCLUDED
#define UTILITY_FACTORY_H_INCLUDED

#include <memory>
#include "Engine/Core.h"

class GG_Engine;
class GG_Factory
{
    public:
        std::unique_ptr<GG_Engine> GG_CreateEngine();
};

#endif // UTILITY_FACTORY_H_INCLUDED
