#ifndef EDITORAPPLICATION_H_INCLUDED
#define EDITORAPPLICATION_H_INCLUDED

#include "Application/Application.h"

class EditorApplication : public GG_Application
{
    public:
        EditorApplication(std::unique_ptr<GG_Engine> const&,
                          std::shared_ptr<GG_ApplicationData>);
        ~EditorApplication() override;

        void OnLogic(std::unique_ptr<GG_Engine> const&) override;
        void OnRender(std::unique_ptr<GG_Engine> const&) override;

    private:
        void OnMouseEvent(const unsigned int, const float);
};

#endif // EDITORAPPLICATION_H_INCLUDED
