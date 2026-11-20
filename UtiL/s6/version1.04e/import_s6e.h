#pragma once

#define sub_959CE0					            ((int(__cdecl*)(DWORD, DWORD)) 0x959CE0)
#define sub_95A1E0					            ((int(__cdecl*)(DWORD a1, DWORD a2, float *a3)) 0x95A1E0)
//-- Call                                       
#define pCursorX					            *(int*)0x879340C // Get position X of the cursor in the game window
#define pCursorY					            *(int*)0x8793410 // Get position Y of the cursor in the game window
#define pIsKeyNone  				            ((bool(__cdecl*)(int vkCode)) 0x791030)
#define pIsKeyPressed				            ((bool(__cdecl*)(int vkCode)) 0x791040)
#define pIsKeyRelease			                ((bool(__cdecl*)(int vkCode)) 0x791050)
#define pIsKeyPress	                            ((bool(__cdecl*)(int vkCode)) 0x791070)
#define pIsKeyRepeat	                        ((bool(*__cdecl*(int vkCode)) 0x791090)
#define pWinWidth					            *(GLsizei*)0xE61E58
#define pWinHeight					            *(GLsizei*)0xE61E5C
#define g_fScreenRate_x				            *(float*)0xE7C3D4
#define g_fScreenRate_y				            *(float*)0xE7C3D8
#define pWinFontHeight				            *(int*)0x81C0380
#define oAllowGUI_Call1				            0x7D378E
#define oAllowGUI_Call2				            0x811C42
#define oDrawInterfaceS_Call		            0x4DA2AC
#define oDrawInterface_Call			            0x80F7FE
#define oLoadSomeForm_Call			            0x7C1D7E
#define pSetCursorFocus				            *(DWORD*)0xE8CB3C
#define pMonsterAttribute                       ((int(__cdecl*)(int ObjectPointer, int Type)) 0x580BB0)	//ObjectPointer is a Struct CHARACTER
#define pGetMapName				                ((char*(__cdecl*)(int MapNumber)) 0x5D2C10)

