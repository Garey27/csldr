typedef struct cmdalias_s {
  struct cmdalias_s* next;
  char name[32];
  char* value;
} cmdalias_t;

struct cl_enginefuncs_s; /* no body */

typedef int (*INITIALIZE_FUNC)(struct cl_enginefuncs_s*, int);
typedef void (*HUD_INIT_FUNC)(void);
typedef int (*HUD_VIDINIT_FUNC)(void);
typedef int (*HUD_REDRAW_FUNC)(float, int);
typedef int (*HUD_UPDATECLIENTDATA_FUNC)(client_data_t*, float);
typedef void (*HUD_RESET_FUNC)(void);
typedef void (*HUD_CLIENTMOVE_FUNC)(playermove_t*, qboolean);
typedef void (*HUD_CLIENTMOVEINIT_FUNC)(playermove_t*);
typedef char (*HUD_TEXTURETYPE_FUNC)(char*);
typedef void (*HUD_IN_ACTIVATEMOUSE_FUNC)(void);
typedef void (*HUD_IN_DEACTIVATEMOUSE_FUNC)(void);
typedef void (*HUD_IN_MOUSEEVENT_FUNC)(int);
typedef void (*HUD_IN_CLEARSTATES_FUNC)(void);
typedef void (*HUD_IN_ACCUMULATE_FUNC)(void);
typedef void (*HUD_CL_CREATEMOVE_FUNC)(float, usercmd_t*, int);
typedef int (*HUD_CL_ISTHIRDPERSON_FUNC)(void);
typedef void (*HUD_CL_GETCAMERAOFFSETS_FUNC)(float*);
typedef kbutton_t* (*HUD_KB_FIND_FUNC)(const char*);
typedef void (*HUD_CAMTHINK_FUNC)(void);
typedef void (*HUD_CALCREF_FUNC)(ref_params_t*);
typedef int (*HUD_ADDENTITY_FUNC)(int, cl_entity_t*, const char*);
typedef void (*HUD_CREATEENTITIES_FUNC)(void);
typedef void (*HUD_DRAWNORMALTRIS_FUNC)(void);
typedef void (*HUD_DRAWTRANSTRIS_FUNC)(void);
typedef void (*HUD_STUDIOEVENT_FUNC)(const mstudioevent_t*, const cl_entity_t*);
typedef void (*HUD_POSTRUNCMD_FUNC)(local_state_t*, local_state_t*, usercmd_t*, int, double, unsigned int);
typedef void (*HUD_SHUTDOWN_FUNC)(void);
typedef void (*HUD_TXFERLOCALOVERRIDES_FUNC)(entity_state_t*, const clientdata_t*);
typedef void (*HUD_PROCESSPLAYERSTATE_FUNC)(entity_state_t*, const entity_state_t*);
typedef void (*HUD_TXFERPREDICTIONDATA_FUNC)(entity_state_t*, const entity_state_t*, clientdata_t*, const clientdata_t*, weapon_data_t*, const weapon_data_t*);
typedef void (*HUD_DEMOREAD_FUNC)(int, unsigned char*);
typedef int (*HUD_CONNECTIONLESS_FUNC)(const netadr_t*, const char*, char*, int*);
typedef int (*HUD_GETHULLBOUNDS_FUNC)(int, float*, float*);
typedef void (*HUD_FRAME_FUNC)(double);
typedef int (*HUD_KEY_EVENT_FUNC)(int, int, const char*);
typedef void (*HUD_TEMPENTUPDATE_FUNC)(double, double, double, TEMPENTITY**, TEMPENTITY**, int (*)(cl_entity_t*), void (*)(TEMPENTITY*, float));
typedef cl_entity_t* (*HUD_GETUSERENTITY_FUNC)(int);
typedef void (*HUD_VOICESTATUS_FUNC)(int, qboolean);
typedef void (*HUD_DIRECTORMESSAGE_FUNC)(int, void*);
typedef int (*HUD_STUDIO_INTERFACE_FUNC)(int, r_studio_interface_t**, engine_studio_api_t*);
typedef void (*HUD_CHATINPUTPOSITION_FUNC)(int*, int*);
typedef int (*HUD_GETPLAYERTEAM)(int);
typedef void* (*CLIENTFACTORY)(void);

