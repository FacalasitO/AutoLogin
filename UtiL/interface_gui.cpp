#include "interface_gui.h"

#include "User.h"
#include "Util.h"
#include "stdafx.h"

interface_gui g_interface;

/**
 * @brief Initializes the interface GUI resources for the Jewel Bank system.
 *
 * This method binds a series of graphical objects (e.g., main interface,
 * titles, frames, buttons, etc.) for the Jewel Bank user interface, specifying
 * their unique object IDs, model identifiers, dimensions, and optional offsets.
 *
 * Additionally, the function sets up hooks to integrate specified functions
 * (such as image loading and rendering functionalities) into the execution flow
 * of the interface, ensuring all required resources and behaviors are properly
 * loaded and executed.
 *
 * The bindings for withdrawing objects are created dynamically within a loop
 * to accommodate up to 50 slots.
 *
 * @note The hooks utilize external calls defined elsewhere in the application
 * to ensure proper coordination between loading, rendering, and updating the
 * user interface.
 */
void interface_gui::load()
{
    // TODO: Add here all bind_object
    // Example
    // this->bind_object(e_jewel_bank_main, 0x7A5A, 222, 240, -1, -1);  // Background

    set_complete_hook(
        ASM::CALL,
        reinterpret_cast<LPVOID>(oLoadSomeForm_Call),
        reinterpret_cast<LPVOID>(load_images)
    );
    set_complete_hook(
        ASM::CALL,
        reinterpret_cast<LPVOID>(oDrawInterface_Call),
        reinterpret_cast<LPVOID>(work)
    );
    set_complete_hook(
        ASM::CALLD,
        reinterpret_cast<LPVOID>(0x633FFB),
        reinterpret_cast<LPVOID>(&load_models)
    );
}

/**
 * @brief Loads and initializes the necessary model and texture resources.
 *
 * This method is designed to serve as a container for custom model and texture loading
 * functions, ensuring that graphical components required by the interface are properly
 * set up. Implementations of pLoadModel and pLoadTexture should be added to enhance the
 * functionality and provide flexibility for extending the graphical assets.
 *
 * After performing the custom model and texture loading logic, this method ensures that
 * the pInitModelData2 function is invoked as the final step to guarantee the correct
 * initialization flow of model data.
 *
 * @note It is critical to call pInitModelData2 last to preserve the expected behavior
 * of model data initialization.
 */
void interface_gui::load_models()
{
    // TODO: add here your pLoadModel and pLoadTexture functions

    // Should always go last to maintain normal flow
    pInitModelData2();
}

/**
 * @brief Loads and initializes the required graphical resources for the interface.
 *
 * This method serves as a container to execute custom image loading functions
 * necessary for rendering the user interface. Implementations of custom
 * pLoadImage functions should be added.
 *
 * Upon completion of custom image loading, this method ensures that the main
 * form loading function is invoked last to preserve the expected flow of
 * interface initialization.
 *
 * @note It is important to call pLoadSomeForm last to ensure the graphical
 * components of the interface are rendered correctly.
 */
void interface_gui::load_images()
{
    // TODO: add here your pLoadImage functions
    // Example:
    // pLoadImage(const_cast<char*>("Custom\\Interface\\Next.tga"), 0x7903, 0x2601, 0x2901, 1, 0);

    // Should always go last to maintain normal flow
    pLoadSomeForm();
}

/**
 * @brief Executes the core graphical operations for the interface.
 *
 * This method triggers the refresh of the user's graphical state and provides
 * a placeholder for custom drawing functions. After invoking these operations,
 * it ensures that the interface's primary drawing mechanism is executed last
 * to maintain the correct rendering flow.
 *
 * @note New custom draw functions should be added within the TODO section
 * for encapsulated and modular rendering.
 */
void interface_gui::work()
{
    g_obj_user.refresh();

    // TODO: add here your draw functions
    // Example:
    // g_custom_jewel_bank.draw_window();

    // Should always go last to maintain normal flow
    pDrawInterface();
}

/**
 * @brief Binds a graphical object to a specific model and sets its properties.
 *
 * This function initializes the graphical object's properties, such as size, position, and
 * additional attributes, based on the provided parameters. It ensures the object is
 * configured for further operations like rendering or interaction.
 *
 * @param object_id The unique identifier for the graphical object to bind.
 * @param model_id The model ID associated with the object to be displayed.
 * @param width The width of the graphical object.
 * @param height The height of the graphical object.
 * @param x The X-coordinate for the object's position on the interface.
 * @param y The Y-coordinate for the object's position on the interface.
 */
