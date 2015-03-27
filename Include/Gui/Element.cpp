#include <stdexcept>
#include "Element.h"

GG_GUI_Element::GG_GUI_Element(bool         const  isVisible,
                               GG_GUI_Style const  style,
                               GG_Rect      const& boundary,
                               GG_Color     const& color) :
    isVisible(isVisible),
    style(style),
    boundary(boundary),
    color(color)
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

GG_GUI_Context *const GG_GetContext(GG_GUI_Element *const element)
{
    return element == nullptr ? nullptr : element->context;
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

void GG_SetContext(GG_GUI_Element *const element, GG_GUI_Context *const context)
{
    if (element == nullptr || context == nullptr)
    {
        return;
    }

    element->context = context;
}

float const GG_GetX(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    auto parent = GG_GetParent(element);
    auto context = GG_GetContext(element);

    switch (element->style)
    {
        case GG_GUI_Style::Absolute:
        {
            return element->boundary.x + (parent == nullptr ? GG_GetX(context) : GG_GetX(parent));
        }
        case GG_GUI_Style::Relative:
        {
            auto offset = (parent == nullptr ? GG_GetX(context) : GG_GetX(parent));
            auto base = (parent == nullptr ? GG_GetWidth(context) : GG_GetWidth(parent));

            return offset + base * (element->boundary.x / 100.0f);
        }
    }
}

float const GG_GetY(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    auto parent = GG_GetParent(element);
    auto context = GG_GetContext(element);

    switch (element->style)
    {
        case GG_GUI_Style::Absolute:
        {
            return element->boundary.y + (parent == nullptr ? GG_GetY(context) : GG_GetY(parent));
        }
        case GG_GUI_Style::Relative:
        {
            auto offset = (parent == nullptr ? GG_GetY(context) : GG_GetY(parent));
            auto base = (parent == nullptr ? GG_GetHeight(context) : GG_GetHeight(parent));

            return offset + base * (element->boundary.y / 100.0f);
        }
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
        case GG_GUI_Style::Absolute: return element->boundary.w;
        case GG_GUI_Style::Relative:
        {
            auto parent = GG_GetParent(element);
            auto context = GG_GetContext(element);

            return (element->boundary.w / 100.0f) * (parent == nullptr ? GG_GetWidth(context) : GG_GetWidth(parent));
        }
    }
}

float const GG_GetHeight(GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return 0.0f;
    }

    switch (element->style)
    {
        case GG_GUI_Style::Absolute: return element->boundary.h;
        case GG_GUI_Style::Relative:
        {
            auto parent = GG_GetParent(element);
            auto context = GG_GetContext(element);

            return (element->boundary.h / 100.0f) * (parent == nullptr ? GG_GetHeight(context) : GG_GetHeight(parent));
        }
    }
}

GG_Color const& GG_GetColor (GG_GUI_Element *const element)
{
    if (element == nullptr)
    {
        return { 0, 0, 0, 0 };
    }

    return element->color;
}

bool const GG_IsVisible(GG_GUI_Element *const element)
{
    return element == nullptr ? false : element->isVisible;
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
        return;
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
                  },
                  GG_GetColor(element));
}