//-- Control Interface                          
#define glViewport2					            ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x6363D0)
#define gluPerspective2				            ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x6358A0)
#define GetOpenGLMatrix				            ((void(__cdecl*)(int a1)) 0x635830)
#define EnableDepthTest				            ((void(*)()) 0x635DE0)
#define EnableDepthMask				            ((void(*)()) 0x635E40)
#define CryingWolf2ndObjectVisual	            ((void(__cdecl*)(int a1, int a2)) 0x8D1C00)
#define EnableAlphaBlend			            ((void(__cdecl*)()) 0x636070)
#define EnableAlphaTest				            ((void(__cdecl*)(BYTE Mode)) 0x635FD0)
#define pDrawInterfaceS				            ((char(__cdecl*)()) 0x4D7970)
#define pDrawInterface				            ((void(__cdecl*)()) 0x80F8E0)
#define pDrawGUI					            ((void(__cdecl*)(DWORD, float, float, float, float)) 0x790B50)
#define pDrawToolTip				            ((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x597220)
#define pDrawButton					            ((void(__cdecl*)(DWORD ModelID, float X, float Y, float W, float H, float CurrentX, float CurrentY)) 0x790E40)
#define pDrawColorButton			            ((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x790F20)
#define pDrawExtraColor				            ((void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, DWORD)) 0x637A60)
#define pDrawMapObject				            ((void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, float, float, float, float, DWORD)) 0x638400)
#define pDrawInfoBox				            ((char(__cdecl*)(char Text, int Arg2)) 0x738200)
#define pDrawBarForm				            ((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
#define pGLSwitch					            ((void(__cdecl*)()) 0x635F50)
//-- Control Text                               
#define pSetTextSize				            ((int(__thiscall*)(LPVOID This, HFONT a2)) 0x420120)
#define pDrawMessage				            ((int(__cdecl*)(LPCSTR Text, int Mode)) 0x597630)
#define pMakeColor					            ((DWORD(__cdecl*)(BYTE, BYTE, BYTE, BYTE)) 0x412D20)
#define pTextThis					            ((LPVOID(*)()) 0x41FE10)
#define sub_401C10					            ((int(*)()) 0x401C10)
#define sub_50D100					            ((size_t(__cdecl*)(char * a1, char * a2, ...)) 0x50D100)
#define sub_41FF80					            ((int(__thiscall*)(LPVOID This)) 0x41FF80)
#define sub_9593B0					            ((int(__stdcall*)(HDC This, LPCSTR lpMultiByteStr, int, LPSIZE psizl)) 0x9593B0)
#define pSetBackgroundTextColor		            ((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x4200B0)
#define pTextFormat					            ((int(__cdecl*)(char * Buffer, int Arg2, int LineSize, LPCTSTR Text, int LineWidth, bool Arg6, BYTE Arg7)) 0x540880)
#define pDrawColorText			                ((int(__cdecl*)(LPCTSTR Text, int PosX, int PosY, int Width, int Height, int Color, int Arg7, int Align)) 0x7D04D0)
#define pDrawText					            ((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int Width, int Height, LPINT Align, int PaddingX)) 0x420150)
#define pSetTextColor				            ((void(__thiscall*)(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)) 0x420040)
#define pTextLineThis				            ((LPVOID(*)()) 0x8128ADC)
#define	pFontNormal				                *(HGDIOBJ*)0xE8C588
#define pFontBold				                *(HGDIOBJ*)0xE8C58C
#define pFontBigBold			                *(HGDIOBJ*)0xE8C590
#define pFontNormal2			                *(HGDIOBJ*)0xE8C594
//-- Control Model                              
#define pModelThis					            ((LPVOID(*)())0x4CDA10)
#define pGetModel					            ((LPVOID(__thiscall*)(LPVOID This, signed int a2)) 0x969C50)
#define pLoadImage					            ((int(__cdecl*)(char* Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x772330)
#define pDrawImage					            ((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float PaddingX, float PaddingY, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)) 0x637C60)
#define pLoadModel					            ((void(__cdecl*)(int ResourceID, char * Path, char * File, int Arg4)) 0x614D10)
#define pLoadTexture				            ((void(__cdecl*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x614710)
#define pInitModelData				            ((void(__cdecl*)()) 0x617D30)
#define pInitModelData2				            ((void(__cdecl*)()) 0x626190)
#define pInitTextureData			            ((void(__cdecl*)()) 0x61AED0)
#define pLoadSomeForm				            ((void(__cdecl*)()) 0x7C2050)
#define pDrawItemModel				            ((int(__cdecl*)(float PosX, float PosY, float Width, float Height, int ItemID, int a6, int a7, int a8, char a9)) 0x5CF310)
#define pGetPosFromAngle			            ((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x635B00)
//-- Control Window                             
#define pWindowThis					            ((LPVOID(*)()) 0x861110)
#define pCheckWindow				            ((bool(__thiscall*)(LPVOID This, int Code)) 0x85EC20)
#define pCloseWindow				            ((int(__thiscall*)(LPVOID This, int Code)) 0x85F9A0)
#define pOpenWindow					            ((int(__thiscall*)(LPVOID This, int Code)) 0x85EC50)
#define pOpenInfoBox				            ((bool(__cdecl*)(LPVOID This, int Arg2, float Arg3)) 0x790A10)
//-- Control Viewport                           
#define	pViewUnknownTargetID		            *(int*)0xE61728 //-- Item target
#define	pViewNPCTargetID			            *(int*)0xE6172C //-- NPC Select
#define	pViewAttackTargetID			            *(int*)0xE61730 //-- Attack Select
#define pPreviewThis				            ((LPVOID(*)()) 0x402BC0)
#define pClearPreviewThis			            ((LPVOID(*)()) 0x82C5C80)
#define pClearPreview				            ((void(__thiscall*)(LPVOID This)) 0x4CC780)
#define pGetPreviewStruct			            ((DWORD(__thiscall*)(LPVOID This, int ViewportID)) 0x96A4C0)
#define pPreviewCharSet				            ((void(__cdecl*)(int ObjectIndex, BYTE * CharSet, lpViewObj Object, int Mode)) 0x57FD90)

