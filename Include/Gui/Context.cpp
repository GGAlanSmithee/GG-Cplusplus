#include <stdexcept>
#include "Context.h"

GG_GUI_Context::GG_GUI_Context(GG_Rect const& boundary) :
    boundary(boundary)
{
    // Empty
}

GG_GUI_Context::~GG_GUI_Context()
{
    for (auto child : children)
    {
        if (child != nullptr)
        {
            delete child;
            child = nullptr;
        }
    }
}

float const GG_GetX(GG_GUI_Context *const context)
{
    return context == nullptr ? 0.0f : context->boundary.x;
}

float const GG_GetY(GG_GUI_Context *const context)
{
    return context == nullptr ? 0.0f : context->boundary.y;
}

float const GG_GetWidth(GG_GUI_Context *const context)
{
    return context == nullptr ? 0.0f : context->boundary.w;
}

float const GG_GetHeight(GG_GUI_Context *const context)
{
    return context == nullptr ? 0.0f : context->boundary.h;
}

void GG_AddChild(GG_GUI_Context * context, GG_GUI_Element *const child)
{
    if (context == nullptr || child == nullptr)
    {
        return;
    }

    context->children.push_back(child);

    GG_SetContext(child, context);
}

std::vector<GG_GUI_Element*> const& GG_GetChildren(GG_GUI_Context *const context)
{
    if (context == nullptr)
    {
        throw std::invalid_argument("context cannot be null.");
    }

    return context->children;
}

void GG_Render(GG_GUI_Context *const context, std::unique_ptr<GG_Renderer> const& renderer)
{
    if (context == nullptr)
    {
        return;
    }

    for (auto child : GG_GetChildren(context))
    {
        GG_Render(child, renderer);
    }
}
