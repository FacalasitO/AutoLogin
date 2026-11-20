#include "controller.h"

#include "interface_gui.h"
#include "stdafx.h"

controller g_controller;

/**
 * @brief Constructs a new controller object.
 *
 * Initializes the controller instance, setting the instance pointer, mouse hook,
 * and keyboard hook to nullptr. This prepares the controller class for further
 * configuration and usage.
 *
 * @return A new instance of the controller object with default initializations.
 */
controller::controller(): instance(nullptr), mouse_hook_(nullptr), keyboard_hook_(nullptr)
{
}

/**
 * @brief Loads the mouse and keyboard hooks for the controller.
 *
 * Sets up the mouse and keyboard hooks necessary for the functioning of the controller.
 * The method ensures both hooks are installed properly and returns a boolean indicating success or failure.
 *
 * @return true if both hooks are successfully installed, false otherwise.
 */
bool controller::load()
{
    if (!this->mouse_hook_)
    {
        this->mouse_hook_ = SetWindowsHookEx(WH_MOUSE, mouse, g_controller.instance, GetCurrentThreadId());

        if (!this->mouse_hook_)
        {
            return false;
        }
    }

    if (!this->keyboard_hook_)
    {
        this->keyboard_hook_ = SetWindowsHookEx(WH_KEYBOARD, keyboard, g_controller.instance, GetCurrentThreadId());

        if (!this->keyboard_hook_)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Handles mouse events intercepted by the hook.
 *
 * Processes mouse input events and routes them to custom handlers while maintaining the integrity
 * of the normal system message flow. Implements specific behavior when the left mouse button
 * is pressed, invoking custom functions.
 *
 * If the current game window is not active or the player state does not correspond to game processing,
 * the event is passed to the next hook in the chain without further action.
 *
 * @param code The hook code passed to the mouse procedure, used to determine the action to be taken.
 * @param w_param The WPARAM parameter indicating the mouse message type, such as WM_LBUTTONDOWN or WM_LBUTTONUP.
 * @param l_param The LPARAM parameter containing additional message-specific information, typically mouse data.
 * @return The result of the CallNextHookEx function, ensuring the event is passed to the next hook in the chain.
 */
LRESULT controller::mouse(const int code, const WPARAM w_param, const LPARAM l_param)
{
    // We verify that it is not in the character selection or server selection
    if (!pGameWindow || GetForegroundWindow() != pGameWindow || pPlayerState != GameProcess)
    {
        return CallNextHookEx(g_controller.mouse_hook_, code, w_param, l_param);
    }

    switch (w_param)
    {
        case WM_LBUTTONUP:
            break;
        case WM_LBUTTONDOWN:
            {
                // TODO: Here we explain what happens when we click inside the game
                // Example:
                // g_custom_jewel_bank.event_click_close(w_param);
                
                return CallNextHookEx(g_controller.mouse_hook_, code, w_param, l_param);
            }
            break;
        default: break;
    }

    return CallNextHookEx(g_controller.mouse_hook_, code, w_param, l_param);
}

/**
 * @brief Handles the keyboard input events through a low-level keyboard hook.
 *
 * This method processes keyboard events captured by the keyboard hook, filtering
 * input based on the current game window and player state.
 *
 * @param code Specifies the type of hook event. A code of HC_ACTION indicates
 *             that a key action occurred.
 * @param w_param An additional message-specific information parameter that varies
 *                depending on the event type (e.g., WM_KEYDOWN).
 * @param l_param A pointer to a KBDLLHOOKSTRUCT structure containing information about
 *                a low-level keyboard input event.
 * @return Returns the result of the next hook in the chain by calling CallNextHookEx.
 *         If the hook should not process a key, simply passes the parameters to the next hook.
 */
LRESULT controller::keyboard(const int code, const WPARAM w_param, const LPARAM l_param)
{
    // We verify that it is not in the character selection or server selection
    if (!pGameWindow || GetForegroundWindow() != pGameWindow || pPlayerState != GameProcess)
        return CallNextHookEx(g_controller.keyboard_hook_, code, w_param, l_param);

    // We verified that it is a valid keyboard code
    if (code < 0)
        return CallNextHookEx(g_controller.keyboard_hook_, code, w_param, l_param);

    // We verified that it was a key press
    if (!l_param)
        return CallNextHookEx(g_controller.keyboard_hook_, code, w_param, l_param);

    // We intercept the key
    if (code == HC_ACTION)
    {
        const bool key_down = !(l_param & (1 << 31));

        if (key_down)
        {
            switch (w_param)
            {
                // TODO: Here when you want to open an interface or execute something with a key.
                // Example: 
                // case VK_J:
                //    {
                //        //custom_jewel_bank::open_window();
                //    }
                //break;
                case VK_ESCAPE:
                    {
                        // TODO: Here where you go when you want to exit an interface using the escape key.
                        // Example: 
                        // if (g_interface.data[e_jewel_bank_main].is_open())
                        // {
                        //     g_interface.data[e_jewel_bank_main].close();
                        // }
                    }
                break;
                default: break;
            }
        }
    }

    return CallNextHookEx(g_controller.keyboard_hook_, code, w_param, l_param);
}

