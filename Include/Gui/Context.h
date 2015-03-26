#ifndef GUI_CONTEXT_H_INCLUDED
#define GUI_CONTEXT_H_INCLUDED

#include <memory>
#include <vector>
#include "Element.h"
#include "Engine/Renderer.h"
#include "Math/Rect.h"

class GG_GUI_Element;

class GG_GUI_Context
{
    public:
        GG_GUI_Context(GG_Rect const&);
        ~GG_GUI_Context();

        friend float const GG_GetX     (GG_GUI_Context *const);
        friend float const GG_GetY     (GG_GUI_Context *const);
        friend float const GG_GetWidth (GG_GUI_Context *const);
        friend float const GG_GetHeight(GG_GUI_Context *const);

        friend void GG_AddChild(GG_GUI_Context *const, GG_GUI_Element *const);

        friend std::vector<GG_GUI_Element*> const& GG_GetChildren(GG_GUI_Context *const);

    private:
        GG_Rect                      boundary;
        std::vector<GG_GUI_Element*> children;
};

void GG_Render(GG_GUI_Context *const, std::unique_ptr<GG_Renderer> const&);

#endif // GUI_CONTEXT_H_INCLUDED
