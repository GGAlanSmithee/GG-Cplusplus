#ifndef GUI_ELEMENT_H_INCLUDED
#define GUI_ELEMENT_H_INCLUDED

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "Styles.h"
#include "Engine/Renderer.h"
#include "Math/Vec2.h"

class GG_GUI_Element
{
    public:
        GG_GUI_Element();
        GG_GUI_Element(GG_Vec2f const&, float const, float const);
        ~GG_GUI_Element();

        friend GG_Vec2f const& GG_GetPosition(GG_GUI_Element const&);
        friend float const GG_GetWidth(GG_GUI_Element const&);
        friend float const GG_GetHeight(GG_GUI_Element const&);

    private:
        GG_GUI_Element*              _parent = nullptr;
        std::vector<GG_GUI_Element*> _children;

        GG_Vec2f position;
        float    width;
        float    height;

        GG_GUI_Styles styles;
};

void GG_Render(GG_GUI_Element const&, std::unique_ptr<GG_Renderer> const&);

#endif // GUI_ELEMENT_H_INCLUDED
