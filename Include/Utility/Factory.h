#ifndef UTILITY_FACTORY_H_INCLUDED
#define UTILITY_FACTORY_H_INCLUDED

#include <memory>
#include "Engine/Core.h"
#include "Application/Application.h"

std::unique_ptr<GG_Engine> GG_CreateEngine();
std::unique_ptr<GG_Application> GG_CreateApplication();

#endif // UTILITY_FACTORY_H_INCLUDED