#define pAllowGUI					            ((bool(__cdecl*)()) 0x7D4250)

#define pCharacterBuf				            ((int(__thiscall*)(void *This, int a2)) 0x40FCA0)
#define CGetScreenWidth2			            ((signed int(*)()) 0x5C6E80)
//-- Control User                               
#define pPartyListStruct			            *(PartyList*)0x81CB4E8
#define pGetPartyStruct(Slot)		            ((Slot * sizeof(PartyList)) + (*(char**)pPartyListStruct))
#define pPartyMemberCount			            *(DWORD*)0x81F6B6C
#define pMapNumber					            *(int*)0xE61E18
#define pLastSkillIndex				            *(DWORD*)0x81C039C
#define oUserPreviewStruct			            *(int*)0x7BC4F04
#define oUserObjectStruct			            *(int*)0x8128AC8
#define oUserObjectStruct_			            *(int*)0x8128AC4
#define pMasterLevel				            *(short*)0x87935D8
#define pMasterPoint				            *(short*)0x87935F2
#define pMasterExp					            *(__int64*)0x87935E0
#define pMasterNextExp				            *(__int64*)0x87935E8
#define pFrameValue1				            *(BYTE*)(0x4D9F02 + 2)
#define pFrameValue2				            *(DWORD*)(0x4DA3B2 + 1)
#define pFrameValue3				            *(DWORD*)(0x4DA3DD + 3)
#define pFrameValue4				            *(BYTE*)(0x4DA3AC + 3)
#define pPlayerState				            *(int*)0xE609E8
#define pFrameLimit					            0//need check value inside struct
#define oBattleMapStart				            0x83165E
#define oBattleZoneStart			            0x5D3043
#define pMaxBattleZoneCount			            *(BYTE*)(0x5D3078 + 3)
#define oIsBattleServer_Call1		            0x5D303A
#define oIsBattleServer_Call2		            0x831651
#define pIsMaster					            ((bool(__cdecl*)(BYTE Class)) 0x5878E0)
#define pIsMaster2					            ((bool(__cdecl*)(BYTE Class)) 0x5875A0)
#define pGetCharClass				            ((BYTE(__cdecl*)(BYTE Class)) 0x405230)
#define pInitEventStatus			            ((void(__cdecl*)(int PreviewStruct)) 0x4EFF70)
#define pEventEffectThis			            ((LPVOID(__cdecl*)(int Arg1)) 0x9D00C5)
#define pAddEventEffect				            ((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, bool bFixRotation, float a5, float a6, float a7, float a8, float a9, float a10)) 0x4EFFF0)
#define pAddEventEffect2			            ((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, int a4, float a5, float a6, float a7)) 0x4F0730)
#define pPShopThis2					            ((LPVOID(__thiscall*)(LPVOID This)) 0x861400)
#define pPShopSet					            ((void(__thiscall*)(LPVOID This, BYTE Mode)) 0x840F70)
#define pPShopRefresh				            ((void(__cdecl*)(int Preview)) 0x6685B0)
#define pMUHelperThis				            ((LPVOID(__cdecl*)()) 0x4DB240)
#define pMUHelperClass				            *(int*)0xE8CB7C
#define pMUHelperClose				            ((void(__thiscall*)(LPVOID This)) 0x95D450)
#define pMUHelperStart				            ((void(__thiscall*)(LPVOID This)) 0x95D190)
#define pMUHelperDataSet			            ((bool(__thiscall*)(LPVOID This, LPBYTE Data)) 0x960C10)
#define pMUIsLoaded					            *(DWORD*)0xE60974
#define pWarehouseClass			                ((int(__cdecl*)()) 0x860FC0)
#define pWarehouseExThis			            ((int(__thiscall*)(LPVOID This)) 0x861A80)
#define pWarehouseExSet				            ((void(__thiscall*)(int Pointer, BYTE Status)) 0x856BD0)
#define pGameShopThis				            ((LPVOID(*)()) 0x93F370)
#define pGameShopGetGP				            ((double(__thiscall*)(LPVOID This)) 0x9405B0)
#define pUserStat					            ((LPVOID(*)()) 0x588D70)
#define pUpdateUserStat				            ((void(__thiscall*)(LPVOID This, int * Value, int Code)) 0x4EA460)


