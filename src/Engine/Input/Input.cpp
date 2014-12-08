#include "Input/Input.h"

namespace GGInputEngine
{
	void OnKeyDown(const std::unique_ptr<GGCoreEngine::EventManager>& eventManager, const SDL_Keycode keycode)
    {
        switch (keycode)
        {
            case SDLK_0: eventManager->OnKeyDown0(); break;
            case SDLK_1: eventManager->OnKeyDown1(); break;
            case SDLK_2: eventManager->OnKeyDown2(); break;
            case SDLK_3: eventManager->OnKeyDown3(); break;
            case SDLK_4: eventManager->OnKeyDown4(); break;
            case SDLK_5: eventManager->OnKeyDown5(); break;
            case SDLK_6: eventManager->OnKeyDown6(); break;
            case SDLK_7: eventManager->OnKeyDown7(); break;
            case SDLK_8: eventManager->OnKeyDown8(); break;
            case SDLK_9: eventManager->OnKeyDown9(); break;
            case SDLK_KP_0: eventManager->OnKeyDownKeypad0(); break;
            case SDLK_KP_1: eventManager->OnKeyDownKeypad1(); break;
            case SDLK_KP_2: eventManager->OnKeyDownKeypad2(); break;
            case SDLK_KP_3: eventManager->OnKeyDownKeypad3(); break;
            case SDLK_KP_4: eventManager->OnKeyDownKeypad4(); break;
            case SDLK_KP_5: eventManager->OnKeyDownKeypad5(); break;
            case SDLK_KP_6: eventManager->OnKeyDownKeypad6(); break;
            case SDLK_KP_7: eventManager->OnKeyDownKeypad7(); break;
            case SDLK_KP_8: eventManager->OnKeyDownKeypad8(); break;
            case SDLK_KP_9: eventManager->OnKeyDownKeypad9(); break;
            case SDLK_F1: eventManager->OnKeyDownF1(); break;
            case SDLK_F2: eventManager->OnKeyDownF2(); break;
            case SDLK_F3: eventManager->OnKeyDownF3(); break;
            case SDLK_F4: eventManager->OnKeyDownF4(); break;
            case SDLK_F5: eventManager->OnKeyDownF5(); break;
            case SDLK_F6: eventManager->OnKeyDownF6(); break;
            case SDLK_F7: eventManager->OnKeyDownF7(); break;
            case SDLK_F8: eventManager->OnKeyDownF8(); break;
            case SDLK_F9: eventManager->OnKeyDownF9(); break;
            case SDLK_F10: eventManager->OnKeyDownF10(); break;
            case SDLK_F11: eventManager->OnKeyDownF11(); break;
            case SDLK_F12: eventManager->OnKeyDownF12(); break;
            case SDLK_a: eventManager->OnKeyDownA(); break;
            case SDLK_b: eventManager->OnKeyDownB(); break;
            case SDLK_c: eventManager->OnKeyDownC(); break;
            case SDLK_d: eventManager->OnKeyDownD(); break;
            case SDLK_e: eventManager->OnKeyDownE(); break;
            case SDLK_f: eventManager->OnKeyDownF(); break;
            case SDLK_g: eventManager->OnKeyDownG(); break;
            case SDLK_h: eventManager->OnKeyDownH(); break;
            case SDLK_i: eventManager->OnKeyDownI(); break;
            case SDLK_j: eventManager->OnKeyDownJ(); break;
            case SDLK_k: eventManager->OnKeyDownK(); break;
            case SDLK_l: eventManager->OnKeyDownL(); break;
            case SDLK_m: eventManager->OnKeyDownM(); break;
            case SDLK_n: eventManager->OnKeyDownN(); break;
            case SDLK_o: eventManager->OnKeyDownO(); break;
            case SDLK_p: eventManager->OnKeyDownP(); break;
            case SDLK_q: eventManager->OnKeyDownQ(); break;
            case SDLK_r: eventManager->OnKeyDownR(); break;
            case SDLK_s: eventManager->OnKeyDownS(); break;
            case SDLK_t: eventManager->OnKeyDownT(); break;
            case SDLK_u: eventManager->OnKeyDownU(); break;
            case SDLK_v: eventManager->OnKeyDownV(); break;
            case SDLK_w: eventManager->OnKeyDownW(); break;
            case SDLK_x: eventManager->OnKeyDownX(); break;
            case SDLK_y: eventManager->OnKeyDownY(); break;
            case SDLK_z: eventManager->OnKeyDownZ(); break;
            case SDLK_LSHIFT: eventManager->OnKeyDownLeftShift(); break;
            case SDLK_RSHIFT: eventManager->OnKeyDownRightShift(); break;
            case SDLK_LCTRL: eventManager->OnKeyDownLeftControl(); break;
            case SDLK_RCTRL: eventManager->OnKeyDownRightControl(); break;
            case SDLK_LALT: eventManager->OnKeyDownLeftAlt(); break;
            case SDLK_RALT: eventManager->OnKeyDownRightAlt(); break;
            case SDLK_BACKSPACE: eventManager->OnKeyDownBackspace(); break;
            case SDLK_DELETE: eventManager->OnKeyDownDelete(); break;
            case SDLK_ESCAPE: eventManager->OnKeyDownEscape(); break;
            case SDLK_SPACE: eventManager->OnKeyDownSpace(); break;
            case SDLK_TAB: eventManager->OnKeyDownTab(); break;
        }
    }
	
