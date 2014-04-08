/* Filename: shadow_multiply
 * Author: Alexander Cheung
 *
 * This file contains scripted behaviour for the multiply effect used by the
 * shadow at the start of the final encounter.
 */
#include "global"

float delay = 0.5;
float anim_speed = 1.0;
float anim_duration = 2.0;

void SpawnShadow(int n);

void main()
{
    // DestroyObject(GetObjectByTag(SHADOW_TAG));

    effect glow = EffectVisualEffect(VFX_DUR_AURA_PULSE_RED_BLACK);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, glow, GetObjectByTag("shadow_kara_cutscene"));

    int i;
    for (; i < NUM_MIRRORS; i++)
    {
        DelayCommand(i * delay, SpawnShadow(i + 1));
    }
}

void SpawnShadow(int n)
{
    string tag = SHADOW_MULTIPLY_POINT_TAG + IntToString(n);
    object spawn_waypoint = GetObjectByTag(tag);
    object created;
    location l = GetLocation(spawn_waypoint);
    effect spawn_effect = EffectVisualEffect(VFX_FNF_SUMMON_EPIC_UNDEAD);
    // effect glow = EffectVisualEffect(VFX_DUR_AURA_PULSE_RED_BLACK);

    ApplyEffectAtLocation(DURATION_TYPE_TEMPORARY, spawn_effect, l, 2.0);
    created = CreateObject(OBJECT_TYPE_CREATURE, SHADOW_CUTSCENE_BLUEPRINT, l, FALSE, SHADOW_CUTSCENE_TAG);
    AssignCommand(created, PlayAnimation(ANIMATION_LOOPING_MEDITATE, anim_speed, anim_duration));
    // ApplyEffectToObject(DURATION_TYPE_PERMANENT, glow, created);
}