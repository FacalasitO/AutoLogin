#pragma once
#include "Util/stdafx.h"

#define TEXT_AUTO_LOGIN_REGISTRY "SOFTWARE\\Webzen\\Mu\\Config"
#define TEXT_AUTO_LOGIN_ID "ID"
#define TEXT_AUTO_LOGIN_PASSWORD "PW"
#define TEXT_AUTO_LOGIN_SAVE_PASSWORD "SavePass"
#define TEXT_AUTO_LOGIN_SAVE_PASSWORD_INPUT_TEXT "Guardar Contraseña"

#define InputBox_GetText					((void(__thiscall*)(int thisa, LPSTR lpString, int nMaxCount)) 0x004217D0)
#define InputBox_SetText					((void(__thiscall*)(int thisa, const char* pszText)) 0x00421830)
#define RequestLogin						((int(__thiscall*)(int This)) 0x0040B7B0)
#define ButtonCancel_SetPosition			((int(__thiscall*)(BYTE* CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define _Instance							((int(*)()) 0x00482B70)
#define LoginWinCreate						((void(__thiscall*)(int This)) 0x0040AD70)

class custom_auto_login
{
public:
    static void __thiscall set_position_cancel_button(BYTE* This, int nXCoord, int nYCoord, int eChangedPram);
    void Load();
    BOOL savePass;
    int iCancelButtonPosX;
    int iCancelButtonPosY;
    char iUser[32];
    char iPassword[32];
};

extern custom_auto_login g_custom_auto_login;
