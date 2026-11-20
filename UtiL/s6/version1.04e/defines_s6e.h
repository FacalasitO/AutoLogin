#pragma once

// Utilidades
#define Naked(Function)				void __declspec(naked) Function()
#define _FC							__fastcall
#define _CD							__cdecl
#define ITEM_INTER					1171
#define ITEM_BASE_MODEL             1171
#define GET_ITEM(x, y)				((x * 512) + y)
#define GET_ITEM2(x, y)				((x * 512) + y + ITEM_INTER)
#define FULL_X_IN_GAME_X(x)			( (640 * x) / pWinWidth)
#define FULL_Y_IN_GAME_Y(x)			( (480 * x) / pWinHeight)
#define MAX_ITEM                    (MAX_ITEM_SECTION*MAX_ITEM_TYPE)
#define Color4f(r, b, g, o)			((o << 24) + (g << 16) + (b << 8) + r)
#define IS_NEWWINGS(x)				((x < ITEM(12, 180)) ? FALSE : (x > ITEM(12, 215)) ? FALSE : TRUE)
#define CS_GET_WEAPON(x, y)			( y | (16 * (x & 0xF0)) )
#define CS_GET_HELM(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 7) & 1) + (y >> 4) )
#define CS_GET_ARMOR(x, y, z)		( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 6) & 1) + (y & 0xF) )
#define CS_GET_PANTS(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 5) & 1) + (y >> 4) )
#define CS_GET_GLOVES(x, y, z)		( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 4) & 1) + (y & 0xF) )
#define CS_GET_BOOTS(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 3) & 1) + (y >> 4) )
#define MAX_ITEMOPT_BIT				0x3F
#define GET_ITEMOPT_LEVEL(x)		((x >> 3) & 0xF)
#define SET_ITEMOPT_LEVEL(x)		(x << 3)
#define GET_ITEMOPT0(x)				(x & 3)
#define GET_ITEMOPT16(x)			(x & 0x40)
#define GET_ITEMOPT_SKILL(x)		(x >> 7)
#define GET_ITEMOPT_LUCK(x)			((x >> 2) & 1)
#define GET_ITEMOPT_0(x)			(x & 1)
#define GET_ITEMOPT_1(x)			(((x & MAX_ITEMOPT_BIT) >> 1) & 1)
#define GET_ITEMOPT_2(x)			(((x & MAX_ITEMOPT_BIT) >> 2) & 1)
#define GET_ITEMOPT_3(x)			(((x & MAX_ITEMOPT_BIT) >> 3) & 1)
#define GET_ITEMOPT_4(x)			(((x & MAX_ITEMOPT_BIT) >> 4) & 1)
#define GET_ITEMOPT_5(x)			(((x & MAX_ITEMOPT_BIT) >> 5) & 1)
#define MAX_ACCOUNT_LEVEL           4
#define GetCharacterItem(x)         ((*(DWORD*)MAIN_CHARACTER_STRUCT)+0x1240 + x * 0x6B)

// Data Game
enum: DWORD
{
    MAIN_WINDOW             = 0xE8C578,
    MAIN_LANGUAGE           = 0xE8C5C4,
    MAIN_CONNECTION_STATUS  = 0x8793704,
    MAIN_SCREEN_STATE       = 0xE609E8,
    MAIN_CHARACTER_STRUCT   = 0x8128AC8,
    MAIN_VIEWPORT_STRUCT    = 0x7BC4F04,
    MAIN_PACKET_SERIAL      = 0x8793700,
    MAIN_HELPER_STRUCT      = 0xE8CB7C,
    MAIN_FONT_SIZE          = 0x81C0380,
    MAIN_RESOLUTION         = 0xE8C240,
    MAIN_RESOLUTION_X       = 0xE61E58,
    MAIN_RESOLUTION_Y       = 0xE61E5C,
    MAIN_PARTY_MEMBER_COUNT = 0x81F6B6C
};

