#pragma once

#include "stdafx.h"
#include "s6/version1.04e/import_s6e.h"

// -- Default

enum interface_constants: WORD
{
    max_object     = 250,
    max_win_width  = 640,
    max_win_height = 480
};

struct interface_object
{
    // Variables
    DWORD model_id;
    float width;
    float height;
    float x;
    float y;
    float max_x;
    float max_y;
    DWORD event_tick;
    bool  on_click;
    bool  on_show;
    BYTE  attribute;
    bool  by_close;
    long  opened_value;
    BYTE  speed;
    char  stat_value[20];
    int   type;
    bool  first_load;

    // Funciones
    void close()
    {
        this->on_show   = false;
        pSetCursorFocus = false;
        this->by_close  = false;
    }

    void open()
    {
        this->on_show   = true;
        pSetCursorFocus = true;
        this->by_close  = false;
    }

    void open(const int value, const int speed_animation)
    {
        this->on_show      = true;
        pSetCursorFocus    = true;
        this->opened_value = value;
        this->speed        = static_cast<BYTE>(speed_animation);
        this->by_close     = false;
        this->first_load   = true;
    }

    void close(const int value, const int speed_animation)
    {
        this->on_show      = false;
        pSetCursorFocus    = false;
        this->opened_value = value;
        this->speed        = static_cast<BYTE>(speed_animation);
        this->by_close     = false;
    }

    void close_animated(int speed_animation)
    {
        pSetCursorFocus = false;
        this->speed     = static_cast<BYTE>(speed_animation);
        this->by_close  = true;
    }

    bool is_open() const
    {
        return this->on_show == true;
    }

    bool is_close() const
    {
        return this->on_show == false;
    }
};

class interface_gui
{
public:
    interface_object data[max_object];

    void        load();
    static void load_models();
    static void load_images();
    static void work();
    void        bind_object(short object_id, DWORD model_id, float width, float height, float x, float y);

    void       draw_gui(short object_id, float pos_x, float pos_y);
    void       draw_img(short object_id, float pos_x, float pos_y, float scale_x, float scale_y);
    void       reset_draw_img(short object_id);
    static int draw_tool_tip(int x, int y, LPCSTR text, ...);
    static int draw_message(int mode, LPCSTR text, ...);
    static int draw_format(DWORD color, int pos_x, int pos_y, int width, int align, LPCSTR text, ...);
    static void       draw_text(HFONT   font, int PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height, BYTE Align,
                                LPCSTR Text, ...);
    void        draw_button(short object_id, float pos_x, float pos_y, float scale_x, float scale_y);
    void        draw_colored_gui(short object_id, float x, float y, DWORD color);
    float       draw_repeat_gui(short object_id, float x, float y, int count) const;
    static void draw_item(float pos_x, float pos_y, float width, float height, int item_id, int level, int excl,
                          int   anc, bool    on_mouse);

    static bool check_window(int window_id);
    static int  close_window(int window_id);
    static int  open_window(int window_id);
    bool        is_work_zone(short object_id) const;
    static float get_position_screen(float position, bool isPositionY);
    static float get_scale_screen(int size);
    static bool combined_checks();
    static bool check_map();
};

extern interface_gui g_interface;
