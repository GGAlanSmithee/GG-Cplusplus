#ifndef UTILITY_FACTORY_H_INCLUDED
#define UTILITY_FACTORY_H_INCLUDED

#include <memory>
#include "Engine/Core.h"

std::unique_ptr<GG_Engine> GG_CreateEngine();

#endif // UTILITY_FACTORY_H_INCLUDED