enum: DWORD
{
    HDK_SET_ITEM_EFFECT       = 0x57AD82, //0x52B0DB
    HDK_SET_COLOR_EFFECT      = 0x57AEFA, //0x52B122
    HDK_ITEM_EFFECT_ALLOW     = 0x57AD8D, //0x52B0E7
    HDK_ITEM_EFFECT_NOT_ALLOW = 0x57B73B, //0x52B9E0
    HDK_NEXT_ITEM_COLOR       = 0x57AF2E  //0x52B150
};

// Virtual Key
enum: BYTE
{
    VK_0 = 0x30,
    VK_1 = 0x31,
    VK_2 = 0x32,
    VK_3 = 0x33,
    VK_4 = 0x34,
    VK_5 = 0x35,
    VK_6 = 0x36,
    VK_7 = 0x37,
    VK_8 = 0x38,
    VK_9 = 0x39,
    VK_A = 0x41,
    VK_B = 0x42,
    VK_C = 0x43,
    VK_D = 0x44,
    VK_E = 0x45,
    VK_F = 0x46,
    VK_G = 0x47,
    VK_H = 0x48,
    VK_I = 0x49,
    VK_J = 0x4A,
    VK_K = 0x4B,
    VK_L = 0x4C,
    VK_M = 0x4D,
    VK_N = 0x4E,
    VK_O = 0x4F,
    VK_P = 0x50,
    VK_Q = 0x51,
    VK_R = 0x52,
    VK_S = 0x53,
    VK_T = 0x54,
    VK_U = 0x55,
    VK_V = 0x56,
    VK_W = 0x57,
    VK_X = 0x58,
    VK_Y = 0x59,
    VK_Z = 0x5A
};

// Max Const
enum: WORD
{
    MAX_CHAT_TYPE1          = 10,
    MAX_CUSTOM_WING         = 100,
    MAX_DYNAMIC_WING_EFFECT = 1500,
    MAX_CUSTOM_WING_EFFECT  = 3000,
    MAX_ITEM_SECTION        = 16,
    MAX_ITEM_TYPE           = 512
};

namespace ASM
{
    enum: BYTE
    {
        JMP   = 0xE9,
        JE    = 0x74,
        JNE   = 0x75,
        JGE   = 0x7D,
        NOP   = 0x90,
        CALL  = 0xE8,
        CALLD = 0xFF,
        PUSH  = 0x68,
    };
}

enum eObjectType: BYTE
{
    emPlayer  = 1,
    emMonster = 2,
    emNPC     = 4,
    emNone    = 8,
};

enum eClassNumber: BYTE
{
    CLASS_WIZARD   = 0,
    CLASS_KNIGHT   = 1,
    CLASS_ELF      = 2,
    CLASS_MAGUMSA  = 3,
    CLASS_DARKLORD = 4,
    CLASS_SUMMONER = 5,
    CLASS_MONK     = 6,
};

enum eClassCode: BYTE
{
    DarkWizard  = 0,
    SoulMaster  = 8,
    GrandMaster = 24,

    DarkKnight  = 1,
    BladeKnight = 9,
    BladeMaster = 25,

    Elf      = 2,
    MuseElf  = 10,
    HightElf = 26,

    MagicGladiator = 3,
    DuelMaster     = 19,

    DarkLord    = 4,
    LordEmperor = 28,

    Summoner        = 5,
    BloodySummoner  = 13,
    DimensionMaster = 29,

    RageFighter = 6,
    FirstMaster = 16
};

enum ObjState: BYTE
{
    SelectServer    = 2,
    SwitchCharacter = 4,
    GameProcess     = 5,
};

