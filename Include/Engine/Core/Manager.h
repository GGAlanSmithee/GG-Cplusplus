#ifndef CORE_ENGINE_MANAGER_H_INCLUDED
#define CORE_ENGINE_MANAGER_H_INCLUDED

namespace GGCoreEngine
{
    /// Manages input for the game using this manager
    /// @author Alan Smithee
    /// @date created 2014-12-05
    /// @todo flesh out exactly how this should interact with event engine and physics engine with clicking enteties, doing raycasts etc
    class InputManager : Manager
    {
        public:
            /// Initializes the input manager
            /// @author Alan Smithee
            /// @date created 2014-12-05
            InputManager();

            /// Cleans up the input manager
            /// @author Alan Smithee
            /// @date created 2014-12-05
            virtual ~InputManager() override;

            /// Is called every frame from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-05
            virtual void OnUpdate() override;

            /// Is called at a fixed update rate from game loop on update
            /// @author Alan Smithee
            /// @date created 2014-12-05
            virtual void OnFixedUpdate() override;

            /// Fires when user presses the keyboard 0 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown0();

            /// Fires when user presses the keyboard 1 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown1();

            /// Fires when user presses the keyboard 2 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown2();

            /// Fires when user presses the keyboard 3 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown3();

            /// Fires when user presses the keyboard 4 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown4();

            /// Fires when user presses the keyboard 5 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown5();

            /// Fires when user presses the keyboard 6 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown6();

            /// Fires when user presses the keyboard 7 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown7();

            /// Fires when user presses the keyboard 8 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown8();

            /// Fires when user presses the keyboard 9 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDown9();

            /// Fires when user presses the keyboard keypad 0 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad0();

            /// Fires when user presses the keyboard keypad 1 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad1();

            /// Fires when user presses the keyboard keypad 2 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad2();

            /// Fires when user presses the keyboard keypad 3 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad3();

            /// Fires when user presses the keyboard keypad 4 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad4();

            /// Fires when user presses the keyboard keypad 5 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad5();

            /// Fires when user presses the keyboard keypad 6 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad6();

            /// Fires when user presses the keyboard keypad 7 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad7();

            /// Fires when user presses the keyboard keypad 8 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad8();

            /// Fires when user presses the keyboard keypad 9 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownKeypad9();

            /// Fires when user presses the keyboard f1 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF1();

            /// Fires when user presses the keyboard f2 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF2();

            /// Fires when user presses the keyboard f3 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF3();

            /// Fires when user presses the keyboard f4 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF4();

            /// Fires when user presses the keyboard f5 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF5();

            /// Fires when user presses the keyboard f6 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF6();

            /// Fires when user presses the keyboard f7 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF7();

            /// Fires when user presses the keyboard f8 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF8();

            /// Fires when user presses the keyboard f9 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF9();

            /// Fires when user presses the keyboard f10 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF10();

            /// Fires when user presses the keyboard f11 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF11();

            /// Fires when user presses the keyboard f12 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF12();

            /// Fires when user presses the keyboard a key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownA();

            /// Fires when user presses the keyboard b key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownB();

            /// Fires when user presses the keyboard c key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownC();

            /// Fires when user presses the keyboard d key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownD();

            /// Fires when user presses the keyboard e key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownE();

            /// Fires when user presses the keyboard f key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownF();

            /// Fires when user presses the keyboard g key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownG();

            /// Fires when user presses the keyboard h key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownH();

            /// Fires when user presses the keyboard i key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownI();

            /// Fires when user presses the keyboard j key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownJ();

            /// Fires when user presses the keyboard k key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownK();

            /// Fires when user presses the keyboard l key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownL();

            /// Fires when user presses the keyboard m key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownM();

            /// Fires when user presses the keyboard n key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownN();

            /// Fires when user presses the keyboard o key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownO();

			/// Fires when user presses the keyboard p key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownP();

            /// Fires when user presses the keyboard q key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownQ();

            /// Fires when user presses the keyboard r key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownR();

            /// Fires when user presses the keyboard s key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownS();

            /// Fires when user presses the keyboard t key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownT();

            /// Fires when user presses the keyboard u key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownU();

            /// Fires when user presses the keyboard v key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownV();

            /// Fires when user presses the keyboard w key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownW();

            /// Fires when user presses the keyboardx  key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownX();

            /// Fires when user presses the keyboard y key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownY();

            /// Fires when user presses the keyboard z key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownZ();

            /// Fires when user presses the keyboard left shift key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownLeftShift();

            /// Fires when user presses the keyboard right shift key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownRightShift();

            /// Fires when user presses the keyboard left ctrl key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownLeftCtrl();

            /// Fires when user presses the keyboard right ctrl key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownRightCtrl();