typedef struct
{
  INITIALIZE_FUNC pInitFunc;
  HUD_INIT_FUNC pHudInitFunc;
  HUD_VIDINIT_FUNC pHudVidInitFunc;
  HUD_REDRAW_FUNC pHudRedrawFunc;
  HUD_UPDATECLIENTDATA_FUNC pHudUpdateClientDataFunc;
  HUD_RESET_FUNC pHudResetFunc;
  HUD_CLIENTMOVE_FUNC pClientMove;
  HUD_CLIENTMOVEINIT_FUNC pClientMoveInit;
  HUD_TEXTURETYPE_FUNC pClientTextureType;
  HUD_IN_ACTIVATEMOUSE_FUNC pIN_ActivateMouse;
  HUD_IN_DEACTIVATEMOUSE_FUNC pIN_DeactivateMouse;
  HUD_IN_MOUSEEVENT_FUNC pIN_MouseEvent;
  HUD_IN_CLEARSTATES_FUNC pIN_ClearStates;
  HUD_IN_ACCUMULATE_FUNC pIN_Accumulate;
  HUD_CL_CREATEMOVE_FUNC pCL_CreateMove;
  HUD_CL_ISTHIRDPERSON_FUNC pCL_IsThirdPerson;
  HUD_CL_GETCAMERAOFFSETS_FUNC pCL_GetCameraOffsets;
  HUD_KB_FIND_FUNC pFindKey;
  HUD_CAMTHINK_FUNC pCamThink;
  HUD_CALCREF_FUNC pCalcRefdef;
  HUD_ADDENTITY_FUNC pAddEntity;
  HUD_CREATEENTITIES_FUNC pCreateEntities;
  HUD_DRAWNORMALTRIS_FUNC pDrawNormalTriangles;
  HUD_DRAWTRANSTRIS_FUNC pDrawTransparentTriangles;
  HUD_STUDIOEVENT_FUNC pStudioEvent;
  HUD_POSTRUNCMD_FUNC pPostRunCmd;
  HUD_SHUTDOWN_FUNC pShutdown;
  HUD_TXFERLOCALOVERRIDES_FUNC pTxferLocalOverrides;
  HUD_PROCESSPLAYERSTATE_FUNC pProcessPlayerState;
  HUD_TXFERPREDICTIONDATA_FUNC pTxferPredictionData;
  HUD_DEMOREAD_FUNC pReadDemoBuffer;
  HUD_CONNECTIONLESS_FUNC pConnectionlessPacket;
  HUD_GETHULLBOUNDS_FUNC pGetHullBounds;
  HUD_FRAME_FUNC pHudFrame;
  HUD_KEY_EVENT_FUNC pKeyEvent;
  HUD_TEMPENTUPDATE_FUNC pTempEntUpdate;
  HUD_GETUSERENTITY_FUNC pGetUserEntity;
  HUD_VOICESTATUS_FUNC pVoiceStatus;
  HUD_DIRECTORMESSAGE_FUNC pDirectorMessage;
  HUD_STUDIO_INTERFACE_FUNC pStudioInterface;
  HUD_CHATINPUTPOSITION_FUNC pChatInputPosition;
  HUD_GETPLAYERTEAM pGetPlayerTeam;
  CLIENTFACTORY pClientFactory;
} cldll_func_t;

struct con_nprint_s; /* no body */
struct tagPOINT;  /* no body */

