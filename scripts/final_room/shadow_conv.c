/* Filename: shadow_conv.c
 * Author: Alexander Cheung
 *
 * This file contains behaviour for "decoy" shadows when initiating conversation
 * by the player.
 */

#include "global"
#include "dialogue"

const int DAMAGE = 1;
effect death_visual = EffectVisualEffect(VFX_IMP_DEATH_WARD);
float delay = 1.00;
float STUN_DURATION = 1.5;

void StopShadow();
void DestroyShadow();
void AttackMia();
void FaceMia();
void TauntMia();
void MiaWrong();
string GetAttack(int n);
string GetWrong(int n);

void main()
{
    StopShadow();
    FaceMia();
    AttackMia();
    DelayCommand(1 * delay, TauntMia());
    DelayCommand(4 * delay, DestroyShadow());
    DelayCommand(6 * delay, MiaWrong());
}

void StopShadow()
{
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectCutsceneImmobilize(),
        OBJECT_SELF);
}

void AttackMia()
{
    effect damage;
    effect damage_visual;

    damage_visual = EffectVisualEffect(VFX_IMP_DOMINATE_S);
    damage = EffectDamage(DAMAGE);
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectCutsceneImmobilize(), pc, STUN_DURATION);
    AssignCommand(pc, PlayAnimation(ANIMATION_LOOPING_SPASM, 1.0, STUN_DURATION));
    ApplyEffectToObject(DURATION_TYPE_INSTANT, damage_visual, pc);
    ApplyEffectToObject(DURATION_TYPE_INSTANT, damage, pc);
}

void DestroyShadow()
{
    ApplyEffectToObject(DURATION_TYPE_INSTANT, death_visual, OBJECT_SELF);
    DelayCommand(delay * 2, DestroyObject(OBJECT_SELF));
}

void FaceMia()
{
    vector pcpos = GetPositionFromLocation(GetLocation(pc));
    SetFacingPoint(pcpos);
}

void TauntMia()
{
    int n;
    string taunt;
    string text;

    n = Random(NUM_ATTACKS) + 1;
    taunt = SHADOW_ATTACK_TAG + IntToString(n);
    text = GetAttack(n);

    SoundObjectPlay(GetObjectByTag(taunt));
    SpeakString(text, TALKVOLUME_SHOUT);
    AssignCommand(OBJECT_SELF, PlayAnimation(ANIMATION_FIREFORGET_TAUNT));
}

void MiaWrong()
{
    int n;
    string wrong;
    string text;

    n = Random(NUM_WRONGS) + 1;
    wrong = MIA_WRONG_TAG + IntToString(n);
    text = GetWrong(n);

    SoundObjectPlay(GetObjectByTag(wrong));
    AssignCommand(pc, SpeakString(text, TALKVOLUME_TALK));
}

string GetAttack(int n)
{
    switch(n)
    {
        case 1:
            return SHADOW_ATTACK_1;
        case 2:
            return SHADOW_ATTACK_2;
        case 3:
            return SHADOW_ATTACK_3;
        case 4:
            return SHADOW_ATTACK_4;
        case 5:
            return SHADOW_ATTACK_5;
        case 6:
            return SHADOW_ATTACK_6;
        case 7:
            return SHADOW_ATTACK_7;
    }
    return "";
}

string GetWrong(int n)
{
    switch(n)
    {
        case 1:
            return MIA_WRONG_1;
        case 2:
            return MIA_WRONG_2;
        case 3:
            return MIA_WRONG_3;
        case 4:
            return MIA_WRONG_4;
        case 5:
            return MIA_WRONG_5;
    }
    return "";
}