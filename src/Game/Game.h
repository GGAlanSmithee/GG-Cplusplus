#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Engine/Core/World.h"

namespace GGGame
{
    /// Represents a game instance and serves as the main starting point of any game using the GGEngine
    /// @author Alan Smithee
    /// @date created 2014-11-25
    /// @date changed 2014-12-03
    class Game
    {
        public:
            /// Default constructor for initializing a game instance
            /// @author Alan Smithee
            /// @date created 2014-11-25
            /// @param world the world holding enteties that live withing the scope of the whole game
            Game(GGCoreEngine::World&);

        private:
            GGCoreEngine::World _world;
    };
}

#endif // GAME_H_INCLUDED
