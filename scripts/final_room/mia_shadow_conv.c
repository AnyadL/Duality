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
void RecreateSpawner();
string GetRight(int n);
void createObject(location l);

void main()
{
    ClearAllActions();
    StopShadow(OBJECT_SELF);
    DestroyAllShadows();

    if (GetLocalInt(OBJECT_SELF, DYING) == 0)
    {
        SetLocalInt(OBJECT_SELF, DYING, 1);
        if (GetLocalInt(pc, ROUNDS_PASSED) < (NUM_ROUNDS - 1))
        {
            if (GetLocalInt(pc, ROUNDS_PASSED) == 2)
            {
                SetLocked(GetObjectByTag("journal_hint_trigger_2"), FALSE);
            }
            RecreateSpawner();
            SetLocalInt(pc, ROUNDS_PASSED, GetLocalInt(pc, ROUNDS_PASSED) + 1);
            AssignCommand(pc, DelayCommand(2 * delay, MiaRight()));
            DelayCommand(delay, DestroyAllShadows());
            DelayCommand(delay, DestroyObject(OBJECT_SELF));
        }
        else
        {
            SetLocked(GetObjectByTag("decoration"), FALSE);
            DelayCommand(2*delay, DestroyAllShadows());
            DelayCommand(2*delay, ClearCanvas());
            DelayCommand(3*delay, DestroyObject(OBJECT_SELF));
        }
    }
}

void RecreateSpawner()
{
    object spawner = GetObjectByTag("decoration");
    location l = GetLocation(spawner);
    DestroyObject(spawner);
    CreateObject(OBJECT_TYPE_PLACEABLE, SPAWNER_BLUEPRINT, l);
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
    /*
    int n = Random(2) + 1;
    string tag = MIA_RIGHT_TAG + IntToString(n);
    SoundObjectPlay(GetObjectByTag(tag));
    AssignCommand(pc, SpeakString(GetRight(n)));
    */
    object shadow_right_1 = GetObjectByTag(SHADOW_RIGHT_1_TAG);
    object shadow_right_2 = GetObjectByTag(SHADOW_RIGHT_2_TAG);
    object shadow_right_3 = GetObjectByTag(SHADOW_RIGHT_3_TAG);
    object mia_right_2 = GetObjectByTag(MIA_RIGHT_2_TAG);
    object mia_right_4 = GetObjectByTag(MIA_RIGHT_4_TAG);
    object shadow_speech = GetObjectByTag("shadow_speech");

    int round = GetLocalInt(pc, ROUNDS_PASSED);

    switch(round)
    {
    case 1:
        SoundObjectPlay(shadow_right_1);
        SendMessageToPC(pc, SHADOW_RIGHT_1);
        //AssignCommand(shadow_speech, SpeakString(SHADOW_RIGHT_1));
        break;
    case 2:
        SoundObjectPlay(mia_right_2);
        AssignCommand(pc, SpeakString(MIA_RIGHT_2));
        DelayCommand(2.0, SoundObjectPlay(shadow_right_2));
        //DelayCommand(2.0, AssignCommand(shadow_speech, SpeakString(SHADOW_RIGHT_2)));
        DelayCommand(2.0, SendMessageToPC(pc, SHADOW_RIGHT_2));
        break;
    case 3:
        SoundObjectPlay(shadow_right_3);
        //AssignCommand(shadow_speech, SpeakString(SHADOW_RIGHT_3));
        SendMessageToPC(pc, SHADOW_RIGHT_3);
        break;
    case 4:
        SoundObjectPlay(mia_right_4);
        AssignCommand(pc, SpeakString(MIA_RIGHT_4));
        break;
    }
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