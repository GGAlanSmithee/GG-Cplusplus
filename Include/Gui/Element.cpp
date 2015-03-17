#include "Element.h"

GG_GUI_Element::GG_GUI_Element() :
    GG_GUI_Element({ 0.0f, 0.0f, 0.0f, 0.0f })
{

}

GG_GUI_Element::GG_GUI_Element(GG_Rect const& rect) :
    _rect(rect)
{

}

GG_GUI_Element::~GG_GUI_Element()
{
    // Empty
}

void GG_Render(GG_GUI_Element const& element, std::unique_ptr<GG_Renderer> const& renderer)
{
    GG_RenderRect(renderer, element._rect);
}