void interface_gui::bind_object(short object_id, DWORD model_id, float width, float height, float x, float y)
{
    this->data[object_id].event_tick = 0;
    this->data[object_id].on_click   = false;
    this->data[object_id].on_show    = false;
    this->data[object_id].model_id   = model_id;
    this->data[object_id].width      = width;
    this->data[object_id].height     = height;
    this->data[object_id].x          = x;
    this->data[object_id].y          = y;
    this->data[object_id].max_x      = x + width;
    this->data[object_id].max_y      = y + height;
    this->data[object_id].attribute  = 0;
}

/**
 * @brief Draws a graphical user interface (GUI) element at a specified position.
 *
 * This function renders a GUI element identified by the given object ID at the given position.
 * If the element's coordinates are uninitialized, it initializes them along with the element's
 * boundaries based on its width and height.
 *
 * @param object_id The unique identifier of the GUI element to draw.
 * @param pos_x The horizontal position (X-coordinate) where the GUI element should be drawn.
 * @param pos_y The vertical position (Y-coordinate) where the GUI element should be drawn.
 */
void interface_gui::draw_gui(short object_id, float pos_x, float pos_y)
{
    if (static_cast<int>(this->data[object_id].x) == -1 || static_cast<int>(this->data[object_id].y) == -1)
    {
        this->data[object_id].x     = pos_x;
        this->data[object_id].y     = pos_y;
        this->data[object_id].max_x = pos_x + this->data[object_id].width;
        this->data[object_id].max_y = pos_y + this->data[object_id].height;
    }

    pDrawGUI(
        this->data[object_id].model_id,
        pos_x,
        pos_y,
        this->data[object_id].width,
        this->data[object_id].height
    );
}

/**
 * @brief Draws an image on the graphical interface with specified position and scaling.
 *
 * This function renders an image corresponding to a given object ID at the specified position and
 * scale factors. If the image's position is uninitialized (represented by -1), it initializes the
 * position and boundaries based on the given parameters and the object's width and height.
 *
 * @param object_id The unique identifier of the graphical object to be drawn.
 * @param pos_x The horizontal position (X-coordinate) where the image should be drawn.
 * @param pos_y The vertical position (Y-coordinate) where the image should be drawn.
 * @param scale_x The horizontal scaling factor to adjust the image's width.
 * @param scale_y The vertical scaling factor to adjust the image's height.
 */
void interface_gui::draw_img(short object_id, float pos_x, float pos_y, float scale_x, float scale_y)
{
    if (static_cast<int>(this->data[object_id].x) == -1 || static_cast<int>(this->data[object_id].y) == -1)
    {
        this->data[object_id].x     = pos_x;
        this->data[object_id].y     = pos_y;
        this->data[object_id].max_x = pos_x + this->data[object_id].width;
        this->data[object_id].max_y = pos_y + this->data[object_id].height;
    }

    pDrawImage(
        static_cast<int>(this->data[object_id].model_id),
        pos_x,
        pos_y,
        this->data[object_id].width,
        this->data[object_id].height,
        0,
        0,
        scale_x,
        scale_y,
        true,
        true,
        0.0f
    );
}

/**
 * @brief Resets the drawing parameters for a specific graphical object in the interface.
 *
 * This function clears the positional and dimensional data of the specified object,
 * effectively resetting its drawing state. It ensures that the object's
 * properties for position and size are set to default values (-1).
 *
 * @param object_id The unique identifier of the graphical object whose drawing parameters are to be reset.
 */
void interface_gui::reset_draw_img(short object_id)
{
    if (static_cast<int>(this->data[object_id].x) != -1 || static_cast<int>(this->data[object_id].y) != -1)
    {
        this->data[object_id].x     = -1;
        this->data[object_id].y     = -1;
        this->data[object_id].max_x = -1;
        this->data[object_id].max_y = -1;
    }
}

/**
 * @brief Draws a tooltip at the specified screen coordinates with formatted text.
 *
 * This function formats the input text with variadic arguments and displays it at the given position
 * on the graphical user interface as a tooltip.
 *
 * @param x The x-coordinate where the tooltip is to be displayed.
 * @param y The y-coordinate where the tooltip is to be displayed.
 * @param text The base text for the tooltip, supporting variadic arguments for additional formatting.
 * @return The result code from the tooltip rendering function, indicating success or failure.
 */
