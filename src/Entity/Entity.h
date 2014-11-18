#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "World.h"
#include <memory>

namespace GGEntity
{
    const unsigned int CreateEntity (World&);
    void               DestroyEntity(World&, const unsigned int);
//                const unsigned int CreatePlayer (World&,
//                                                 const std::string&,
//                                                 const std::string&,
//                                                 const float,
//                                                 const float);
}


#endif // ENTITY_H_INCLUDED
