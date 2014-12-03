#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

namespace GGGame
{
    /// Represents a game instance and serves as the main starting point of any game using the GGEngine
    /// @author Alan Smithee
    /// @date created 2014-11-25
    /// @date changed 2014-12-03
    class Game
    {
        public:
            Game(World&);

        private:
            World _world;
    };
}

#endif // GAME_H_INCLUDED
