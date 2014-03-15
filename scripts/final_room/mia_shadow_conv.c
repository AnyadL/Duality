/* Filename: mia_shadow_conv.c
 * Author: Alexander Cheung
 *
 * This file contains the script to execute when the player interacts with the
 * "real" shadow during the final encounter.
 */

#include "global"
#include "dialogue"
#include "structs"

effect death_visual = EffectVisualEffect(VFX_FNF_STRIKE_HOLY);
float delay = 1.00;
float death_visual_duration = 3.0;

void DestroyAllShadows();
void StopShadow(object shadow);
void ClearCanvas();
void ConvertPixel(object pixel);
void MiaRight();
string GetRight(int n);

void main()
{
    StopShadow(OBJECT_SELF);
    DestroyAllShadows();

    if (GetLocalInt(OBJECT_SELF, DYING) == 0)
    {
        SetLocalInt(OBJECT_SELF, DYING, 1);
        if (GetLocalInt(pc, ROUNDS_PASSED) < 5)
        {
            MusicBattlePlay(GetArea(pc));
            SetLocalInt(pc, ROUNDS_PASSED, GetLocalInt(pc, ROUNDS_PASSED) + 1);
            AssignCommand(pc, DelayCommand(3 * delay, MiaRight()));
            DelayCommand(delay, DestroyObject(OBJECT_SELF));
        }
        else
        {
            SetLocked(GetObjectByTag("decoration"), FALSE);
            DelayCommand(2*delay, ClearCanvas());
            DelayCommand(3*delay, DestroyObject(OBJECT_SELF));
        }
    }
}

void DestroyAllShadows()
{
    object to_destroy;
    location l;

    int i = 0;
    for (; i < NUM_MIRRORS; i++)
    {
        to_destroy = GetObjectByTag(SHADOW_TAG, i);

        if (to_destroy != OBJECT_INVALID)
        {
            StopShadow(to_destroy);
            DelayCommand(delay, DestroyObject(to_destroy));
        }
    }
}

void MiaRight()
{
    int n = Random(2) + 1;
    string tag = MIA_RIGHT_TAG + IntToString(n);
    SoundObjectPlay(GetObjectByTag(tag));
    AssignCommand(pc, SpeakString(GetRight(n)));
}

string GetRight(int n)
{
    switch(n)
    {
        case 1:
            return MIA_FOUND_1;
        case 2:
            return MIA_FOUND_2;
    }
    return "";
}

void StopShadow(object shadow)
{
    location l;
    l = GetLocation(shadow);
    ApplyEffectAtLocation(DURATION_TYPE_TEMPORARY, death_visual, l, death_visual_duration);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectCutsceneImmobilize(),
        shadow);
    if (Random(2) == 0)
        DelayCommand(delay * 0.5, AssignCommand(shadow, PlayAnimation(ANIMATION_LOOPING_DEAD_BACK)));
    else
        DelayCommand(delay * 0.5, AssignCommand(shadow, PlayAnimation(ANIMATION_LOOPING_DEAD_FRONT)));
}

void ClearCanvas()
{
    location l = GetLocation(GetObjectByTag("canvas_center"));
    object pixel;

    int i = 0;
    for (; i < NUM_PIXELS; i++)
    {
        pixel = array_get_object(pc, PIXELS, i);
        ConvertPixel(pixel);
    }
}

void ConvertPixel(object pixel)
{
    location l = GetLocation(pixel);
    CreateObject(OBJECT_TYPE_PLACEABLE, DARK_PIXEL_BLUEPRINT, l);
    DestroyObject(pixel);
}