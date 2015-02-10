#include "Application.h"

GG_Application::GG_Application(GG_World* world) :
    _world(world)
{
    // Empty
}

GG_Application::~GG_Application()
{
    if (_world == nullptr)
    {
        return;
    }

    delete _world;
    _world = nullptr;
}

void GG_Application::CameraSystem()
{
    GGCoreEngine::Display*     d;
    GGCoreEngine::Focus*       f;
    GGCoreEngine::PointOfView* p;
    GGCoreEngine::Transform*   t;

    for (unsigned int entity = 0; entity < _world->Size; ++entity)
    {
        if ((_world->Enteties[entity] & CameraMask) != CameraMask)
        {
            continue;
        }

        d = &(_world->DisplayComponents[entity]);
        f = &(_world->FocusComponents[entity]);
        p = &(_world->PointOfViewComponents[entity]);
        t = &(_world->TransformComponents[entity]);

        /// @todo use camera here
    }
}

void GG_Application::MovementSystem()
{
    GGCoreEngine::Transform* transform;
    GGCoreEngine::Physics*     physics;

    for (auto entity = 0; entity < _world->Size; ++entity)
    {
        if ((_world->Enteties[entity] & MovementMask) != MovementMask)
        {
            continue;
        }

        transform = &(_world->TransformComponents[entity]);
        physics     = &(_world->PhysicsComponents[entity]);

//        transform->Scale = glm::scale(glm::mat4(0.2f), glm::vec3(0.5f, 0.5f, 0.5f));
//        transform->Rotation = glm::rotate(glm::mat4(1.0f), 76.0f, glm::vec3(0.75f, 1.0f, 0.302f));
//        transform->Translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    }
}

void GG_Application::RenderingSystem()
{
    GGCoreEngine::Transform*  t;
    GGCoreEngine::Appearance* a;

    for (unsigned int entity = 0; entity < _world->Size; ++entity)
    {
        if ((_world->Enteties[entity] & RenderMask) != RenderMask)
        {
            continue;
        }

        t = &(_world->TransformComponents[entity]);
        a = &(_world->AppearanceComponents[entity]);

//        GGRendererEngine::DrawModel(t->Get(), a->Scene, a->Shader);
    }
}

GG_Application* const GG_CreateApplication(GG_World* const world)
{
    if (world == nullptr)
    {
        return new GG_Application(new GG_World(1000));
    }

    return new GG_Application(world);
}

void GG_DestroyApplication(GG_Application* application)
{
    if (application == nullptr)
    {
        return;
    }

    delete application;
    application = nullptr;
}

void GG_OnEvent(GG_Application* const application, GG_Engine* const engine)
{

}

void GG_OnLogic(GG_Application* const application, GG_Engine* const engine)
{

}

void GG_OnRender(GG_Application* const application, GG_Engine* const engine)
{

}
