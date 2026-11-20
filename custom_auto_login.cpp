#include "custom_auto_login.h"

#include "Util/interface_gui.h"
#include "Util/util.h"

custom_auto_login g_custom_auto_login;

bool write_string(const std::string& name, const std::string& value)
{
    HKEY  hKey = nullptr;
    DWORD dwDisp;
    DWORD dwSize = value.size();

    if (ERROR_SUCCESS != RegCreateKeyExA(
            HKEY_CURRENT_USER,
            TEXT_AUTO_LOGIN_REGISTRY,
            0,
            nullptr,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            nullptr,
            &hKey,
            &dwDisp)
    )
    {
        return false;
    }

    RegSetValueExA(
        hKey,
        name.c_str(),
        0L,
        REG_SZ,
        reinterpret_cast<const BYTE*>(value.c_str()),
        dwSize
    );
    RegCloseKey(hKey);
    return true;
}

bool write_dword(const std::string& name, DWORD value)
{
    HKEY  hKey = nullptr;
    DWORD dwDisp;
    DWORD dwSize = sizeof(DWORD);

    if (ERROR_SUCCESS != RegCreateKeyExA(
            HKEY_CURRENT_USER,
            TEXT_AUTO_LOGIN_REGISTRY,
            0,
            nullptr,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            nullptr,
            &hKey,
            &dwDisp)
    )
    {
        return false;
    }

    RegSetValueExA(
        hKey,
        name.c_str(),
        0L,
        REG_DWORD,
        reinterpret_cast<BYTE*>(&value),
        dwSize
    );
    RegCloseKey(hKey);
    return true;
}

void custom_auto_login::set_position_cancel_button(BYTE* This, int nXCoord, int nYCoord, int eChangedPram)
{
    g_custom_auto_login.iCancelButtonPosX = nXCoord;
    g_custom_auto_login.iCancelButtonPosY = nYCoord;
    ButtonCancel_SetPosition(This, nXCoord, nYCoord, eChangedPram);
}

void do_request_login()
{
    const int Struct = _Instance() + 16968;

    InputBox_GetText(*reinterpret_cast<DWORD*>(Struct + 848), g_custom_auto_login.iUser, 11);
    InputBox_GetText(*reinterpret_cast<DWORD*>(Struct + 852), g_custom_auto_login.iPassword, 11);

    if (g_custom_auto_login.savePass)
    {
        write_string(TEXT_AUTO_LOGIN_ID, g_custom_auto_login.iUser);
        write_string(TEXT_AUTO_LOGIN_PASSWORD, g_custom_auto_login.iPassword);
        write_dword(TEXT_AUTO_LOGIN_SAVE_PASSWORD, 1);
    }
    else
    {
        write_dword(TEXT_AUTO_LOGIN_SAVE_PASSWORD, 0);
    }

    RequestLogin(Struct);
}

