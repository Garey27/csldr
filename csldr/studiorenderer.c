#include "pch.h"

#if defined(_WIN32)
#include <windows.h>
#include <wingdi.h>
#endif

engine_studio_api_t IEngineStudio;
r_studio_interface_t studio;

extern cvar_t *viewmodel_fov;

extern cvar_t *viewmodel_offset_x;
extern cvar_t *viewmodel_offset_y;
extern cvar_t *viewmodel_offset_z;
extern cvar_t *viewmodel_hands;

extern cvar_t *cl_mirror_knife;

#define Z_NEAR 1.0 /* was 4 but that's too far for viewmodels */
#define Z_FAR 4096.0

static int Hk_StudioDrawModel(int flags)
{
	studio_drawcount++;
	return studio.StudioDrawModel(flags);
}

static int Hk_StudioDrawPlayer(int flags, entity_state_t *player)
{
	studio_drawcount++;
	return studio.StudioDrawPlayer(flags, player);
}

static float CalcVerticalFov(float fov)
{
	/* hardcoded 4:3 aspect ratio so i don't need to do hor+ on vm fov */
	float x;

	x = 4.0f / tanf(Radians(fov) / 2);
	return Degrees(atanf(3.0f / x)) * 2;
}

static void UnflipKnife(float *value)
{
	if (currentWeaponId != WEAPON_KNIFE || cl_mirror_knife->value)
		return;

	*value = cl_righthand->value;
	cl_righthand->value = (float)!cl_righthand->value;
}

static void ReflipKnife(float value)
{
	if (currentWeaponId != WEAPON_KNIFE || cl_mirror_knife->value)
		return;

	cl_righthand->value = value;
}

static void DrawHands(cl_entity_t *weapon, int flags)
{
	bool changed;
	model_t *model;
	cl_entity_t backup;
	static char hands_path[256] = "";
	static bool hands_valid = false;

	if (!*viewmodel_hands->string)
		return;

	/* skip "models/" for comparison */
	changed = strncmp(hands_path + 7, viewmodel_hands->string, sizeof(hands_path) - 7) != 0;
	if (changed)
	{
		/* update path */
		sprintf(hands_path, "models/%s", viewmodel_hands->string);
	}
	else if (!hands_valid)
	{
		/* no change and the last hands were invalid, don't even try */
		return;
	}

	/* mikkotodo: even though Mod_ForName returns null, it doesn't actually
	free the model so we'd need to do that manually... */
	model = IEngineStudio.Mod_ForName(hands_path, false);
	hands_valid = model != NULL;
	if (!hands_valid)	
		return;

	/* should probably see what changes and only backup the necessary */
	backup = *weapon;

	/* abuse existing bonemerge functionality */
	weapon->model = model;
	weapon->curstate.movetype = 12; /* MOVETYPE_FOLLOW */

	Hk_StudioDrawModel(flags);

	*weapon = backup;
}

static int My_StudioDrawModel(int flags)
{
	int result;
	SCREENINFO scr;
	double top, aspect;
	float fov, fov1, fov2;
	float old_righthand = 0; /* shut the fuck up */

	cl_entity_t *entity = IEngineStudio.GetCurrentEntity();

	if (entity != IEngineStudio.GetViewEntity())
		return Hk_StudioDrawModel(flags);

	scr.iSize = sizeof(SCREENINFO);
	gEngfuncs.pfnGetScreenInfo(&scr);
	aspect = (double)scr.iWidth / (double)scr.iHeight;

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	
	fov1 = viewmodel_fov->value * fovDifference;
	fov2 = CLAMP(fov1, 1, 170);
	fov = CalcVerticalFov(fov2);
	
	top = tan(Radians(fov) / 2) * Z_NEAR;
	
	glFrustum(-top * aspect, top * aspect, -top, top, Z_NEAR, Z_FAR);
	
	glMatrixMode(GL_MODELVIEW);

	/* think about inspecting now since we're about to draw the vm */
	InspectThink();

	UnflipKnife(&old_righthand);

	result = Hk_StudioDrawModel(flags);

	/* draw hands now that the scene is properly set up */
	DrawHands(entity, flags);

	ReflipKnife(old_righthand);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	return result;
}

void My_StudioSetupModel(int bodypart, void **ppbodypart, void **ppsubmodel)
{
	cl_entity_t *entity;
	bool viewModel;
	studiohdr_t *studiohdr;
	mstudiobodyparts_t *body;
	int oldbody;
	int current;
	int newbody;

	entity = IEngineStudio.GetCurrentEntity();
	viewModel = (entity == IEngineStudio.GetViewEntity());
	if (!viewModel) /* we don't want to do anything */
	{
		Hk_StudioSetupModel(bodypart, ppbodypart, ppsubmodel);
		return;
	}

	/* check if bodypart is right */
	studiohdr = (studiohdr_t *)entity->model->cache.data;
	if (!studiohdr) /* what the fuck */
	{
		Hk_StudioSetupModel(bodypart, ppbodypart, ppsubmodel);
		return;
	}

	body = (mstudiobodyparts_t *)((byte *)studiohdr + studiohdr->bodypartindex) + bodypart;

	/* check if the names matches and that there's enough submodels */
	if (*(uint32 *)body->name != *(uint32 *)"arms" || body->nummodels < 2)
	{
		Hk_StudioSetupModel(bodypart, ppbodypart, ppsubmodel);
		return;
	}

	/* bodypart is right one, do arm changing stuff */
	oldbody = entity->curstate.body;

	if (user1 == 4)
		newbody = playerInfo[user2].team;
	else
		newbody = localTeam;

	current = (entity->curstate.body / body->base) % body->nummodels;
	entity->curstate.body = (entity->curstate.body - (current * body->base) + (newbody * body->base));

	/* set the arm bodygroup */
	Hk_StudioSetupModel(bodypart, ppbodypart, ppsubmodel);

	/* restore state */
	entity->curstate.body = oldbody;
}

int Hk_GetStudioModelInterface(int version,
		r_studio_interface_t **ppinterface,
		engine_studio_api_t *pstudio)
{
	int result;

	/* install hooks for fast path rendering */
	memcpy(&IEngineStudio, pstudio, sizeof(engine_studio_api_t));
	HookEngineStudio(pstudio);

	/* give to client */
	result = cl_funcs.pStudioInterface(version, ppinterface, pstudio);

	/* backup and change client stuff */
	memcpy(&studio, (*ppinterface), sizeof(studio));
	(*ppinterface)->StudioDrawModel = My_StudioDrawModel;
	(*ppinterface)->StudioDrawPlayer = Hk_StudioDrawPlayer;

	/* no one uses software or d3d renderers */
	if (!pstudio->IsHardware())
		Plat_Error("Software mode is not supported\n");

#if defined(_WIN32)
	if (!wglGetCurrentContext())
		Plat_Error("D3D mode is not supported\n");
#endif

	return result;
}