typedef _HSPRITE (*pfnEngSrc_pfnSPR_Load_t)(const char*);
typedef int (*pfnEngSrc_pfnSPR_Frames_t)(_HSPRITE);
typedef int (*pfnEngSrc_pfnSPR_Height_t)(_HSPRITE, int);
typedef int (*pfnEngSrc_pfnSPR_Width_t)(_HSPRITE, int);
typedef void (*pfnEngSrc_pfnSPR_Set_t)(_HSPRITE, int, int, int);
typedef void (*pfnEngSrc_pfnSPR_Draw_t)(int, int, int, const wrect_t*);
typedef void (*pfnEngSrc_pfnSPR_DrawHoles_t)(int, int, int, const wrect_t*);
typedef void (*pfnEngSrc_pfnSPR_DrawAdditive_t)(int, int, int, const wrect_t*);
typedef void (*pfnEngSrc_pfnSPR_EnableScissor_t)(int, int, int, int);
typedef void (*pfnEngSrc_pfnSPR_DisableScissor_t)(void);
typedef client_sprite_t* (*pfnEngSrc_pfnSPR_GetList_t)(char*, int*);
typedef void (*pfnEngSrc_pfnFillRGBA_t)(int, int, int, int, int, int, int, int);
typedef int (*pfnEngSrc_pfnGetScreenInfo_t)(SCREENINFO*);
typedef void (*pfnEngSrc_pfnSetCrosshair_t)(_HSPRITE, wrect_t, int, int, int);
typedef cvar_t* (*pfnEngSrc_pfnRegisterVariable_t)(char*, char*, int);
typedef float (*pfnEngSrc_pfnGetCvarFloat_t)(char*);
typedef char* (*pfnEngSrc_pfnGetCvarString_t)(char*);
typedef int (*pfnEngSrc_pfnAddCommand_t)(char*, void (*)(void));
typedef int (*pfnUserMsgHook)(const char*, int, void*);
typedef int (*pfnEngSrc_pfnHookUserMsg_t)(char*, pfnUserMsgHook);
typedef int (*pfnEngSrc_pfnServerCmd_t)(char*);
typedef int (*pfnEngSrc_pfnClientCmd_t)(char*);
typedef void (*pfnEngSrc_pfnGetPlayerInfo_t)(int, hud_player_info_s*);
typedef void (*pfnEngSrc_pfnPlaySoundByName_t)(char*, float);
typedef void (*pfnEngSrc_pfnPlaySoundByIndex_t)(int, float);
typedef void (*pfnEngSrc_pfnAngleVectors_t)(const float*, float*, float*, float*);
typedef client_textmessage_t* (*pfnEngSrc_pfnTextMessageGet_t)(const char*);
typedef int (*pfnEngSrc_pfnDrawCharacter_t)(int, int, int, int, int, int);
typedef int (*pfnEngSrc_pfnDrawConsoleString_t)(int, int, char*);
typedef void (*pfnEngSrc_pfnDrawSetTextColor_t)(float, float, float);
typedef void (*pfnEngSrc_pfnDrawConsoleStringLen_t)(const char*, int*, int*);
typedef void (*pfnEngSrc_pfnConsolePrint_t)(const char*);
typedef void (*pfnEngSrc_pfnCenterPrint_t)(const char*);
typedef int (*pfnEngSrc_GetWindowCenterX_t)(void);
typedef int (*pfnEngSrc_GetWindowCenterY_t)(void);
typedef void (*pfnEngSrc_GetViewAngles_t)(float*);
typedef void (*pfnEngSrc_SetViewAngles_t)(float*);
typedef int (*pfnEngSrc_GetMaxClients_t)(void);
typedef void (*pfnEngSrc_Cvar_SetValue_t)(char*, float);
typedef int (*pfnEngSrc_Cmd_Argc_t)(void);
typedef char* (*pfnEngSrc_Cmd_Argv_t)(int);
typedef void (*pfnEngSrc_Con_Printf_t)(char*, ...);
typedef void (*pfnEngSrc_Con_DPrintf_t)(char*, ...);
typedef void (*pfnEngSrc_Con_NPrintf_t)(int, char*, ...);
typedef void (*pfnEngSrc_Con_NXPrintf_t)(struct con_nprint_s*, char*, ...);
typedef const char* (*pfnEngSrc_PhysInfo_ValueForKey_t)(const char*);
typedef const char* (*pfnEngSrc_ServerInfo_ValueForKey_t)(const char*);
typedef float (*pfnEngSrc_GetClientMaxspeed_t)(void);
typedef int (*pfnEngSrc_CheckParm_t)(char*, char**);
typedef void (*pfnEngSrc_Key_Event_t)(int, int);
typedef void (*pfnEngSrc_GetMousePosition_t)(int*, int*);
typedef int (*pfnEngSrc_IsNoClipping_t)(void);
typedef cl_entity_t* (*pfnEngSrc_GetLocalPlayer_t)(void);
typedef cl_entity_t* (*pfnEngSrc_GetViewModel_t)(void);
typedef cl_entity_t* (*pfnEngSrc_GetEntityByIndex_t)(int);
typedef float (*pfnEngSrc_GetClientTime_t)(void);
typedef void (*pfnEngSrc_V_CalcShake_t)(void);
typedef void (*pfnEngSrc_V_ApplyShake_t)(float*, float*, float);
typedef int (*pfnEngSrc_PM_PointContents_t)(float*, int*);
typedef int (*pfnEngSrc_PM_WaterEntity_t)(float*);
typedef pmtrace_t* (*pfnEngSrc_PM_TraceLine_t)(float*, float*, int, int, int);
typedef model_t* (*pfnEngSrc_CL_LoadModel_t)(const char*, int*);
typedef int (*pfnEngSrc_CL_CreateVisibleEntity_t)(int, cl_entity_t*);
typedef const model_t* (*pfnEngSrc_GetSpritePointer_t)(_HSPRITE);
typedef void (*pfnEngSrc_pfnPlaySoundByNameAtLocation_t)(char*, float, float*);
typedef unsigned short (*pfnEngSrc_pfnPrecacheEvent_t)(int, const char*);
typedef void (*pfnEngSrc_pfnPlaybackEvent_t)(int, const edict_t*, unsigned short, float, float*, float*, float, float, int, int, int, int);
typedef void (*pfnEngSrc_pfnWeaponAnim_t)(int, int);
typedef float (*pfnEngSrc_pfnRandomFloat_t)(float, float);
typedef int32 (*pfnEngSrc_pfnRandomLong_t)(int32, int32);
typedef void (*pfnEngSrc_pfnHookEvent_t)(char*, void (*)(event_args_t*));
typedef int (*pfnEngSrc_Con_IsVisible_t)(void);
typedef const char* (*pfnEngSrc_pfnGetGameDirectory_t)(void);
typedef cvar_t* (*pfnEngSrc_pfnGetCvarPointer_t)(const char*);
typedef const char* (*pfnEngSrc_Key_LookupBinding_t)(const char*);
typedef const char* (*pfnEngSrc_pfnGetLevelName_t)(void);
typedef void (*pfnEngSrc_pfnGetScreenFade_t)(screenfade_t*);
typedef void (*pfnEngSrc_pfnSetScreenFade_t)(screenfade_t*);
typedef void* (*pfnEngSrc_VGui_GetPanel_t)(void);
typedef void (*pfnEngSrc_VGui_ViewportPaintBackground_t)(int*);
typedef byte* (*pfnEngSrc_COM_LoadFile_t)(char*, int, int*);
typedef char* (*pfnEngSrc_COM_ParseFile_t)(char*, char*);
typedef void (*pfnEngSrc_COM_FreeFile_t)(void*);
typedef int (*pfnEngSrc_IsSpectateOnly_t)(void);
typedef model_t* (*pfnEngSrc_LoadMapSprite_t)(const char*);
typedef void (*pfnEngSrc_COM_AddAppDirectoryToSearchPath_t)(const char*, const char*);
typedef int (*pfnEngSrc_COM_ExpandFilename_t)(const char*, char*, int);
typedef const char* (*pfnEngSrc_PlayerInfo_ValueForKey_t)(int, const char*);
typedef void (*pfnEngSrc_PlayerInfo_SetValueForKey_t)(const char*, const char*);
typedef qboolean (*pfnEngSrc_GetPlayerUniqueID_t)(int, char*);
typedef int (*pfnEngSrc_GetTrackerIDForPlayer_t)(int);
typedef int (*pfnEngSrc_GetPlayerForTrackerID_t)(int);
typedef int (*pfnEngSrc_pfnServerCmdUnreliable_t)(char*);
typedef void (*pfnEngSrc_GetMousePos_t)(struct tagPOINT*);
typedef void (*pfnEngSrc_SetMousePos_t)(int, int);
typedef void (*pfnEngSrc_SetMouseEnable_t)(qboolean);
typedef cvar_t* (*pfnEngSrc_GetFirstCVarPtr_t)(void);
typedef unsigned int (*pfnEngSrc_GetFirstCmdFunctionHandle_t)(void);
typedef unsigned int (*pfnEngSrc_GetNextCmdFunctionHandle_t)(unsigned int);
typedef const char* (*pfnEngSrc_GetCmdFunctionName_t)(unsigned int);
typedef float (*pfnEngSrc_GetClientOldTime_t)(void);
typedef float (*pfnEngSrc_GetServerGravityValue_t)(void);
typedef model_t* (*pfnEngSrc_GetModelByIndex_t)(int);
typedef void (*pfnEngSrc_pfnSetFilterMode_t)(int);
typedef void (*pfnEngSrc_pfnSetFilterColor_t)(float, float, float);
typedef void (*pfnEngSrc_pfnSetFilterBrightness_t)(float);
typedef sequenceEntry_s* (*pfnEngSrc_pfnSequenceGet_t)(const char*, const char*);
typedef void (*pfnEngSrc_pfnSPR_DrawGeneric_t)(int, int, int, const wrect_t*, int, int, int, int);
typedef sequenceEntry_s* (*pfnEngSrc_pfnSequencePickSentence_t)(const char*, int, int*);
typedef int (*pfnEngSrc_pfnDrawString_t)(int, int, const char*, int, int, int);
typedef int (*pfnEngSrc_pfnDrawStringReverse_t)(int, int, const char*, int, int, int);
typedef const char* (*pfnEngSrc_LocalPlayerInfo_ValueForKey_t)(const char*);
typedef int (*pfnEngSrc_pfnVGUI2DrawCharacter_t)(int, int, int, unsigned int);
typedef int (*pfnEngSrc_pfnVGUI2DrawCharacterAdd_t)(int, int, int, int, int, int, unsigned int);
typedef unsigned int (*pfnEngSrc_COM_GetApproxWavePlayLength)(const char*);
typedef void* (*pfnEngSrc_pfnGetCareerUI_t)(void);
typedef void (*pfnEngSrc_Cvar_Set_t)(char*, char*);
typedef int (*pfnEngSrc_pfnIsPlayingCareerMatch_t)(void);
typedef void (*pfnEngSrc_pfnPlaySoundVoiceByName_t)(char*, float, int);
typedef void (*pfnEngSrc_pfnPrimeMusicStream_t)(char*, int);
typedef double (*pfnEngSrc_GetAbsoluteTime_t)(void);
typedef void (*pfnEngSrc_pfnProcessTutorMessageDecayBuffer_t)(int*, int);
typedef void (*pfnEngSrc_pfnConstructTutorMessageDecayBuffer_t)(int*, int);
typedef void (*pfnEngSrc_pfnResetTutorMessageDecayData_t)(void);
typedef void (*pfnEngSrc_pfnPlaySoundByNameAtPitch_t)(char*, float, int);
typedef void (*pfnEngSrc_pfnFillRGBABlend_t)(int, int, int, int, int, int, int, int);
typedef int (*pfnEngSrc_pfnGetAppID_t)(void);
typedef cmdalias_t* (*pfnEngSrc_pfnGetAliases_t)(void);
typedef void (*pfnEngSrc_pfnVguiWrap2_GetMouseDelta_t)(int*, int*);
typedef int (*pfnEngSrc_pfnFilteredClientCmd_t)(char*);