//-- Control Camera                             
#define oCam_Zoom					            0xD27BFC	//1037DB0
#define oCam_PosZDef				            0xD255AC	// Restore PosZ
#define oCam_PosZ					            0xD255A0	// PosZ
#define oCam_RotZ					            0x87933D8	//8B4ACC8
#define oCam_RotZDef				            0xD27B78	//1033AB0
#define oCam_RotY					            0xD27B88	//1033AC0
#define oCam_ClipX					            0xD2C848	//1038D28
#define oCam_ClipY					            0xD2C894	//1033A78
#define oCam_ClipZ					            0xD2C8B8	//1038D78
#define oCam_ClipXCS				            0xD2C898	//1038D58
#define oCam_ClipYCS				            0xD2C8A8	//1038D68
#define oCam_ClipX2					            0xD2C878	//1038D38
#define oCam_ClipY2					            0xD2C880	//1038D40
#define oCam_ClipZ2					            0xD2B94C	//1037DA4
#define oCam_ClipGL					            0xD2570C	//1031BCC
// Chat                                              
#define oCharColor_Loot				            (0x64B6AB + 1)
#define oCharColor_Exp				            (0x64C9A0 + 1)
#define pGetMoneyFormat				            ((int(__cdecl*)(double Value, char * Buff, int Arg3)) 0x5C1170)
#define pPlayEffectAnimation		            ((int(__cdecl*)(int EffectIndex, int PreviewStruct)) 0x667130)
#define oVulcanusMove				            (0x831BAC + 2)
#define oShowChatMessage_Call		            0x78B0BC
#define pShowChatMessage			            ((bool(__thiscall*)(LPVOID This)) 0x788A80)
#define pSetChatMessageType			            ((int(__thiscall*)(LPVOID This, int Type)) 0x78B870)
#define pChatThis					            ((LPVOID(__thiscall*)(LPVOID This)) 0x861220)
#define pChatIsClosed				            ((bool(__thiscall*)(LPVOID This)) 0x786110)
#define pChatCheckLevel				            ((bool(__cdecl*)(int MinLevel, char * Name)) 0x597E10)
#define pChatWhisperThis			            ((LPVOID(__thiscall*)(LPVOID This)) 0x861620)
#define pChatWhisperActive			            ((bool(__thiscall*)(LPVOID This)) 0x849E00)
#define pPlayBuffer			                    ((DWORD(__cdecl*)(DWORD Arg1, DWORD Arg2, DWORD Arg3)) 0x6D6C20)
#define pChatBoxThis				            ((DWORD(__thiscall*)(LPVOID This)) 0x861180)
#define pChatOutput					            ((void(__thiscall*)(DWORD This, char * Name, char * Message, DWORD Type, DWORD Arg4)) 0x7894E0)
#define pGetCommandLine				            ((LPSTR(WINAPI*)()) 0xD221C8)
#define pFrameSpeed1				            *(double*)0xD27C88
#define	pFrameSpeed2				            *(double*)0xD281C0
#define pIsDisconnect				            *(int*)0xE82C24
#define pCreateConnect				            ((int(__cdecl*)(char * IP, WORD Port)) 0x63C960)
#define pOnLine						            *(DWORD*)0x8793704
#define pMenuExitEvent				            ((DWORD(__cdecl*)(int Arg1)) 0x7A89D0)
#define pGameWindow					            *(HWND*)0xE8C578
#define pMUCommandLine				            (char*)0xE8C274
#define pGameLoad					            ((int(__cdecl*)()) 0x4D0FC0)
#define pGameResolutionMode			            *(int*)0xE8C240
#define pMoveListInit				            ((void(__thiscall*)(LPVOID This, int Arg1, int Arg2)) 0x830C10)
#define pTexEffect					            ((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x5468A0) //0x4E2E70
#define pChatSend				                ((int(__cdecl*)(LPCSTR Text)) 0x5BDE40)