int interface_gui::draw_tool_tip(int x, int y, LPCSTR text, ...)
{
    if (!text)
    {
        pDrawMessage("[draw_tool_tip] Error: The text is empty.", 1);
        return -1;
    }

    if (std::strchr(text, '%') != nullptr)
    {
        pDrawMessage("[draw_tool_tip] Error: The text contains arguments but they have no value.", 1);
        pDrawMessage(text, 1);
        return -1;
    }

    char      buff[2048];
    const int buff_len = sizeof(buff);
    ZeroMemory(buff, buff_len);

    va_list args;
    va_start(args, text);
    const int buff_add_size = vsnprintf_s(buff, buff_len, _TRUNCATE, text, args);
    va_end(args);

    if (buff_add_size < 0 || buff_add_size >= buff_len)
    {
        pDrawMessage("[draw_message] Error: vsnprintf_s failed to process message.", 2);
        return -1;
    }

    return pDrawToolTip(x, y, buff);
}

/**
 * @brief Draws a formatted message to the graphical user interface.
 *
 * This function processes the input text with optional variadic arguments, applies formatting,
 * and renders it using the specified mode. The formatted message is stored in a temporary buffer
 * and then passed to the drawing function.
 *
 * @param mode Specifies the display mode or behavior for the message rendering.
 * @param text The formatted string to be rendered. This supports variadic arguments for dynamic text formatting.
 * @return The result code from the rendering function, indicating success or failure.
 */
int interface_gui::draw_message(int mode, LPCSTR text, ...)
{
    if (!text)
    {
        pDrawMessage("[draw_message] Error: The text is empty.", 1);
        return -1;
    }

    if (std::strchr(text, '%') != nullptr)
    {
        pDrawMessage("[draw_message] Error: The text contains arguments but they have no value.", 1);
        pDrawMessage(text, 1);
        return -1;
    }

    char      buff[2048];
    const int buff_len = sizeof(buff);
    ZeroMemory(buff, buff_len);

    va_list args;
    va_start(args, text);
    const int buff_add_size = vsnprintf_s(buff, buff_len, _TRUNCATE, text, args);
    va_end(args);

    if (buff_add_size < 0 || buff_add_size >= buff_len)
    {
        pDrawMessage("[draw_message] Error: vsnprintf_s failed to process message.", 2);
        return -1;
    }

    return pDrawMessage(buff, mode);
}

/**
 * @brief Draws formatted text with specific attributes to the graphical interface.
 *
 * This function renders multi-line formatted text at a given position on the screen, allowing
 * for alignment and color customization. The text is separated into lines based on newline
 * characters, and each line is drawn individually with an incremental vertical position.
 *
 * @param color The color of the text to be drawn.
 * @param pos_x The horizontal position where the text rendering starts.
 * @param pos_y The vertical position where the text rendering starts.
 * @param width The maximum width allowed for the text rendering. This determines alignment and wrapping rules.
 * @param align Specifies the alignment of the text (e.g., left, center, right).
 * @param text The formatted string to be drawn. This supports variable arguments for dynamic text formatting.
 * @return The vertical position (pos_y) after the last line of text has been rendered.
 */
int interface_gui::draw_format(const DWORD  color, const int pos_x, const int pos_y, const int width, const int align,
                               const LPCSTR text, ...)
{
    if (!text)
    {
        pDrawMessage("[draw_format] Error: The text is empty.", 1);
        return -1;
    }

    if (std::strchr(text, '%') != nullptr)
    {
        pDrawMessage("[draw_format] Error: The text contains arguments but they have no value.", 1);
        pDrawMessage(text, 1);
        return -1;
    }

    char      buff[2048];
    const int buff_len = sizeof(buff);
    ZeroMemory(buff, buff_len);

    va_list args;
    va_start(args, text);
    const int buff_add_size = vsnprintf_s(buff, buff_len, _TRUNCATE, text, args);
    va_end(args);

    if (buff_add_size < 0 || buff_add_size >= buff_len)
    {
        pDrawMessage("[draw_format] Error: vsnprintf_s failed to process message.", 1);
    }

    char*       context = nullptr;
    const char* line    = strtok_s(buff, "\n", &context);

    int current_y = pos_y;

    while (line != nullptr)
    {
        pDrawColorText(reinterpret_cast<LPCTSTR>(line), pos_x, pos_y, width, 0, static_cast<int>(color), 0, align);
        current_y += 10;
        line      = strtok_s(nullptr, "\n", &context);
    }

    return current_y;
}