enum ObjWindow: BYTE
{
    FriendList       = 1,
    MoveList         = 2,
    Party            = 3,
    Quest            = 4,
    NPC_Devin        = 5,
    Guild            = 6,
    Trade            = 7,
    Warehouse        = 8,
    ChaosBox         = 9,
    CommandWindow    = 10,
    PetInfo          = 11,
    Shop             = 12,
    Inventory        = 13,
    Store            = 14,
    OtherStore       = 15,
    Character        = 16,
    DevilSquare      = 19,
    BloodCastle      = 20,
    CreateGuild      = 21,
    GuardNPC         = 22,
    SeniorNPC        = 23,
    GuardNPC2        = 24,
    CastleGateSwitch = 25,
    CatapultNPC      = 26,
    CrywolfGate      = 29,
    IllusionTemple   = 30,
    HeroList         = 32,
    ChatWindow       = 33,
    FastMenu         = 34,
    Options          = 35,
    Help             = 36,
    FastDial         = 39,
    SkillTree        = 57,
    GoldenArcher1    = 58,
    GoldenArcher2    = 59,
    LuckyCoin1       = 60,
    LuckyCoin2       = 61,
    NPC_Duel         = 62,
    NPC_Titus        = 63,
    CashShop         = 65,
    Lugard           = 66,
    QuestList1       = 68,
    QuestList2       = 69,
    Jerint           = 70,
    FullMap          = 72,
    NPC_Dialog       = 73,
    GensInfo         = 74,
    NPC_Julia        = 75,
    NPC_ChaosMix     = 76,
    ExpandInventory  = 77,
    ExpandWarehouse  = 78,
    MuHelper         = 79,
};;

enum eTextColors: BYTE
{
    White      = 0x0,
    Blue       = 0x1,
    Red        = 0x2,
    Gold       = 0x3,
    Green      = 0x4,
    WhiteRed   = 0x5,
    Violet     = 0x6,
    WhiteBlue  = 0x7,
    WhiteBeige = 0x8,
    GreenBlue  = 0x9,
    Gray       = 0xA,
    DarkViolet = 0xB,
};

enum eTextWeight: BYTE
{
    Bold   = 0x1,
    Normal = 0x0,
};

enum ColorLine2: BYTE
{
    TEXT_COLOR_WHITE = 0,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_RED,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_DARKRED,
    TEXT_COLOR_PURPLE,
    TEXT_COLOR_DARKBLUE,
    TEXT_COLOR_DARKYELLOW,
    TEXT_COLOR_GREEN_BLUE,
    TEXT_COLOR_GRAY,
    TEXT_COLOR_REDPURPLE,
    TEXT_COLOR_VIOLET,
    TEXT_COLOR_ORANGE = 13,
};

namespace eItemOption
{
    enum : BYTE
    {
        Damage         = 80, //-> Additional Damage +<N>
        WizardryDamage = 81,
        CurseSpell     = 82,
        Defense        = 84, //-> Additional Defense +<N>
        Luck           = 85, //-> Default: 0
        HPRecovery     = 86,

        LifeIncrease   = 87, //-> Increase Max HP +4%%
        ManaIncrease   = 88, //-> Increase Max Mana +4%%
        DamageDecrease = 89, //-> Damage Decrease +4%%
        Reflect        = 90, //-> Reflect Damage +5%%
        DefenseSuccess = 91, //-> Defense success rate +10%%
        IncreaseZen    = 92, //-> Increases acquisition rate of Zen after hunting monsters +30%%

        ExcellentDamage  = 93, //-> Excellent Damage rate +10%%
        DamageByLevel    = 94, //-> Increase Damage +level/20
        IncreaseDamage   = 95, //-> Increase Damage +%d%%
        IncreaseWizardry = 96, //-> Increase Wizardry Dmg +level/20
        IncreaseSpeed    = 98, //-> Increase Attacking(Wizardry)speed +%d
        IgnorOpDefense   = 103,
        ReturnAttack     = 106, //-> Return's the enemy's attack power in <N>%
        CompleteLife     = 107, //-> Complete recovery of life in <N>% rate
        CompleteMana     = 108, //-> Complete recovery of Mana in <N>% rate

        IncreaseWizardryDmg = 97,  //-> Increase Wizardry Dmg +2%
        LifePerMob          = 99,  //-> Increases acquisition rate of Life after hunting monsters +life/8
        ManaPerMob          = 100, //-> Increases acquisition rate of Mana after hunting monsters +Mana/8
    };
};

