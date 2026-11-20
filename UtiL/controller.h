#pragma once
#include <windows.h>

#include "stdafx.h"

#define HOOK_KEY_CONSUMED (-1)

struct virtual_key {
    int key_code;
    const char* description;
};

extern virtual_key virtual_key_table[];

class controller
{
public:
    controller();
    bool	load();
	
    static	LRESULT WINAPI mouse(int code, WPARAM w_param, LPARAM l_param);
    static	LRESULT WINAPI keyboard(int code, WPARAM w_param, LPARAM l_param);
    static const char* get_key_description(int key_code);
	
    HINSTANCE	instance;
private:
    HHOOK		mouse_hook_;
    HHOOK		keyboard_hook_;
};
extern controller g_controller;
