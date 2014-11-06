#ifndef COMPONENTS_H_INCLUDED
#define COMPONENTS_H_INCLUDED

#include <string>
#include <SDL.h>
#include <glm/glm.hpp>

namespace GGEngine
{
    namespace Component
    {
        const long long NumbTypes = 1 << 4;

        enum class Type : int
        {
            None         = 0,
            Displacement = 1 << 0,
            Velocity     = 1 << 2,
            Appearance   = 1 << 3
        };

        typedef struct Appearance
                       {
                           std::string TextureId    = "";
                           SDL_Rect    ClippingRect = { 0.0f, 0.0f, 0.0f, 0.0f };
                       }
                       Appearance;

        typedef struct Displacement
                       {
                           glm::vec4 Value = glm::vec4(glm::vec3(0.0), 1.0);
                       }
                       Displacement;

        typedef struct Velocity
                       {
                           float Value = 0.0f;
                       }
                       Velocity;
    }
}

#endif // COMPONENTS_H_INCLUDED
