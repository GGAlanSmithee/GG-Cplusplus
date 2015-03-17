#ifndef EDITORAPPLICATION_H_INCLUDED
#define EDITORAPPLICATION_H_INCLUDED

#include "Application/Application.h"
#include "Gui/Element.h"

class EditorApplication : public GG_Application
{
    public:
        EditorApplication(std::unique_ptr<GG_Engine> const&,
                          std::shared_ptr<GG_ApplicationData>);
        ~EditorApplication() override;

        void OnLogic(std::unique_ptr<GG_Engine> const&) override;
        void OnRender(std::unique_ptr<GG_Engine> const&) override;

    private:
        void OnMouseEvent(const unsigned int, const float, const GG_Rect);
        GG_GUI_Element guiTestElement;
};

#endif // EDITORAPPLICATION_H_INCLUDED
