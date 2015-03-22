#include "Element.h"

GG_GUI_Element::GG_GUI_Element() :
    GG_GUI_Element({ 0.0f, 0.0f }, 0.0f, 0.0f)
{
    // Empty
}

GG_GUI_Element::GG_GUI_Element(GG_Vec2f const& position,
                               float const width,
                               float const height) :
    position(position),
    width(width),
    height(height)
{
    // Empty
}

GG_GUI_Element::~GG_GUI_Element()
{
    for (auto child : _children)
    {
        if (child == nullptr)
        {
            continue;
        }

        delete child;
        child = nullptr;
    }
}

GG_Vec2f const& GG_GetPosition(GG_GUI_Element const& element)
{
    return element.position;
}

float const GG_GetWidth(GG_GUI_Element const& element)
{
    return element.width;
}

float const GG_GetHeight(GG_GUI_Element const& element)
{
    return element.height;
}

void GG_Render(GG_GUI_Element const& element, std::unique_ptr<GG_Renderer> const& renderer)
{
    GG_RenderRect(renderer,
                  {
                      GG_GetPosition(element).x,
                      GG_GetPosition(element).y,
                      GG_GetWidth(element),
                      GG_GetHeight(element)
                  });
}
