#ifndef GUI_ELEMENT_H_INCLUDED
#define GUI_ELEMENT_H_INCLUDED

#include <vector>
#include "Context.h"
#include "Engine/Renderer.h"
#include "Math/Rect.h"

enum class GG_GUI_Style
{
    None,
    Absolute,
    Relative
};

class GG_GUI_Context;

class GG_GUI_Element
{
    public:
        GG_GUI_Element(GG_Rect const&, GG_GUI_Style const, bool const);

        ~GG_GUI_Element();

        friend float const GG_GetX     (GG_GUI_Element *const);
        friend float const GG_GetY     (GG_GUI_Element *const);
        friend float const GG_GetWidth (GG_GUI_Element *const);
        friend float const GG_GetHeight(GG_GUI_Element *const);

        friend bool const GG_IsVisible(GG_GUI_Element *const);

        friend std::vector<GG_GUI_Element*> const& GG_GetChildren(GG_GUI_Element *const);

        friend GG_GUI_Element *const GG_GetParent (GG_GUI_Element *const);
        friend GG_GUI_Context *const GG_GetContext(GG_GUI_Element *const);
        friend void                  GG_AddChild  (GG_GUI_Element *const,
                                                   GG_GUI_Element *const);
        friend void                  GG_SetContext(GG_GUI_Element *const,
                                                   GG_GUI_Context *const);

    private:
        GG_GUI_Context*              context;
        GG_GUI_Element*              parent;
        std::vector<GG_GUI_Element*> children;
        GG_Rect                      boundary;
        GG_GUI_Style                 style;
        bool                         isVisible;
};

void GG_Render(GG_GUI_Element *const, std::unique_ptr<GG_Renderer> const&);

#endif // GUI_ELEMENT_H_INCLUDED
