#include "in_g_cutscene"

void main()
{

    object oPC = GetFirstPC();
    object oShadow = GetObjectByTag("Shadow");
    location lPlayer = GetLocation(oPC);
    object oPlayer = CreateObject(OBJECT_TYPE_WAYPOINT, "playerlocation", lPlayer);

    object oBrightMoon = GetObjectByTag("BrightMoonWaypoint");
    object oTheMoon = GetObjectByTag("floating_moon");
    object oShadowDeath = GetObjectByTag("ShadowDeath");
    location lShadowDeath = GetLocation(oShadowDeath);
    object oWatchDeath = GetObjectByTag("PlayerWatchDeath");
    object oMoon = GetObjectByTag("MoonWaypoint");
    vector vDresserLoc = Vector(31.22f, 23.84f);
    object oMirrorRoom = GetArea(oTheMoon);
    location lDresser = Location(oMirrorRoom, vDresserLoc, 75.0f);
    object oDresserPlace = CreateObject(OBJECT_TYPE_WAYPOINT, "playerlocation", lDresser);
    vector vMoonLoc = Vector(27.0f, 25.0f, 0.5f);
    location lMoonPortal = Location(oMirrorRoom, vMoonLoc, 0.0f);
    object oMoonPortalPlace = CreateObject(OBJECT_TYPE_WAYPOINT, "playerlocation", lMoonPortal);
    object oSun = GetObjectByTag("floating_sun");
    object oPoem = GetObjectByTag("poem");

    GestaltStartCutscene(oPC);

    effect eInvisible = EffectVisualEffect(VFX_DUR_CUTSCENE_INVISIBILITY);
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eInvisible, oPC, 14.5f);


    GestaltCameraFacing(0.1f, 80.0f, 5.0f, 1.0f, oPC);
    GestaltJump(0.2f, oPC, oBrightMoon);

    GestaltDestroy(0.2f, oShadow);          //*********
    GestaltCreate(0.5f, oShadowDeath, OBJECT_TYPE_CREATURE, "cutsceneshadow", "CutsceneShadow");   //*******
    object oSecondShadow = GetObjectByTag("CutsceneShadow");    //******

    /*GestaltFace(0.5f, oShadow, 135.0f);
    GestaltJump(0.6f, oShadow, oShadowDeath);
    GestaltClearActions(0.7f, oShadow); */

    effect eBrightLight = EffectVisualEffect(VFX_FNF_STRIKE_HOLY);
    GestaltApplyEffect(1.5f, oTheMoon, eBrightLight, TEMPORARY, 1.0f);
    GestaltCreate(1.5f, oMoonPortalPlace, OBJECT_TYPE_PLACEABLE, "mist", "portal");
    GestaltCreate(1.5f, oMoonPortalPlace, OBJECT_TYPE_PLACEABLE, "mist001", "magic_sparks_yellow");


    DelayCommand(4.0f, SetCameraMode(oPC, CAMERA_MODE_TOP_DOWN));
    GestaltCameraFacing(4.6f, 315.0f, 5.0f, 1.0f, oPC);
    GestaltActionFace(4.7f, oPC,315.0f,2,oSecondShadow);
    GestaltJump(4.5f, oPC, oWatchDeath);

    GestaltCreate(5.0f, oDresserPlace, OBJECT_TYPE_PLACEABLE, "entrancemirro037", "armourdresser");
    GestaltCreate(5.0f, oDresserPlace, OBJECT_TYPE_PLACEABLE, "entrancemirro031", "floor_light");
    object oDresser = GetObjectByTag("armourdresser");


    GestaltSpeak(4.7f, oSecondShadow, "Stop! There's too much light in here!");
    effect eShadowDeath = EffectVisualEffect(VFX_FNF_STRIKE_HOLY);
    GestaltApplyLocationEffect(6.0f, lShadowDeath, eShadowDeath, TEMPORARY, 2.0f);
    //GestaltApplyEffect(6.0f, oShadow, eShadowDeath, TEMPORARY, 2.0f);
    //GestaltDestroy(6.1f, oSecondShadow);


    GestaltJump(8.5f, oPC, oMoon);


    GestaltCameraFace(9.0f,
                      oSun,5.0f,1.0f,
                      oPoem,5.0f,1.0f,
                      6.0f,30.0f,
                      oPC, 1);
    GestaltPlaySound(10.0f, oPC, "BrightMoon");
    GestaltPlaySound(13.0f, oPC, "Whatsthat");


    GestaltJump(14.5f, oPC, oPlayer);

    GestaltStopCutscene(14.7f, oPC);

    DelayCommand(15.0f, SetCameraMode(oPC, CAMERA_MODE_TOP_DOWN));
}