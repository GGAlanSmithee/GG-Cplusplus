#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

namespace GGCoreEngine
{
    /// Abstract baseclass for managers. A manager is a class that provides logic which affects some part of the game that isn't component specific
    /// @author Alan Smithee
    /// @date created 2014-12-03
    class Manager
    {
        public:
            /// Initializes the manager
            /// @author Alan Smithee
            /// @date created 2014-12-03
            Manager();

            /// Virtual destructor for inheritance purposes
            /// @author Alan Smithee
            /// @date created 2014-12-03
            virtual ~Manager() = 0;

            /// Is called every frame from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-03
            virtual void OnUpdate();

            /// Is called at a fixed update rate from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-03
            virtual void OnFixedUpdate();
    };
    
    /// Manages input for the game using this manager
    /// @author Alan Smithee
    /// @date created 2014-12-05
    /// @todo flesh out exactly how this should interact with event engine and physics engine with clicking enteties, doing raycasts etc
    class InputManager : Manager
    {
        public:
            /// Initializes the input manager
            /// @author Alan Smithee
            /// @date created 2014-12-05
            InputManager();

            /// Cleans up the input manager
            /// @author Alan Smithee
            /// @date created 2014-12-05
            virtual ~InputManager() override;

            /// Is called every frame from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-05
            virtual void OnUpdate() override;

            /// Is called at a fixed update rate from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-05
            virtual void OnFixedUpdate() override;
    };
}

#endif // MANAGER_H_INCLUDED
