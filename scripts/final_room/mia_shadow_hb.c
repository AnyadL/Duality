/* Filename: mia_shadow_hb.c
 * Author: Alexander Cheung
 *
 * This file contains the script for the "real" shadow's heartbeat. Includes
 * the same functionality as the decoy shadows' heartbeats in addition to taunts
 * used against the player.
 */
#include "global"
#include "dialogue"

const string FLAG = "flag";
float TALK_DIST = 15.0;

void taunt();
void TauntMia();
string GetTaunt(int n);
void consume();

void main()
{
    int i;

    i = 0;

    if (GetLocalInt(OBJECT_SELF, DYING) == 0)
    {
        for (; i < SECS_PER_HB*2; i++)
        {
            DelayCommand(i * 0.5, taunt());
            DelayCommand(i * 0.5, consume());
        }
    }

}

void taunt()
{
    float d = GetDistanceBetween(OBJECT_SELF, pc);
    int check = GetLocalInt(OBJECT_SELF, FLAG);

    if (d < TALK_DIST)
    {
        ApplyEffectToObject(DURATION_TYPE_INSTANT,
            EffectVisualEffect(VFX_IMP_AURA_NEGATIVE_ENERGY), OBJECT_SELF);
        if (check == 0)
        {
            TauntMia();
            SetLocalInt(OBJECT_SELF, FLAG, 1);
        }
    }
}

void TauntMia()
{
    int n;
    string taunt_tag;
    string text;

    n = Random(NUM_TAUNTS) + 1;
    taunt_tag = SHADOW_TAUNT_TAG + IntToString(n);
    text = GetTaunt(n);

    SoundObjectPlay(GetObjectByTag(taunt_tag));
    SpeakString(text, TALKVOLUME_SHOUT);
}

string GetTaunt(int n)
{
    switch(n)
    {
        case 1:
            return SHADOW_TAUNT_1;
        case 2:
            return SHADOW_TAUNT_2;
        case 3:
            return SHADOW_TAUNT_3;
        case 4:
            return SHADOW_TAUNT_4;
        case 5:
            return SHADOW_TAUNT_5;
        case 6:
            return SHADOW_TAUNT_6;
    }
    return "";
}

void consume()
{
    ClearAllActions();
    object target = GetNearestObjectByTag(PIXEL_TAG);
    if (target == OBJECT_INVALID)
        DestroyObject(OBJECT_SELF);
    ActionInteractObject(target);
}