#define pTransformPosition			            ((int(__thiscall*)(int This, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x545030)
#define pCustomEffGet2				            ((int(__thiscall*)(int This, int a2, float a3,int a4,float a5,float a6, float a7, int a8,int a9)) 0x5494C0) //0x4E597C
#define pGetTextLine				            ((char*(__thiscall*)(LPVOID This, int LineNumber)) 0x402320)
// ----------------------------------------------------------------------------------------------
//-> Item                                       
#define pGetItemColor				            ((void(__cdecl*)(int ModelID, float Arg2, float Arg3, VAngle * Color, bool BalrogMode)) 0x5F8C50)
#define pGetItemColor2				            ((void(__cdecl*)(int ModelID, float Arg2, float Arg3, VAngle * Color, bool BalrogMode)) 0x5FA4A0)
#define pSetItemPrice				            ((__int64(__cdecl*)(ObjectItem * lpItem, int Mode)) 0x58E3B0)
#define pIsExpensiveItem			            ((bool(__cdecl*)(ObjectItem * lpItem)) 0x5C81F0)
#define pIsUpgradeItem				            ((bool(__thiscall*)(LPVOID This, ObjectItem * lpSource, ObjectItem * lpTarget)) 0x7DDAC0)
#define pAllowRepairWings			            ((bool(__cdecl*)(ObjectItem * lpItem)) 0x5C9DA0)
#define pSetItemOptionText			            ((void(__cdecl*)(int ItemID, int Line, WORD OptionID, bool Arg4, int Arg5)) 0x5C2F70)
#define pSetItemTextLine			            ((void(__cdecl*)(int Line, LPSTR Text, ...)) 0x9CF6AA)
#define pIsWings					            ((int(__thiscall*)(LPVOID This, DWORD ItemID)) 0x7E7870)
#define pSetItemEffect				            ((void(__cdecl*)(int Arg1, int ModelID, VAngle Angle, int Arg4, int ItemLevel, char Arg6, int Arg7, int Arg8, int Arg9)) 0x609E70)
#define pSetItemEffect2				            ((void(__cdecl*)(float a4, float a5, float a6, lpViewObj Object, float a8, DWORD ModelID, int a10, char a11, char a12, char a13, signed int a14, char a15)) 0x5655C0)
#define pGetMaxDurability			            ((short(__cdecl*)(ObjectItem * lpItem, int ScriptStruct, int Level)) 0x5C2170)
#define pIsFlyingMauntToMove		            ((bool(__thiscall*)(LPVOID This, WORD ItemID1, WORD ItemID2)) 0x831B09)
#define pAllowStaticEffect			            ((void(__thiscall*)(LPVOID This, DWORD * Arg1, DWORD Arg2, int Arg3, int Arg4)) 0x544E60)
#define pPlayStaticEffect			            ((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, float Scale, float * Color, int Model, float a6, int a7)) 0x771310)
#define pPlayDynamicEffect			            ((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, int Arg2, float * Color, int Arg4, float Arg5, int Arg6)) 0x74CD30)

