#pragma once
#include "stdafx.h"

// Constantes
enum target_type: BYTE
{
    target_type_undefined = 0,
    target_type_npc = 1,
    target_type_attack = 2
};

// Clase principal
class user
{
public:
    // Variables
    int       x_coordinate;
    int       y_coordinate;
    lpCharObj lp_player;
    lpViewObj lp_view_player;
    lpViewObj lp_view_target;
    BYTE      m_target_type;
    int       m_map_number;
    int       m_cursor_x;
    int       magick_attack;
    int       m_cursor_y;
    DWORD     m_target_update_tick;
    int       post_item_id;
    int       post_item_lv;
    int       post_item_exc;
    int       post_item_acc;
    int       post_item_x;
    int       post_item_y;

public:
    void       load();
    void       refresh();
    bool       get_target();
    static int get_active_skill();
};

extern user g_obj_user;