typedef struct cl_enginefuncs_s {
  pfnEngSrc_pfnSPR_Load_t pfnSPR_Load;
  pfnEngSrc_pfnSPR_Frames_t pfnSPR_Frames;
  pfnEngSrc_pfnSPR_Height_t pfnSPR_Height;
  pfnEngSrc_pfnSPR_Width_t pfnSPR_Width;
  pfnEngSrc_pfnSPR_Set_t pfnSPR_Set;
  pfnEngSrc_pfnSPR_Draw_t pfnSPR_Draw;
  pfnEngSrc_pfnSPR_DrawHoles_t pfnSPR_DrawHoles;
  pfnEngSrc_pfnSPR_DrawAdditive_t pfnSPR_DrawAdditive;
  pfnEngSrc_pfnSPR_EnableScissor_t pfnSPR_EnableScissor;
  pfnEngSrc_pfnSPR_DisableScissor_t pfnSPR_DisableScissor;
  pfnEngSrc_pfnSPR_GetList_t pfnSPR_GetList;
  pfnEngSrc_pfnFillRGBA_t pfnFillRGBA;
  pfnEngSrc_pfnGetScreenInfo_t pfnGetScreenInfo;
  pfnEngSrc_pfnSetCrosshair_t pfnSetCrosshair;
  pfnEngSrc_pfnRegisterVariable_t pfnRegisterVariable;
  pfnEngSrc_pfnGetCvarFloat_t pfnGetCvarFloat;
  pfnEngSrc_pfnGetCvarString_t pfnGetCvarString;
  pfnEngSrc_pfnAddCommand_t pfnAddCommand;
  pfnEngSrc_pfnHookUserMsg_t pfnHookUserMsg;
  pfnEngSrc_pfnServerCmd_t pfnServerCmd;
  pfnEngSrc_pfnClientCmd_t pfnClientCmd;
  pfnEngSrc_pfnGetPlayerInfo_t pfnGetPlayerInfo;
  pfnEngSrc_pfnPlaySoundByName_t pfnPlaySoundByName;
  pfnEngSrc_pfnPlaySoundByIndex_t pfnPlaySoundByIndex;
  pfnEngSrc_pfnAngleVectors_t pfnAngleVectors;
  pfnEngSrc_pfnTextMessageGet_t pfnTextMessageGet;
  pfnEngSrc_pfnDrawCharacter_t pfnDrawCharacter;
  pfnEngSrc_pfnDrawConsoleString_t pfnDrawConsoleString;
  pfnEngSrc_pfnDrawSetTextColor_t pfnDrawSetTextColor;
  pfnEngSrc_pfnDrawConsoleStringLen_t pfnDrawConsoleStringLen;
  pfnEngSrc_pfnConsolePrint_t pfnConsolePrint;
  pfnEngSrc_pfnCenterPrint_t pfnCenterPrint;
  pfnEngSrc_GetWindowCenterX_t GetWindowCenterX;
  pfnEngSrc_GetWindowCenterY_t GetWindowCenterY;
  pfnEngSrc_GetViewAngles_t GetViewAngles;
  pfnEngSrc_SetViewAngles_t SetViewAngles;
  pfnEngSrc_GetMaxClients_t GetMaxClients;
  pfnEngSrc_Cvar_SetValue_t Cvar_SetValue;
  pfnEngSrc_Cmd_Argc_t Cmd_Argc;
  pfnEngSrc_Cmd_Argv_t Cmd_Argv;
  pfnEngSrc_Con_Printf_t Con_Printf;
  pfnEngSrc_Con_DPrintf_t Con_DPrintf;
  pfnEngSrc_Con_NPrintf_t Con_NPrintf;
  pfnEngSrc_Con_NXPrintf_t Con_NXPrintf;
  pfnEngSrc_PhysInfo_ValueForKey_t PhysInfo_ValueForKey;
  pfnEngSrc_ServerInfo_ValueForKey_t ServerInfo_ValueForKey;
  pfnEngSrc_GetClientMaxspeed_t GetClientMaxspeed;
  pfnEngSrc_CheckParm_t CheckParm;
  pfnEngSrc_Key_Event_t Key_Event;
  pfnEngSrc_GetMousePosition_t GetMousePosition;
  pfnEngSrc_IsNoClipping_t IsNoClipping;
  pfnEngSrc_GetLocalPlayer_t GetLocalPlayer;
  pfnEngSrc_GetViewModel_t GetViewModel;
  pfnEngSrc_GetEntityByIndex_t GetEntityByIndex;
  pfnEngSrc_GetClientTime_t GetClientTime;
  pfnEngSrc_V_CalcShake_t V_CalcShake;
  pfnEngSrc_V_ApplyShake_t V_ApplyShake;
  pfnEngSrc_PM_PointContents_t PM_PointContents;
  pfnEngSrc_PM_WaterEntity_t PM_WaterEntity;
  pfnEngSrc_PM_TraceLine_t PM_TraceLine;
  pfnEngSrc_CL_LoadModel_t CL_LoadModel;
  pfnEngSrc_CL_CreateVisibleEntity_t CL_CreateVisibleEntity;
  pfnEngSrc_GetSpritePointer_t GetSpritePointer;
  pfnEngSrc_pfnPlaySoundByNameAtLocation_t pfnPlaySoundByNameAtLocation;
  pfnEngSrc_pfnPrecacheEvent_t pfnPrecacheEvent;
  pfnEngSrc_pfnPlaybackEvent_t pfnPlaybackEvent;
  pfnEngSrc_pfnWeaponAnim_t pfnWeaponAnim;
  pfnEngSrc_pfnRandomFloat_t pfnRandomFloat;
  pfnEngSrc_pfnRandomLong_t pfnRandomLong;
  pfnEngSrc_pfnHookEvent_t pfnHookEvent;
  pfnEngSrc_Con_IsVisible_t Con_IsVisible;
  pfnEngSrc_pfnGetGameDirectory_t pfnGetGameDirectory;
  pfnEngSrc_pfnGetCvarPointer_t pfnGetCvarPointer;
  pfnEngSrc_Key_LookupBinding_t Key_LookupBinding;
  pfnEngSrc_pfnGetLevelName_t pfnGetLevelName;
  pfnEngSrc_pfnGetScreenFade_t pfnGetScreenFade;
  pfnEngSrc_pfnSetScreenFade_t pfnSetScreenFade;
  pfnEngSrc_VGui_GetPanel_t VGui_GetPanel;
  pfnEngSrc_VGui_ViewportPaintBackground_t VGui_ViewportPaintBackground;
  pfnEngSrc_COM_LoadFile_t COM_LoadFile;
  pfnEngSrc_COM_ParseFile_t COM_ParseFile;
  pfnEngSrc_COM_FreeFile_t COM_FreeFile;
  triangleapi_t* pTriAPI;
  efx_api_t* pEfxAPI;
  event_api_t* pEventAPI;
  demo_api_t* pDemoAPI;
  net_api_t* pNetAPI;
  struct IVoiceTweak_s* pVoiceTweak;
  pfnEngSrc_IsSpectateOnly_t IsSpectateOnly;
  pfnEngSrc_LoadMapSprite_t LoadMapSprite;
  pfnEngSrc_COM_AddAppDirectoryToSearchPath_t COM_AddAppDirectoryToSearchPath;
  pfnEngSrc_COM_ExpandFilename_t COM_ExpandFilename;
  pfnEngSrc_PlayerInfo_ValueForKey_t PlayerInfo_ValueForKey;
  pfnEngSrc_PlayerInfo_SetValueForKey_t PlayerInfo_SetValueForKey;
  pfnEngSrc_GetPlayerUniqueID_t GetPlayerUniqueID;
  pfnEngSrc_GetTrackerIDForPlayer_t GetTrackerIDForPlayer;
  pfnEngSrc_GetPlayerForTrackerID_t GetPlayerForTrackerID;
  pfnEngSrc_pfnServerCmdUnreliable_t pfnServerCmdUnreliable;
  pfnEngSrc_GetMousePos_t pfnGetMousePos;
  pfnEngSrc_SetMousePos_t pfnSetMousePos;
  pfnEngSrc_SetMouseEnable_t pfnSetMouseEnable;
  pfnEngSrc_GetFirstCVarPtr_t GetFirstCvarPtr;
  pfnEngSrc_GetFirstCmdFunctionHandle_t GetFirstCmdFunctionHandle;
  pfnEngSrc_GetNextCmdFunctionHandle_t GetNextCmdFunctionHandle;
  pfnEngSrc_GetCmdFunctionName_t GetCmdFunctionName;
  pfnEngSrc_GetClientOldTime_t hudGetClientOldTime;
  pfnEngSrc_GetServerGravityValue_t hudGetServerGravityValue;
  pfnEngSrc_GetModelByIndex_t hudGetModelByIndex;
  pfnEngSrc_pfnSetFilterMode_t pfnSetFilterMode;
  pfnEngSrc_pfnSetFilterColor_t pfnSetFilterColor;
  pfnEngSrc_pfnSetFilterBrightness_t pfnSetFilterBrightness;
  pfnEngSrc_pfnSequenceGet_t pfnSequenceGet;
  pfnEngSrc_pfnSPR_DrawGeneric_t pfnSPR_DrawGeneric;
  pfnEngSrc_pfnSequencePickSentence_t pfnSequencePickSentence;
  pfnEngSrc_pfnDrawString_t pfnDrawString;
  pfnEngSrc_pfnDrawStringReverse_t pfnDrawStringReverse;
  pfnEngSrc_LocalPlayerInfo_ValueForKey_t LocalPlayerInfo_ValueForKey;
  pfnEngSrc_pfnVGUI2DrawCharacter_t pfnVGUI2DrawCharacter;
  pfnEngSrc_pfnVGUI2DrawCharacterAdd_t pfnVGUI2DrawCharacterAdd;
  pfnEngSrc_COM_GetApproxWavePlayLength COM_GetApproxWavePlayLength;
  pfnEngSrc_pfnGetCareerUI_t pfnGetCareerUI;
  pfnEngSrc_Cvar_Set_t Cvar_Set;
  pfnEngSrc_pfnIsPlayingCareerMatch_t pfnIsCareerMatch;
  pfnEngSrc_pfnPlaySoundVoiceByName_t pfnPlaySoundVoiceByName;
  pfnEngSrc_pfnPrimeMusicStream_t pfnPrimeMusicStream;
  pfnEngSrc_GetAbsoluteTime_t GetAbsoluteTime;
  pfnEngSrc_pfnProcessTutorMessageDecayBuffer_t pfnProcessTutorMessageDecayBuffer;
  pfnEngSrc_pfnConstructTutorMessageDecayBuffer_t pfnConstructTutorMessageDecayBuffer;
  pfnEngSrc_pfnResetTutorMessageDecayData_t pfnResetTutorMessageDecayData;
  pfnEngSrc_pfnPlaySoundByNameAtPitch_t pfnPlaySoundByNameAtPitch;
  pfnEngSrc_pfnFillRGBABlend_t pfnFillRGBABlend;
  pfnEngSrc_pfnGetAppID_t pfnGetAppID;
  pfnEngSrc_pfnGetAliases_t pfnGetAliasList;
  pfnEngSrc_pfnVguiWrap2_GetMouseDelta_t pfnVguiWrap2_GetMouseDelta;
  pfnEngSrc_pfnFilteredClientCmd_t pfnFilteredClientCmd;
} cl_enginefunc_t;
