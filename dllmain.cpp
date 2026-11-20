#include <windows.h>

#include "custom_auto_login.h"
#include "Util/controller.h"
#include "Util/interface_gui.h"
#include "Util/User.h"

extern "C" _declspec(dllexport) void EntryProc()
{
    g_controller.load();
    g_obj_user.load();
    g_interface.load();
    
    // TODO: Here all load function
    g_custom_auto_login.Load();
}

BOOL APIENTRY DllMain(HMODULE h_module, DWORD  ul_reason_for_call, LPVOID lp_reserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        g_controller.instance = h_module;
    }

    return TRUE;
}