            /// Fires when user presses the keyboard left alt key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownLeftAlt();

            /// Fires when user presses the keyboard right alt key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownRightAlt();

            /// Fires when user presses the keyboard backspace key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownBackspace();

            /// Fires when user presses the keyboard delete key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownDelete();

            /// Fires when user presses the keyboard escape key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownEscape();

            /// Fires when user presses the keyboard space key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownSpace();

            /// Fires when user presses the keyboard tab key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyDownTab();

            /// Fires when user releases the keyboard 0 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp0();

            /// Fires when user releases the keyboard 1 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp1();

            /// Fires when user releases the keyboard 2 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp2();

            /// Fires when user releases the keyboard 3 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp3();

            /// Fires when user releases the keyboard 4 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp4();

            /// Fires when user releases the keyboard 5 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp5();

            /// Fires when user releases the keyboard 6 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp6();

            /// Fires when user releases the keyboard 7 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp7();

            /// Fires when user releases the keyboard 8 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp8();

            /// Fires when user releases the keyboard 9 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUp9();

            /// Fires when user releases the keyboard keypad 0 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad0();

            /// Fires when user releases the keyboard keypad 1 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad1();

            /// Fires when user releases the keyboard keypad 2 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad2();

            /// Fires when user releases the keyboard keypad 3 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad3();

            /// Fires when user releases the keyboard keypad 4 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad4();

            /// Fires when user releases the keyboard keypad 5 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad5();

            /// Fires when user releases the keyboard keypad 6 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad6();

            /// Fires when user releases the keyboard keypad 7 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad7();

            /// Fires when user releases the keyboard keypad 8 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad8();

            /// Fires when user releases the keyboard keypad 9 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpKeypad9();

            /// Fires when user releases the keyboard f1 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF1();

            /// Fires when user releases the keyboard f2 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF2();

            /// Fires when user releases the keyboard f3 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF3();

            /// Fires when user releases the keyboard f4 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF4();

            /// Fires when user releases the keyboard f5 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF5();

            /// Fires when user releases the keyboard f6 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF6();

            /// Fires when user releases the keyboard f7 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF7();

            /// Fires when user releases the keyboard f8 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF8();

            /// Fires when user releases the keyboard f9 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF9();

            /// Fires when user releases the keyboard f10 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF10();

            /// Fires when user releases the keyboard f11 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF11();

            /// Fires when user releases the keyboard f12 key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF12();

            /// Fires when user releases the keyboard a key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpA();

            /// Fires when user releases the keyboard b key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpB();

            /// Fires when user releases the keyboard c key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpC();

            /// Fires when user releases the keyboard d key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpD();

            /// Fires when user releases the keyboard e key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpE();

            /// Fires when user releases the keyboard f key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpF();

            /// Fires when user releases the keyboard g key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpG();

            /// Fires when user releases the keyboard h key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpH();

            /// Fires when user releases the keyboard i key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpI();

            /// Fires when user releases the keyboard j key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpJ();

            /// Fires when user releases the keyboard k key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpK();

            /// Fires when user releases the keyboard l key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpL();

            /// Fires when user releases the keyboard m key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpM();

            /// Fires when user releases the keyboard n key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpN();

            /// Fires when user releases the keyboard o key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpO();

			/// Fires when user releases the keyboard p key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpP();

            /// Fires when user releases the keyboard q key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpQ();

            /// Fires when user releases the keyboard r key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpR();

            /// Fires when user releases the keyboard s key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpS();

            /// Fires when user releases the keyboard t key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpT();

            /// Fires when user releases the keyboard u key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpU();

            /// Fires when user releases the keyboard v key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpV();

            /// Fires when user releases the keyboard w key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpW();

            /// Fires when user releases the keyboardx  key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpX();

            /// Fires when user releases the keyboard y key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpY();

            /// Fires when user releases the keyboard z key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpZ();

            /// Fires when user releases the keyboard left shift key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpLeftShift();

            /// Fires when user releases the keyboard right shift key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpRightShift();

            /// Fires when user releases the keyboard left ctrl key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpLeftCtrl();

            /// Fires when user releases the keyboard right ctrl key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpRightCtrl();

            /// Fires when user releases the keyboard left alt key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpLeftAlt();

            /// Fires when user releases the keyboard right alt key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpRightAlt();

            /// Fires when user releases the keyboard backspace key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpBackspace();

            /// Fires when user releases the keyboard delete key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpDelete();

            /// Fires when user releases the keyboard escape key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpEscape();

            /// Fires when user releases the keyboard space key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpSpace();

            /// Fires when user releases the keyboard tab key
            /// @author Alan Smithee
            /// @date created 2014-12-10
            virtual void OnKeyUpTab();
    };
}

#endif // CORE_ENGINE_MANAGER_H_INCLUDED
