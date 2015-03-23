#include "Element.h"
#include <stdexcept>

GG_GUI_Element::GG_GUI_Element() :
    GG_GUI_Element({ 0.0f, 0.0f, 0.0f, 0.0f }, GG_GUI_Style::Absolute, true)
{
    // Empty
}

GG_GUI_Element::GG_GUI_Element(GG_Rect const& rect, GG_GUI_Style const style, bool const isVisible) :
    rect(rect),
    style(style),
    isVisible(isVisible)
{
    // Empty
}

GG_GUI_Element::~GG_GUI_Element()
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

GG_GUI_Element *const GG_GetParent(GG_GUI_Element *const element)
{
    return element == nullptr ? nullptr : element->parent;
}

void GG_AddChild(GG_GUI_Element *const element, GG_GUI_Element *const child)
{
    if (element == nullptr || child == nullptr)
    {
        return;
    }

    element->children.push_back(child);
    child->parent = element;
}

/// @todo bad logic: GetX relative must calculate parent with - parent x
float const GG_GetX(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    switch (element->style)
    {
        case GG_GUI_Style::Absolute: return element->rect.x;
        case GG_GUI_Style::Relative: return GG_GetX(GG_GetParent(element)) * (element->rect.x / 100.0f);
    }
}

/// @todo bad logic: GetY relative must calculate parent with - parent x
float const GG_GetY(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    switch (element->style)
    {
        case GG_GUI_Style::Absolute: return element->rect.y;
        case GG_GUI_Style::Relative: return GG_GetY(GG_GetParent(element)) * (element->rect.y / 100.0f);
    }
}

float const GG_GetWidth(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    switch (element->style)
    {
        case GG_GUI_Style::Absolute: return element->rect.w;
        case GG_GUI_Style::Relative: return GG_GetWidth(GG_GetParent(element)) * (element->rect.w / 100.0f);
    }
}

bool const GG_IsVisible(GG_GUI_Element *const element)
{
    return element == nullptr ? false : element->isVisible;
}

float const GG_GetHeight(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    switch (element->style)
    {
        case GG_GUI_Style::Absolute: return element->rect.h;
        case GG_GUI_Style::Relative: return GG_GetHeight(GG_GetParent(element)) * (element->rect.h / 100.0f);
    }
}

std::vector<GG_GUI_Element*> const& GG_GetChildren(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        throw std::invalid_argument("element cannot be null.");
    }

    return element->children;
}

void GG_Render(GG_GUI_Element *const element, std::unique_ptr<GG_Renderer> const& renderer)
{
    if (element == nullptr)
    {
        throw std::invalid_argument("element cannot be null.");
    }

    for (auto child : GG_GetChildren(element))
    {
        GG_Render(child, renderer);
    }

    if (!GG_IsVisible(element))
    {
        return;
    }

    GG_RenderRect(renderer,
                  {
                      GG_GetX(element),
                      GG_GetY(element),
                      GG_GetWidth(element),
                      GG_GetHeight(element)
                  });
}
