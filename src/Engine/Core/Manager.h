#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

namespace GGCore
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
            
            /// Is called every frame  from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-03
            virtual void OnUpdate();
            
            /// Is called at a fixed update rate from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-03
            virtual void OnFixedUpdate();
    }
}

#endif // MANAGER_H_INCLUDED