#define pItemBmdStruct				            *(ItemBmdStruct*)0x8128AC0
#define pGetItemBmdStruct(ItemId)               (ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct) * ItemId)

#define sub_636720_Addr				            ((int(*)())0x636720)
#define sub_637770_Addr				            ((void(*)()) 0x637770)
#define sub_6359B0_Addr				            ((int(__cdecl*)(int a1, int a2, int a3, char a4)) 0x6359B0)
#define SetTextColorByHDC			            ((int(__thiscall*)(LPVOID a1, int color)) 0x420080)

#define sub_41FFE0_Addr				            ((int(__thiscall*)(LPVOID a1)) 0x41FFE0)
#define sub_420010_Addr				            ((int(__thiscall*)(LPVOID a1)) 0x420010)
#define sub_4200F0_Addr				            ((int(__thiscall*)(LPVOID a1, int a2)) 0x4200F0)

#define pTest						            ((float(__cdecl*)(double))0x9CEBF0)
#define pGetAttackSpeed				            ((void(__thiscall*)()) 0x593B20)
#define Main_PrintGlobal                        0x597630H

#define pPetCall1					            ((LPVOID(__cdecl*)(int ID, int PetStruct, int PetObjectView, int Mode, int arg5)) 0x5013B0)
#define pPetCall2					            ((LPVOID(__cdecl*)(int ID, int PetStruct, int PetObjectView, int Mode, int arg5)) 0x501700)
#define oItemText_Color				            0x81C0A68
#define oItemText_Weight			            0x81C09F0
#define oItemText_Line				            0x81C0AE0
#define oItemText_Index				            0x81F6BF0

#define oItemTitleColor				            0x5C8261
#define oItemTitleColor_Next		            (oItemTitleColor + 8)
#define oItemTitleColor_Set			            0x5A9C00

#define oItemDescriptionText		            0x5AE921
#define oItemDescriptionText_Next	            0x5AE96C

#define pChatStructure				            0x8129540
#define pFpsTime					            0xE8CB30


