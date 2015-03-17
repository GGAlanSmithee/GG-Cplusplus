#include "Element.h"

GG_GUI_Element::GG_GUI_Element() :
    GG_GUI_Element({ 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f })
{

}

GG_GUI_Element::GG_GUI_Element(GG_Rect const& dimensions, GG_Vec2f const& centerPosition) :
    _dimensions(dimensions),
    _centerPosition(centerPosition)
{

}

GG_GUI_Element::~GG_GUI_Element()
{
    // Empty
}
