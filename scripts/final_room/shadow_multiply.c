/* Filename: shadow_multiply
 * Author: Alexander Cheung
 *
 * This file contains scripted behaviour for the multiply effect used by the
 * shadow at the start of the final encounter.
 */
#include "global"

float delay = 0.5;

void SpawnShadow(int n);

void main()
{
    DestroyObject(GetObjectByTag(SHADOW_TAG));
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
    location l = GetLocation(spawn_waypoint);
    effect spawn_effect = EffectVisualEffect(VFX_FNF_SUMMON_EPIC_UNDEAD);

    ApplyEffectAtLocation(DURATION_TYPE_TEMPORARY, spawn_effect, l, 2.0);
    CreateObject(OBJECT_TYPE_CREATURE, SHADOW_CUTSCENE_BLUEPRINT, l, FALSE, "shadow_kara_cutscene");
}