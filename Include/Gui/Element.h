#ifndef GUI_ELEMENT_H_INCLUDED
#define GUI_ELEMENT_H_INCLUDED

#include <memory>
#include <vector>
#include "Math/Vec2.h"
#include "Math/Rect.h"
#include "Engine/Renderer.h"

enum class GG_GUI_Style
{
    None,
    Inherited,
    Relative,
    Absolute
};

class GG_GUI_Element
{
    public:
      GG_GUI_Element();
      GG_GUI_Element(GG_Rect const&);
      ~GG_GUI_Element();

      friend void GG_Render(GG_GUI_Element const&, std::unique_ptr<GG_Renderer> const&);

    private:
        GG_Rect _rect;

        struct Style
        {
            GG_GUI_Style position;
            GG_GUI_Style size;
        };

        GG_GUI_Element* _parent = nullptr;
        std::vector<GG_GUI_Element*> _children;
};

#endif // GUI_ELEMENT_H_INCLUDED