void interface_gui::draw_text(HFONT font, int     PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height,
                              BYTE  Align, LPCSTR Text, ...)
{
    if (!Text)
    {
        pDrawMessage("[draw_format] Error: The text is empty.", 1);
        return;
    }

    if (std::strchr(Text, '%') != nullptr)
    {
        pDrawMessage("[draw_format] Error: The text contains arguments but they have no value.", 1);
        pDrawMessage(Text, 1);
        return;
    }

    char Buff[2048];
    int  BuffLen = sizeof(Buff) - 1;
    ZeroMemory(Buff, BuffLen);

    va_list args;
    va_start(args, Text);
    int Len = vsnprintf_s(Buff, BuffLen, Text, args);
    va_end(args);

    int LineCount = 0;

    char* next_token = nullptr;
    char* Line       = strtok_s(Buff, "\n", &next_token);

    while (Line != NULL)
    {
        pSetTextSize(pTextThis(), font);
        pSetTextColor(pTextThis(),
                      static_cast<BYTE>((color & 0xff000000) >> 24),
                      static_cast<BYTE>((color & 0x00ff0000) >> 16),
                      static_cast<BYTE>((color & 0x0000ff00) >> 8),
                      static_cast<BYTE>(color & 0x000000ff));
        pSetBackgroundTextColor(pTextThis(),
                                static_cast<BYTE>((bkcolor & 0xff000000) >> 24),
                                static_cast<BYTE>((bkcolor & 0x00ff0000) >> 16),
                                static_cast<BYTE>((bkcolor & 0x0000ff00) >> 8),
                                static_cast<BYTE>(bkcolor & 0x000000ff));
        pDrawText(pTextThis(), PosX, PosY, reinterpret_cast<LPCTSTR>(Line), Width, Height,
                  reinterpret_cast<LPINT>(Align), 0);
        PosY += 10;
        Line = strtok_s(nullptr, "\n", &next_token);
    }
}

/**
 * @brief Draws a button with specified position and scaling factors.
 *
 * This function renders a button on the graphical interface at a given position with
 * the specified scaling properties. If the button's position has not been initialized,
 * it updates the button's coordinates and boundaries based on its width and height.
 *
 * @param object_id The unique identifier of the button to be drawn.
 * @param pos_x The horizontal position where the button will be rendered.
 * @param pos_y The vertical position where the button will be rendered.
 * @param scale_x The scaling factor in the horizontal direction.
 * @param scale_y The scaling factor in the vertical direction.
 */
void interface_gui::draw_button(short object_id, float pos_x, float pos_y, float scale_x, float scale_y)
{
    if (static_cast<int>(this->data[object_id].x) == -1 || static_cast<int>(this->data[object_id].y) == -1)
    {
        this->data[object_id].x     = pos_x;
        this->data[object_id].y     = pos_y;
        this->data[object_id].max_x = pos_x + this->data[object_id].width;
        this->data[object_id].max_y = pos_y + this->data[object_id].height;
    }

    pDrawButton(
        this->data[object_id].model_id,
        pos_x,
        pos_y,
        this->data[object_id].width,
        this->data[object_id].height,
        scale_x,
        scale_y
    );
}

/**
 * @brief Draws a colored graphical user interface element at a specified position.
 *
 * This method renders a GUI element with the specified characteristics, including position
 * and color. It updates the object's coordinates and maximum boundaries if they are uninitialized.
 * It also relies on an external function to handle the actual graphical rendering of the colored GUI element.
 *
 * @param object_id The unique identifier of the GUI object to be drawn.
 * @param x The horizontal position where the GUI object will be rendered.
 * @param y The vertical position where the GUI object will be rendered.
 * @param color The color used to render the GUI object, specified as a DWORD value.
 */
void interface_gui::draw_colored_gui(short object_id, float x, float y, DWORD color)
{
    if (static_cast<int>(this->data[object_id].x) == -1 || static_cast<int>(this->data[object_id].y) == -1)
    {
        this->data[object_id].x     = x;
        this->data[object_id].y     = y;
        this->data[object_id].max_x = x + this->data[object_id].width;
        this->data[object_id].max_y = y + this->data[object_id].height;
    }

    pDrawColorButton(
        this->data[object_id].model_id,
        x,
        y,
        this->data[object_id].width,
        this->data[object_id].height,
        0,
        0,
        color
    );
}

