#ifndef ENTITY_MANAGER_H_INCLUDED
#define ENTITY_MANAGER_H_INCLUDED

#include <memory>
#include <SDL.h>
#include "EntityWorld.h"

namespace GGEngine
{
    namespace Entity
    {
        class Manager
        {
            public:
                Manager();
                ~Manager();

                const unsigned int CreateEntity (World&);
                void               DestroyEntity(World&, const unsigned int);
                const unsigned int CreatePlayer (World&,
                                                 const std::string&,
                                                 const std::string&,
                                                 const float,
                                                 const float);
        };
    }
}

#endif // ENTITY_MANAGER_H_INCLUDED
