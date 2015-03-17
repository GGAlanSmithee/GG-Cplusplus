#ifndef GUI_ELEMENT_H_INCLUDED
#define GUI_ELEMENT_H_INCLUDED

#include "Math/Vec2.h"
#include "Math/Rect.h"

class GG_GUI_Element
{
    public:
      GG_GUI_Element();
      GG_GUI_Element(GG_Rect const&, GG_Vec2f const&);
      ~GG_GUI_Element();

    private:
        GG_Rect  _dimensions;
        GG_Vec2f _centerPosition;
};

#endif // GUI_ELEMENT_H_INCLUDED
