#ifndef APPLICATION_APPLICATION_H_INCLUDED
#define APPLICATION_APPLICATION_H_INCLUDED

#include <memory>
#include "Engine/Core.h"
#include "Entity.h"
#include "map.h"

class GG_Application
{
    public:
        GG_Application();
        ~GG_Application();

        friend GG_Map const& GG_GetMap(std::unique_ptr<GG_Application> const&);

        /// Executes the logic related systems of the \a application
        /// @author Alan Smithee
        /// @date created 2015-02-10
        /// @date changed 2015-02-16
        /// @param application the GG_Application to invoke the systems on
        /// @param engine the GG_Engine used by the applications systems
        /// @exception throws a std::invalid_argument if \a application is null
        /// @exception throws a std::invalid_argument if \a engine is null
        friend void GG_OnLogic(std::unique_ptr<GG_Application> const&, std::unique_ptr<GG_Engine> const&);

        /// Executes the rendering related systems of the \a application
        /// @author Alan Smithee
        /// @date created 2015-02-10
        /// @date changed 2015-02-16
        /// @param application the GG_Application to invoke the systems on
        /// @param engine the GG_Engine used by the applications systems
        /// @exception throws a std::invalid_argument if \a application is null
        /// @exception throws a std::invalid_argument if \a engine is null
        friend void GG_OnRender(std::unique_ptr<GG_Application> const&, std::unique_ptr<GG_Engine> const&);

    private:
        GG_EntityManager entityManager;
        GG_Map           map;
};

#endif // APPLICATION_H_INCLUDED