enum ColorMacro
{
    eTextShop      = Color4f(0xFFu, 0xDCu, 0x96u, 0xFFu),
    eExcellentS15  = Color4f(67, 204, 65, 255),
    eBlack         = Color4f(0, 0, 0, 255),
    eShinyGreen    = Color4f(172, 255, 56, 255),
    eShinyGreen100 = Color4f(172, 255, 56, 100),
    eGold          = Color4f(255, 189, 25, 255),
    eGold150       = Color4f(255, 189, 25, 150),
    eGold180       = Color4f(255, 189, 25, 180),
    eWhite         = Color4f(255, 255, 255, 255),
    eWhite150      = Color4f(255, 255, 255, 150),
    eWhite180      = Color4f(255, 255, 255, 180),
    eOrange        = Color4f(255, 105, 25, 255),
    eGray100       = Color4f(211, 211, 211, 100),
    eGray150       = Color4f(50, 50, 50, 150),
    eGray190       = Color4f(50, 50, 50, 190),
    eBlowPink      = Color4f(220, 20, 60, 255),
    eRed           = Color4f(225, 0, 0, 255),
    eRed2          = Color4f(225, 95, 45, 255),
    eExcellent     = Color4f(0, 225, 139, 255),
    eAncient       = Color4f(1, 223, 119, 255),
    eSocket        = Color4f(153, 102, 204, 255),
    eBlue          = Color4f(36, 242, 252, 255),
    eBlue250       = Color4f(36, 242, 252, 250),
    eYellow        = Color4f(255, 255, 0, 255),
    eYellow170     = Color4f(255, 255, 0, 170),
    eBrown         = Color4f(69, 39, 18, 255),
    eColorAdvance  = Color4f(109, 25, 192, 255),
    eColorHealth   = Color4f(191, 191, 146, 255),
};

namespace TextAlign
{
    enum: BYTE
    {
        Left = 1,
        Center = 3,
        Right = 4
    };
}

enum eMapNumber: BYTE
{
    Lorencia      = 0,
    Dungeon       = 1,
    Devias        = 2,
    Noria         = 3,
    LostTower     = 4,
    Exile         = 5,
    Stadium       = 6,
    Atlans        = 7,
    Tarkan        = 8,
    DevilSquaree  = 9,
    Icarus        = 10,
    BloodCastle1  = 11,
    BloodCastle2  = 12,
    BloodCastle3  = 13,
    BloodCastle4  = 14,
    BloodCastle5  = 15,
    BloodCastle6  = 16,
    BloodCastle7  = 17,
    ChaosCastle1  = 18,
    ChaosCastle2  = 19,
    ChaosCastle3  = 20,
    ChaosCastle4  = 21,
    ChaosCastle5  = 22,
    ChaosCastle6  = 23,
    Kalima1       = 24,
    Kalima2       = 25,
    Kalima3       = 26,
    Kalima4       = 27,
    Kalima5       = 28,
    Kalima6       = 29,
    Kalima7       = 36,
    Loren         = 30,
    Trials        = 31,
    DevilSquare6  = 32,
    Aida          = 33,
    Crywolf       = 34,
    Kanturu1      = 37,
    Kanturu3      = 38,
    Kanturu_Event = 39,
    Silent        = 40,
    Barracks      = 41,
    Refuge        = 42,
    Illusion1     = 45,
    Illusion2     = 46,
    Illusion3     = 47,
    Illusion4     = 48,
    Illusion5     = 49,
    Illusion6     = 50,
    Elbeland      = 51,
    BloodCastle8  = 52,
    ChaosCastle7  = 53,
    Calmness      = 56,
    Raklion       = 57,
    RaklionBoss   = 58,
    SantaTown     = 62,
    Vulcanus      = 63,
    Collosseum    = 64,
    Karutan1      = 80,
    Karutan2      = 81
};
