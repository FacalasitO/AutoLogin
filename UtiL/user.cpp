#include "user.h"

#include "s6/version1.04e/defines_s6e.h"
#include "s6/version1.04e/import_s6e.h"

user g_obj_user;

/**
 * @brief Initializes the User object's dynamic properties to default or undefined states.
 *
 * This method resets critical User object properties to their initial values, ensuring a clean state for further processing.
 * It primarily sets internal variables such as target type, cursor coordinates, and map number to their default or "undefined" states.
 *
 * Key operations:
 * - Resets `m_TargetUpdateTick` to 0.
 * - Sets `m_TargetType` to `TARGET_TYPE_UNDEFINED`.
 * - Initializes `m_CursorX` and `m_CursorY` to -1.
 * - Sets `m_MapNumber` to -1.
 */
void user::load()
{
    this->m_target_update_tick = 0;
    this->m_target_type       = target_type_undefined;
    this->m_cursor_x          = -1;
    this->m_cursor_y          = -1;
    this->m_map_number        = -1;
}

/**
 * @brief Updates the properties and references of the User object, including position, cursor, map, and target information.
 *
 * This method refreshes the User object's state by reinitializing core object references and dynamically updating key properties such as
 * the current coordinates, cursor position, and map information. It also invokes the GetTarget method to determine and assign the current target.
 *
 * Key operations:
 * - Updates `lpPlayer` and `lpViewPlayer` pointers based on memory structure references.
 * - Retrieves and sets the player's map coordinates (`CoordenadaX` and `CoordenadaY`) from the view object.
 * - Updates cursor position (`m_CursorX` and `m_CursorY`) and current map number (`m_MapNumber`) based on external constants.
 * - Calls `GetTarget` to evaluate and assign the current target object and type.
 */
void user::refresh()
{
    this->lp_player     = reinterpret_cast<ObjectCharacter*>(oUserObjectStruct);
    this->lp_view_player = reinterpret_cast<ObjectPreview*>(oUserPreviewStruct);
    this->get_target();

    this->x_coordinate = static_cast<int>(this->lp_view_player->MapPosX);
    this->y_coordinate = static_cast<int>(this->lp_view_player->MapPosY);

    this->m_cursor_x   = pCursorX;
    this->m_cursor_y   = pCursorY;
    this->m_map_number = pMapNumber;
}

/**
 * @brief Determines and sets the target for the user's action, whether it is an NPC, an attack target, or undefined.
 *
 * This method evaluates if there is a valid NPC or attack target based on their IDs and assigns the relevant target information to the class,
 * including the target type. If no valid target is found, the target is cleared, and the type is marked as undefined.
 *
 * @return bool Returns true if a valid target is found (NPC or attack target), otherwise returns false.
 */
bool user::get_target()
{
    if (pViewNPCTargetID != -1)
    {
        this->lp_view_target = reinterpret_cast<ObjectPreview*>(pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID));
        this->m_target_type = target_type_npc;
        return true;
    }
    if (pViewAttackTargetID != -1)
    {
        this->lp_view_target = reinterpret_cast<ObjectPreview*>(pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID));
        this->m_target_type = target_type_attack;
        return true;
    }

    if (this->lp_view_target != 0)
    {
        ZeroMemory(&this->lp_view_target, sizeof(this->lp_view_target));
    }

    this->m_target_type = target_type_undefined;
    return false;
}

/**
 * @brief Retrieves the active skill for the main user character.
 *
 * This function accesses the main character's data and the viewport's
 * current active magic to determine and return the corresponding active skill
 * from the character's magic list.
 *
 * @return int The active skill ID for the main user character.
 */
int user::get_active_skill()
{
    lpCharObj lpPlayer     = &*reinterpret_cast<ObjectCharacter*>(*reinterpret_cast<int*>((MAIN_CHARACTER_STRUCT)));
    lpViewObj lpViewPlayer = &*reinterpret_cast<ObjectPreview*>(*reinterpret_cast<int*>((MAIN_VIEWPORT_STRUCT)));

    return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
}
