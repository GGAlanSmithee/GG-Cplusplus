#include "Element.h"

GG_GUI_Element::GG_GUI_Element() :
    GG_GUI_Element({ 0.0f, 0.0f, 0.0f, 0.0f })
{
    // Empty
}

GG_GUI_Element::GG_GUI_Element(GG_Rect const& rect) :
    _rect(rect)
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

void GG_Render(GG_GUI_Element const& element, std::unique_ptr<GG_Renderer> const& renderer)
{
    GG_RenderRect(renderer, element._rect);
}