//-> Monster                                    
#define oNpcName					            0x8119F68
#define pSendChatSay				            ((int(__cdecl*)(char * Name, char * Text, lpViewObj lpObject, int a4, int a5)) 0x5996A0)
#define pShowMonster				            ((lpViewObj(__cdecl*)(int MonsterID, int X, int Y, int a4)) 0x580FC0)
//CashShop                                      
#define	sub_944E50_Addr				            ((char(*)()) 0x944E50)
#define sub_93FCA0_Addr				            ((bool(__thiscall*)(int a1)) 0x93FCA0)
#define sub_93F600_Addr				            ((char(__thiscall*)(char* a1)) 0x93F600)
#define sub_93FD10_Addr				            ((bool(__thiscall*)(int a1)) 0x93FD10)
#define sub_93F950_Addr				            ((char(__thiscall*)(char* a1)) 0x93F950)
#define sub_941030_Addr				            ((int(__thiscall*)(BYTE* a1)) 0x941030)
#define sub_941000_Addr				            ((int(__thiscall*)(BYTE* a1)) 0x941000)
#define sub_944FE0_Addr				            ((void(__thiscall*)(BYTE *This, int a2, BYTE *a3)) 0x944FE0)
#define sub_9406C0_Addr				            ((char(__thiscall*)(BYTE* a1)) 0x9406C0)
#define sub_9406A0_Addr				            ((BYTE*(__thiscall*)(BYTE* a1, char a2)) 0x9406A0)
#define sub_8611E0_Addr				            ((int(__thiscall*)(DWORD* a1)) 0x8611E0)
#define sub_815130_Addr				            ((int(__thiscall*)(char *This, int a2, char a3)) 0x815130)
#define sub_861900_Addr				            ((int(__thiscall*)(int This)) 0x861900)
// ----------post item
#define ChatBoxMuObjectChatDataPtrArray			((MuObjectChatData **) (*(DWORD *) ((*(DWORD *) (0x9867090 + 0x10)) + 0x1C)))
#define ChatBoxMuObjectChatDataPtrFreeSlot		((MuObjectChatData *)  (*(DWORD *) ((*(DWORD *) (0x9867090 + 0x10)) + 0x20)))
#define ChatBoxMuObjectChatDataPtrLastSlot		((MuObjectChatData *)  (*(DWORD *) ((*(DWORD *) (0x9867090 + 0x10)) + 0x24)))
#define ChatBoxMuObjectChatDataPtrArrayLength	((DWORD) (((DWORD) ChatBoxMuObjectChatDataPtrFreeSlot - (DWORD) ChatBoxMuObjectChatDataPtrArray) / sizeof(DWORD)))
#define ChatBoxMuObjectChatDataPtrArraySize		((DWORD) ((((DWORD) ChatBoxMuObjectChatDataPtrLastSlot - (DWORD) ChatBoxMuObjectChatDataPtrArray) / sizeof(DWORD)) + 1))
#define pHandlePacketChatData		            ((void(__cdecl*)(const void * chat_msg)) 0x63F850)
#define oDrawInterface2_Call		            0x80F9AB //1.04D -> 0x80F85B
#define pCurrentViewingItemName		            (*(DWORD *) (0x7E4528 + 2)) //1.04D-> (0x7E43D8 + 2))
#define CharacterHeadChatTextFirst(x)			((char *) ((x) + 0x194))
#define CharacterHeadChatTextLast(x)			((char *) ((x) + 0x194 - 0x100))
//------------------------------------
//-- itemposition
#define sub_959A60_Addr				            ((int(__cdecl*)(int a1, float a2, int a3, int a4)) 0x959A60)
#define sub_4E1250_Addr				            ((int(__cdecl*)(int a1, char a2)) 0x4E1250)
#define sub_5C9370_Addr				            ((bool(__cdecl*)(signed int a1, int a2)) 0x5C9370)
#define sub_5440B0_Addr				            ((int(__fastcall*)(int a1, int a2, int a3, float a4, float a5, __int16 a6, int a7, int a8, char a9, char a10)) 0x5440B0)
#define sub_4CC650_Addr				            ((char *(__thiscall*)(int This)) 0x4CC650)
#define sub_5F58E0_Addr				            ((int(__cdecl*)(ObjectModel * a1)) 0x5F58E0)
#define sub_943A20_Addr				            ((int(__stdcall*)(float a1, float a2)) 0x943A20)
#define sub_5D65E0_Addr				            ((double(__thiscall*)(int This)) 0x5D65E0)
#define sub_4CC720_Addr				            ((int(__thiscall*)(int This)) 0x4CC720)

