#include "Application.h"

GG_Application::GG_Application(std::shared_ptr<GG_ApplicationData> data) :
    data(data)
{
    // Empty
}

GG_Application::~GG_Application()
{
    // Empty, virtual
}

void GG_Application::OnLogic(std::unique_ptr<GG_Engine> const&)
{
    // Empty, virtual
}

void GG_Application::OnRender(std::unique_ptr<GG_Engine> const&)
{
    // Empty, virtual
}