	void OnKeyUp(const std::unique_ptr<GGCoreEngine::EventManager>& eventManager, const SDL_Keycode keycode)
    {
        switch (keycode)
        {
            case SDLK_0: eventManager->OnKeyUp0(); break;
            case SDLK_1: eventManager->OnKeyUp1(); break;
            case SDLK_2: eventManager->OnKeyUp2(); break;
            case SDLK_3: eventManager->OnKeyUp3(); break;
            case SDLK_4: eventManager->OnKeyUp4(); break;
            case SDLK_5: eventManager->OnKeyUp5(); break;
            case SDLK_6: eventManager->OnKeyUp6(); break;
            case SDLK_7: eventManager->OnKeyUp7(); break;
            case SDLK_8: eventManager->OnKeyUp8(); break;
            case SDLK_9: eventManager->OnKeyUp9(); break;
            case SDLK_KP_0: eventManager->OnKeyUpKeypad0(); break;
            case SDLK_KP_1: eventManager->OnKeyUpKeypad1(); break;
            case SDLK_KP_2: eventManager->OnKeyUpKeypad2(); break;
            case SDLK_KP_3: eventManager->OnKeyUpKeypad3(); break;
            case SDLK_KP_4: eventManager->OnKeyUpKeypad4(); break;
            case SDLK_KP_5: eventManager->OnKeyUpKeypad5(); break;
            case SDLK_KP_6: eventManager->OnKeyUpKeypad6(); break;
            case SDLK_KP_7: eventManager->OnKeyUpKeypad7(); break;
            case SDLK_KP_8: eventManager->OnKeyUpKeypad8(); break;
            case SDLK_KP_9: eventManager->OnKeyUpKeypad9(); break;
            case SDLK_F1: eventManager->OnKeyUpF1(); break;
            case SDLK_F2: eventManager->OnKeyUpF2(); break;
            case SDLK_F3: eventManager->OnKeyUpF3(); break;
            case SDLK_F4: eventManager->OnKeyUpF4(); break;
            case SDLK_F5: eventManager->OnKeyUpF5(); break;
            case SDLK_F6: eventManager->OnKeyUpF6(); break;
            case SDLK_F7: eventManager->OnKeyUpF7(); break;
            case SDLK_F8: eventManager->OnKeyUpF8(); break;
            case SDLK_F9: eventManager->OnKeyUpF9(); break;
            case SDLK_F10: eventManager->OnKeyUpF10(); break;
            case SDLK_F11: eventManager->OnKeyUpF11(); break;
            case SDLK_F12: eventManager->OnKeyUpF12(); break;
            case SDLK_a: eventManager->OnKeyUpA(); break;
            case SDLK_b: eventManager->OnKeyUpB(); break;
            case SDLK_c: eventManager->OnKeyUpC(); break;
            case SDLK_d: eventManager->OnKeyUpD(); break;
            case SDLK_e: eventManager->OnKeyUpE(); break;
            case SDLK_f: eventManager->OnKeyUpF(); break;
            case SDLK_g: eventManager->OnKeyUpG(); break;
            case SDLK_h: eventManager->OnKeyUpH(); break;
            case SDLK_i: eventManager->OnKeyUpI(); break;
            case SDLK_j: eventManager->OnKeyUpJ(); break;
            case SDLK_k: eventManager->OnKeyUpK(); break;
            case SDLK_l: eventManager->OnKeyUpL(); break;
            case SDLK_m: eventManager->OnKeyUpM(); break;
            case SDLK_n: eventManager->OnKeyUpN(); break;
            case SDLK_o: eventManager->OnKeyUpO(); break;
            case SDLK_p: eventManager->OnKeyUpP(); break;
            case SDLK_q: eventManager->OnKeyUpQ(); break;
            case SDLK_r: eventManager->OnKeyUpR(); break;
            case SDLK_s: eventManager->OnKeyUpS(); break;
            case SDLK_t: eventManager->OnKeyUpT(); break;
            case SDLK_u: eventManager->OnKeyUpU(); break;
            case SDLK_v: eventManager->OnKeyUpV(); break;
            case SDLK_w: eventManager->OnKeyUpW(); break;
            case SDLK_x: eventManager->OnKeyUpX(); break;
            case SDLK_y: eventManager->OnKeyUpY(); break;
            case SDLK_z: eventManager->OnKeyUpZ(); break;
            case SDLK_LSHIFT: eventManager->OnKeyUpLeftShift(); break;
            case SDLK_RSHIFT: eventManager->OnKeyUpRightShift(); break;
            case SDLK_LCTRL: eventManager->OnKeyUpLeftControl(); break;
            case SDLK_RCTRL: eventManager->OnKeyUpRightControl(); break;
            case SDLK_LALT: eventManager->OnKeyUpLeftAlt(); break;
            case SDLK_RALT: eventManager->OnKeyUpRightAlt(); break;
            case SDLK_BACKSPACE: eventManager->OnKeyUpBackspace(); break;
            case SDLK_DELETE: eventManager->OnKeyUpDelete(); break;
            case SDLK_ESCAPE: eventManager->OnKeyUpEscape(); break;
            case SDLK_SPACE: eventManager->OnKeyUpSpace(); break;
            case SDLK_TAB: eventManager->OnKeyUpTab(); break;
        }
    }
    
	void HandleEvents(const std::unique_ptr<GGCoreEngine::EventManager>& eventManager, SDL_Event& event);
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                {
                    OnKeyDown(eventManager, event.key.keysym.sym);
                    break;
                }
                case SDL_KEYUP:
                {
                    OnKeyUp(eventManager, event.key.keysym.sym);
                    break;
                }
                case SDL_QUIT:
                {
                    // Empty
                }
            }
        }
    }
}