#define sub_5CA0D0_Addr				            ((void(__cdecl*)(signed int a1, signed int a2, int a3, int a4, int a5, int a6, char a7)) 0x5CA0D0)
#define sub_60FC70_Addr				            ((void (__cdecl*)(int a1, int a2, int a3, int a4, float a5, int a6, int a7, int a8, char a9, char a10, char a11, int a12, int a13)) 0x60FC70)
//-- custompet                                  
#define sub_4DB230					            ((int(*)())0x4DB230)
#define sub_9253D0					            ((int(__thiscall*)(int This,int a1, short a2)) 0x9253D0)
#define sub_5012D0					            ((DWORD(__cdecl*)(DWORD)) 0x5012D0)
// custom cloack                                
#define pDrawViewPort				            ((int(__cdecl*)(DWORD ObjectPointer, DWORD ModelPointer, int a3)) 0x56F210)
#define pRefreshViewport			            ((void(__cdecl*)(DWORD a1, DWORD a2, int a3)) 0x558630)
#define pRefreshCape1				            ((void(__thiscall*)(ObjectItem * lpItem)) 0x8363D0)
#define pRefreshCape2				            ((void(__thiscall*)(ObjectItem * lpItem)) 0x835E40)
#define pObjOnViewport				            ((int(__cdecl*)(int Object))0x5F61C0)
// custom efectos                               
#define CreateEffect2				            ((int(__cdecl*)(int a4, vec3_t Bone1, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x6D9070)
#define BeginRender					            ((void(__thiscall*)(float a2)) 0x546860)
#define EndRender					            ((void(__cdecl*)()) 0x546880)
#define Joint(x)					            ((0x30 * x) + 0x7BC08A0)
#define BoneTransform				            *(int*)0x7BC09C0
#define RenderInfomationR			            ((int(*)()) 0x4D5EC0)
//--                                            
#define pGLSupremo					            ((void(__cdecl*)())0x637A30)
// MOVE_ITEM                                    
#define pChaosBoxState				            *(BYTE*)(*(DWORD*)(0x98670C4) + 0xC8)
//-> Thêm Mới Fix Dupe                          
#define pHelperMouseClick			            ((char(__thiscall*)(int a1)) 0x7D2920)
//--                                            
#define pCheckEffectPlayer			            ((bool(__thiscall*)(void * This,char a2)) 0x4C8640)
#define GetBoneTransform			            ((int(__thiscall*)(int This, signed int a2)) 0x4CD7F0)
#define pCheckMouseOver				            ((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x790B10)
//-- Recovery Info User                         
#define pGetUserCoorX				            *(DWORD *)(*(DWORD *)oUserPreviewStruct + 0xAC)
#define pGetUserCoorY				            *(DWORD *)(*(DWORD *)oUserPreviewStruct + 0xB0)
#define pGetUserName				            (const char *)(*(DWORD *)oUserPreviewStruct + 56)
#define pGetStrutParty( x )			            (*(PartyList*)(pPartyListStruct + 32 * x))
#define pGetLifeMemberParty( x )	            ((unsigned __int8)((BYTE*) 0x81CB500)[32 * x])

#define pRecoveryPotionOn			            *(BYTE*)(*(DWORD*)(pMUHelperClass) + 176)
#define pRecoveryPotionPercent		            *(BYTE*)(*(DWORD*)(pMUHelperClass) + 177)
#define pRecoveryHealOn				            *(BYTE*)(*(DWORD*)(pMUHelperClass) + 178)
#define pRecoveryHealPercent		            *(BYTE*)(*(DWORD*)(pMUHelperClass) + 179)
#define pGetItemList( x )			            ((const char*) (*(DWORD*)(pMUHelperClass)+ 304 + ( 28 * x )))

//-- Sombra en pet                              
#define sub_4DB250					            ((int(__cdecl*)()) 0x4DB250)
#define sub_4E44A0					            ((bool(__thiscall*)(int This)) 0x4E44A0)
#define ShadowMaster				            ((void(__thiscall*)(int JCModel, int a2, int JCLayer, int JCLayerMin, int JCLayerMax)) 0x54A270)
#define pCheckMap					            ((bool(__cdecl*)(signed int a1))0x4DB1C0)
#define sub_6D8980					            ((char(__cdecl*)(int a1, int a2, int a3))0x6D8980)
#define sub_4C8AB0					            ((int(__thiscall*)(int This, char a2))0x4C8AB0)
#define pRenderRand					            ((int(*)()) 0x9CFB8D)
#define SetBoundInputField			            ((int(__thiscall*)(int a1, int a2, int a3)) 0x417EC0)

//--
//Auto Move
#define PathFinding2                            ((char(__cdecl*)(int a1, int a2, int a3, int a4, int a5, float a6, int a7))0x542D20)
#define SendMove                                ((char(__cdecl*)(int a1, int a2))0x5A3C70)
#define SendAction                              ((char(__cdecl*)(int a1, int a2))0x5A13C0)

signed int sub_9CEBF0(double a1);

#define RenderBitMapColored                     ((void(__cdecl*)(int a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, int a13))0x790DF0)
