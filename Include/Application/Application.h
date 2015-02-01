#ifndef APPLICATION_APPLICATION_H_INCLUDED
#define APPLICATION_APPLICATION_H_INCLUDED

#include <memory>
#include <vector>
#include "Engine/Core/World.h"
#include "Engine/Core/Manager.h"

namespace GGApplication
{
    /// Represents an editor instance and serves as the main starting point of any editor using the GGEngine
    /// @author Alan Smithee
    /// @date created 2015-02-01
    class Editor
    {
        public:
            /// Default constructor for initializing an editor instance
            /// @author Alan Smithee
            /// @date created 2015-02-01
            /// @param world the world holding enteties that live withing the scope of the editor
            Editor(GGCoreEngine::World&);

            /// Gets the editors world
            /// @author Alan Smithee
            /// @date created 2014-11-25
            /// @return the editors world
            const GGCoreEngine::World GetWorld() const;

        private:
            GGCoreEngine::World _world;
            std::vector<std::unique_ptr<GGCoreEngine::Manager>> _managers;
    };

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
            /// @param world the world holding enteties that live withing the scope of the game
            Game(GGCoreEngine::World&);

            /// Gets the games world
            /// @author Alan Smithee
            /// @date created 2014-11-25
            /// @return the games world
            const GGCoreEngine::World GetWorld() const;

        private:
            GGCoreEngine::World _world;
            std::vector<std::unique_ptr<GGCoreEngine::Manager>> _managers;
    };
}

#endif // APPLICATION_APPLICATION_H_INCLUDED
