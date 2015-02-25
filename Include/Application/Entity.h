#ifndef APPLICATION_ENTITY_H_INCLUDED
#define APPLICATION_ENTITY_H_INCLUDED

#include <bitset>
#include <memory>
#include <vector>
#include "Component.h"
#include "Utility/Utility.h"

class GG_EntityManager
{
    public:
        /// Initializes a world object
        /// @author Alan Smithee
        /// @date created 2014-11-28
        /// @date changed 2014-12-21
        /// @param size the inital size of the world
        GG_EntityManager(const unsigned int = 2000);

        /// Creates an entity by assigning it a mask and returning its id
        /// @author Alan Smithee
        /// @date created 2014-11-25
        /// @date changed 2015-02-17
        friend const unsigned int GG_CreateEntity(GG_EntityManager&);

        /// Destroys an entity by assigning it an empty mask (ComponentType::None)
        /// @author Alan Smithee
        /// @date created 2014-11-25
        /// @date changed 2015-02-17
        friend void GG_DestroyEntity(GG_EntityManager&, const unsigned int);

        /// Worldsize
        /// @author Alan Smithee
        /// @date created 2014-11-28
        unsigned int Size;

        /// List of enteties
        /// @author Alan Smithee
        /// @date created 2014-11-28
        /// @remarks an entity is idetified with a mask that specifies what components the entety is made up of
        std::vector<std::bitset<GG_ComponentType::Total>> Enteties;

        /// List of appearance components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<GG_AppearanceComponent> AppearanceComponents;

        /// List of physics components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<GG_PhysicsComponent> PhysicsComponents;

        /// List of transform components
        /// @author Alan Smithee
        /// @date created 2014-11-28
        std::vector<GG_TransformComponent> TransformComponents;

    private:
        int maxEntityAlive;
};

const unsigned int GG_CreateCamera(GG_EntityManager&, SDL_Rect const&);

#endif // APPLICATION_ENTITY_H_INCLUDED