float interface_gui::draw_repeat_gui(short object_id, float x, float y, int count) const
{
    float start_y = y;

    for (int i = 0; i < count; i++)
    {
        pDrawGUI(
            this->data[object_id].model_id,
            x,
            start_y,
            this->data[object_id].width,
            this->data[object_id].height
        );

        start_y += this->data[object_id].height;
    }

    return start_y;
}

/**
 * @brief Renders a graphical item in the interface.
 *
 * This method draws an item on the graphical user interface, considering its position,
 * dimensions, and other properties. It applies transformations, blending, and utilizes
 * OpenGL functionality to display the item. The rendering behavior may vary based on the item ID
 * and other parameters, such as its properties and effects. The function ensures that various
 * rendering configurations are applied, making use of additional internal rendering utilities.
 *
 * @param pos_x The horizontal position of the item on the screen.
 * @param pos_y The vertical position of the item on the screen.
 * @param width The width of the item.
 * @param height The height of the item.
 * @param item_id The unique identifier of the item to be rendered.
 * @param level The enhancement level of the item.
 * @param excl A flag indicating whether the item has special effects or exclusive properties.
 * @param anc A flag indicating if the item has any ancients applied.
 * @param on_mouse A boolean flag determining if the item is currently hovered or interacted with by the mouse.
 */
void interface_gui::draw_item(
    float pos_x,
    float pos_y,
    float width,
    float height,
    int   item_id,
    int   level,
    int   excl,
    int   anc,
    bool  on_mouse)
{
    if (combined_checks())
    {
        return;
    }

    EnableAlphaTest(true);
    glMatrixMode(0x1701);
    glPushMatrix();
    glLoadIdentity();

    glViewport2(
        0,
        0,
        *reinterpret_cast<GLsizei*>(MAIN_RESOLUTION_X),
        *reinterpret_cast<GLsizei*>(MAIN_RESOLUTION_Y)
    );

    const float v2 = *reinterpret_cast<float*>(MAIN_RESOLUTION_X) / *reinterpret_cast<float*>(MAIN_RESOLUTION_Y);

    if (item_id == 406)
    {
        // bmd size
        gluPerspective2(0.4f, v2, *reinterpret_cast<float*>(0xE61E38), *reinterpret_cast<float*>(0xE61E3C));
    }
    else if (item_id == 407)
    {
        // bmd size
        gluPerspective2(0.5f, v2, *reinterpret_cast<float*>(0xE61E38), *reinterpret_cast<float*>(0xE61E3C));
    }
    else
    {
        // bmd size
        gluPerspective2(0.7f, v2, *reinterpret_cast<float*>(0xE61E38), *reinterpret_cast<float*>(0xE61E3C));
    }

    glMatrixMode(0x1700);
    glPushMatrix();
    glLoadIdentity();

    GetOpenGLMatrix(0x87933A0);
    EnableDepthTest();
    EnableDepthMask();

    //posX 
    //posY
    //Width
    //Height
    //unk
    // 1 - Excellent Effect
    // 1 - Aura +7
    // 1 - original size
    glClear(0x100);

    VAngle v45;

    unsigned char v44 = 1; //0 = idle / 1 = rotating

    sub_6359B0_Addr(static_cast<int>(pos_x), static_cast<int>(pos_y), reinterpret_cast<int>(&v45), 0); //position of bmd
    sub_5CA0D0_Addr(item_id, level, excl, anc, reinterpret_cast<int>(&v45), v44, 0); //function that shows the bmd

    sub_636720_Addr();

    glMatrixMode(0x1700);
    glPopMatrix();
    glMatrixMode(0x1701);
    glPopMatrix();

    sub_637770_Addr();

    glColor3f(1, 1, 1);
    EnableAlphaTest(false);
}

/**
 * @brief Checks whether a specified interface window is currently active or open.
 *
 * This method determines if a specific interface window, identified by the given window ID,
 * is currently active or displayed. It relies on internal function calls to perform the check.
 *
 * @param window_id The ID of the window to be checked.
 * @return A boolean value indicating whether the specified window is active (true) or inactive (false).
 */
bool interface_gui::check_window(int window_id)
{
    return pCheckWindow(pWindowThis(), window_id);
}

/**
 * @brief Closes a specified interface window.
 *
 * This method triggers the closing of an interface window identified by the given window ID.
 * It uses internal logic to interact with relevant functions for closing the window.
 *
 * @param window_id The ID of the window to be closed.
 * @return The result of the window closing operation, typically a status code indicating success or failure.
 */
