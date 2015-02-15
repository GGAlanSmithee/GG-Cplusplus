#ifndef APPLICATION_APPLICATION_H_INCLUDED
#define APPLICATION_APPLICATION_H_INCLUDED

#include "Engine/Core/Core.h"

class GG_Application
{
    public:
        friend GG_Application* const GG_CreateApplication();
        friend void GG_DestroyApplication(GG_Application*);

        friend void GG_OnEvent(GG_Application* const, std::unique_ptr<GG_Engine> const&);
        friend void GG_OnLogic(GG_Application* const, std::unique_ptr<GG_Engine> const&);
        friend void GG_OnRender(GG_Application* const, std::unique_ptr<GG_Engine> const&);

    private:

        GG_Application();
        ~GG_Application();
};

/// Creates a GG_Application* instance
/// @author Alan Smithee
/// @date created 2015-02-10
/// @date changed 2015-02-11
/// @return a GG_Application* instance
/// @remarks friend of GG_Application
GG_Application* const GG_CreateApplication();

/// Destroys a GG_Application* instance
/// @author Alan Smithee
/// @date created 2015-02-10
/// @param application the GG_Application to destroy
/// @remarks friend of GG_Application
void GG_DestroyApplication(GG_Application*);

/// Executes the event related systems of the \a application
/// @author Alan Smithee
/// @date created 2015-02-10
/// @param application the GG_Application* to invoke the systems on
/// @param engine the GG_Engine* to use to when invoking the systems
/// @exception throws a std::invalid_argument if \a application is null
/// @exception throws a std::invalid_argument if \a engine is null
/// @remarks friend of GG_Application
void GG_OnEvent(GG_Application* const, std::unique_ptr<GG_Engine> const&);

/// Executes the logic related systems of the \a application
/// @author Alan Smithee
/// @date created 2015-02-10
/// @param application the GG_Application* to invoke the systems on
/// @param engine the GG_Engine* to use to when invoking the systems
/// @exception throws a std::invalid_argument if \a application is null
/// @exception throws a std::invalid_argument if \a engine is null
/// @remarks friend of GG_Application
void GG_OnLogic(GG_Application* const, std::unique_ptr<GG_Engine> const&);

/// Executes the rendering related systems of the \a application
/// @author Alan Smithee
/// @date created 2015-02-10
/// @param application the GG_Application* to invoke the systems on
/// @param engine the GG_Engine* to use to when invoking the systems
/// @exception throws a std::invalid_argument if \a application is null
/// @exception throws a std::invalid_argument if \a engine is null
/// @remarks friend of GG_Application
void GG_OnRender(GG_Application* const, std::unique_ptr<GG_Engine> const&);

#endif // APPLICATION_H_INCLUDED