void draw_button_auto_login(int This, int a2)
{
    pSetTextSize(pTextThis(), static_cast<HFONT>(pFontNormal2));

    constexpr float button_cancel_width               = 54.0f;
    constexpr float text_width                        = 120.0f;
    constexpr float checkbox_width                    = 15.0f;
    constexpr float checkbox_height                   = 15.0f;
    constexpr float quantity_sprite_checkbox          = 2.0f;
    constexpr float space_between_text_and_button     = 5.0f;
    constexpr float space_between_button_and_checkbox = 5.0f;

    float checkboxPosX = interface_gui::get_position_screen(
        static_cast<float>(g_custom_auto_login.iCancelButtonPosX) + button_cancel_width - checkbox_width,
        false
    );
    float checkboxPosY = interface_gui::get_position_screen(
        static_cast<float>(g_custom_auto_login.iCancelButtonPosY) - checkbox_height - space_between_button_and_checkbox,
        true
    );
    float textPosX = interface_gui::get_position_screen(
        static_cast<float>(g_custom_auto_login.iCancelButtonPosX) + button_cancel_width - text_width -
        space_between_text_and_button - checkbox_width,
        false
    );
    float textPosY = interface_gui::get_position_screen(
        static_cast<float>(g_custom_auto_login.iCancelButtonPosY) - checkbox_height - space_between_button_and_checkbox,
        true
    );

    float currentHeightCheckButton = interface_gui::get_scale_screen(static_cast<int>(checkbox_height)) /
        quantity_sprite_checkbox;

    if (g_custom_auto_login.savePass)
    {
        currentHeightCheckButton = 0;
    }

    if (pCheckMouseOver(
            static_cast<int>(checkboxPosX),
            static_cast<int>(checkboxPosY),
            static_cast<int>(checkbox_width),
            static_cast<int>(checkbox_height)
        )
    )
    {
        if (pIsKeyRelease(VK_LBUTTON))
        {
            g_custom_auto_login.savePass = !g_custom_auto_login.savePass;
        }
    }

    interface_gui::draw_text(
        static_cast<HFONT>(pFontNormal),
        static_cast<int>(textPosX),
        static_cast<int>(textPosY),
        0xffffffD1,
        0x0,
        static_cast<int>(interface_gui::get_position_screen(text_width, false)),
        0,
        TextAlign::Right,
        TEXT_AUTO_LOGIN_SAVE_PASSWORD_INPUT_TEXT
    );

    pDrawImage(
        0x7B69,
        checkboxPosX,
        checkboxPosY,
        interface_gui::get_position_screen(checkbox_width, false),
        interface_gui::get_position_screen(checkbox_height, true),
        0,
        currentHeightCheckButton,
        interface_gui::get_scale_screen(static_cast<int>(checkbox_width)),
        interface_gui::get_scale_screen(static_cast<int>(checkbox_height)) / quantity_sprite_checkbox,
        true,
        true,
        false
    );
}

void do_login_window_create(int)
{
    int Struct = _Instance() + 16968;
    LoginWinCreate(Struct);

    if (g_custom_auto_login.savePass)
    {
        InputBox_SetText(*reinterpret_cast<DWORD*>(Struct + 848), g_custom_auto_login.iUser);
        InputBox_SetText(*reinterpret_cast<DWORD*>(Struct + 852), g_custom_auto_login.iPassword);
    }
}

void custom_auto_login::Load()
{
    //read data
    HKEY  hKey;
    DWORD dwDisp;
    DWORD dwSize;

    if (ERROR_SUCCESS == RegCreateKeyExA(
            HKEY_CURRENT_USER,
            TEXT_AUTO_LOGIN_REGISTRY,
            0,
            nullptr,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            nullptr,
            &hKey,
            &dwDisp)
    )
    {
        dwSize = 11;
        if (RegQueryValueExA(
            hKey,
            TEXT_AUTO_LOGIN_ID,
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(g_custom_auto_login.iUser),
            &dwSize
        ) != ERROR_SUCCESS)
        {
            ZeroMemory(g_custom_auto_login.iUser, sizeof(g_custom_auto_login.iUser));
        }
        dwSize = 11;
        if (RegQueryValueExA(
            hKey,
            TEXT_AUTO_LOGIN_PASSWORD,
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(g_custom_auto_login.iPassword),
            &dwSize
        ) != ERROR_SUCCESS)
        {
            ZeroMemory(g_custom_auto_login.iPassword, sizeof(g_custom_auto_login.iPassword));
        }
        dwSize = sizeof(int);
        if (RegQueryValueExA(
            hKey,
            TEXT_AUTO_LOGIN_SAVE_PASSWORD,
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(&g_custom_auto_login.savePass),
            &dwSize
        ) != ERROR_SUCCESS)
        {
            g_custom_auto_login.savePass = false;
        }
    }

    set_complete_hook(ASM::CALL, reinterpret_cast<LPVOID>(0x0040B306), &custom_auto_login::set_position_cancel_button);
    set_complete_hook(ASM::CALL, reinterpret_cast<LPVOID>(0x0040B5A9), &draw_button_auto_login);
    set_complete_hook(ASM::CALL, reinterpret_cast<LPVOID>(0x0040B400), &do_request_login);
    set_complete_hook(ASM::CALL, reinterpret_cast<LPVOID>(0x0040B44F), &do_request_login);
    set_complete_hook(ASM::CALL, reinterpret_cast<LPVOID>(0x00483711), &do_login_window_create);
}
