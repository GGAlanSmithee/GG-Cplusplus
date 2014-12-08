#include "Input/Input.h"

namespace GGInputEngine
{
	void HandleEvents(const std::unique_ptr<GGCoreEngine::EventManager> eventManager)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                {
                    switch (event.key.keysym.sym)
                    {

                    }
                    
                break;
                
                }
                case SDL_KEYUP:
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        {
                        }
                    }

                break;
                
                }
                case SDL_QUIT:
                {
                    
                }
            }
        }
    }
}