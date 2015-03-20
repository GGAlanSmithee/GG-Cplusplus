#ifndef GUI_ELEMENT_H_INCLUDED
#define GUI_ELEMENT_H_INCLUDED

#include <memory>
#include <vector>
#include <unordered_map>
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
        friend void GG_AddStyle(GG_GUI_Element const&, std::string const&, GG_GUI_Style const&);
        friend void GG_RemoveStyle(GG_GUI_Element const&, std::string const&);
        
    private:
        GG_Rect _rect;

        std::unordered_map<std::string, GG_GUI_Style> _styles;

        GG_GUI_Element* _parent = nullptr;
        std::vector<GG_GUI_Element*> _children;
};

#endif // GUI_ELEMENT_H_INCLUDED
