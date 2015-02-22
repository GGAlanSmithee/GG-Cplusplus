#ifndef TESTAPPLICATION_H_INCLUDED
#define TESTAPPLICATION_H_INCLUDED

#include "Application/Application.h"

class TestApplication : public GG_Application
{
    public:
        TestApplication(std::unique_ptr<GG_Engine> const&,
                        std::shared_ptr<GG_ApplicationData>);
        ~TestApplication() override;

        void OnLogic(std::unique_ptr<GG_Engine> const&) override;
        void OnRender(std::unique_ptr<GG_Engine> const&) override;
};

#endif // TESTAPPLICATION_H_INCLUDED