int interface_gui::close_window(int window_id)
{
    return pCloseWindow(pWindowThis(), window_id);
}

/**
 * @brief Opens a specified interface window.
 *
 * This method triggers the opening of an interface window identified by the given window ID.
 * It utilizes internal logic to handle the window opening process, interacting
 * with relevant internal functions.
 *
 * @param window_id The ID of the window to be opened.
 * @return The result of the window opening operation, typically a status code indicating success or failure.
 */
int interface_gui::open_window(int window_id)
{
    return pOpenWindow(pWindowThis(), window_id);
}

/**
 * @brief Determines whether the cursor is within the work zone of the specified object.
 *
 * This function checks if the current cursor position falls within the boundaries of the work zone
 * of a specific object. The boundaries are defined by the object's position and size stored in the data array.
 *
 * @param object_id The ID of the object whose work zone is being evaluated.
 * @return `true` if the cursor is within the work zone of the object, `false` otherwise.
 */
bool interface_gui::is_work_zone(short object_id) const
{
    if (static_cast<float>(g_obj_user.m_cursor_x) < this->data[object_id].x ||
        static_cast<float>(g_obj_user.m_cursor_x) > this->data[object_id].max_x ||
        static_cast<float>(g_obj_user.m_cursor_y) < this->data[object_id].y ||
        static_cast<float>(g_obj_user.m_cursor_y) > this->data[object_id].max_y)
    {
        return false;
    }

    return true;
}

float interface_gui::get_position_screen(float position, bool isPositionY)
{
    if (isPositionY)
    {
        return position / g_fScreenRate_y;
    }

    return position / g_fScreenRate_x;
}

float interface_gui::get_scale_screen(int size)
{
    float size_screen = static_cast<float>(size);

    if (size_screen < 16)
    {
        return size_screen / 16;
    }

    if (size_screen < 32)
    {
        return size_screen / 32;
    }

    if (size_screen < 64)
    {
        return size_screen / 64;
    }

    if (size_screen < 128)
    {
        return size_screen / 128;
    }

    if (size_screen < 256)
    {
        return size_screen / 256;
    }

    if (size_screen < 512)
    {
        return size_screen / 512;
    }

    if (size_screen < 1024)
    {
        return size_screen / 1024;
    }

    return size_screen / 2048;
}

/**
 * @brief Checks whether any combination of specific windows is currently active.
 *
 * This function evaluates the states of different windows to check if any predefined
 * combination of windows is open. If any of the specified single windows or group
 * combinations are detected as active, the function returns `true`. Otherwise, it
 * returns `false`.
 *
 * @return `true` if any of the defined windows or window combinations is active,
 *         `false` otherwise.
 */
bool interface_gui::combined_checks()
{
    if (check_window(MoveList) ||
        check_window(CashShop) ||
        check_window(SkillTree) ||
        check_window(FullMap) ||
        (check_window(Inventory) &&
            check_window(ExpandInventory) &&
            check_window(Store)) ||
        (check_window(Inventory) &&
            check_window(Warehouse) &&
            check_window(ExpandWarehouse)) ||
        (check_window(Inventory) &&
            check_window(Character) &&
            check_window(Store)))
    {
        return true;
    }

    return false;
}

/**
 * @brief Determines whether the current map allows operations defined by the interface GUI.
 *
 * This function checks the current map number assigned to the `gObjUser.m_MapNumber` variable
 * and evaluates whether the map is restricted or allowed for specific functionality.
 * For the maps predefined in the cases of the `switch` statement, the function returns `false`,
 * indicating restricted functionality.
 * If the map is not predefined in the `switch` cases, the function returns `true`.
 *
 * @return `true` if the current map is allowed, `false` if the map is restricted.
 */
bool interface_gui::check_map()
{
    switch (g_obj_user.m_map_number)
    {
        case Lorencia:
        case Dungeon:
        case Devias:
        case Noria:
        case LostTower:
        case Atlans:
        case Tarkan:
        case Elbeland:
        case Icarus:
        case Trials:
        case Aida:
        case Crywolf:
        case Kanturu1:
        case Kanturu3:
        case Barracks:
        case Calmness:
        case Raklion:
        case Vulcanus:
        case Karutan1:
        case Karutan2:
            return false;
        default:
            return true;
    }
}
