/* Filename: shadow_spawn.c
 * Author: Alexander Cheung
 *
 * This file contains the heartbeat script for an in-game controller to spawn
 * shadows during the final encounter.
 */

#include "global"
#include "dialogue"

float delay = 0.015;

void spawn(int i, int mia_spawn);
void spawn_mia_shadow(location spawn_point);
void spawn_shadow(location spawn_point);

void main()
{
    int mia_spawn;
    int i;

    if (GetObjectByTag(PIXEL_TAG) != OBJECT_INVALID &&
        GetObjectByTag(MIA_SHADOW_TAG) == OBJECT_INVALID &&
        GetObjectByTag(SHADOW_TAG) == OBJECT_INVALID)
    {
        mia_spawn = Random(NUM_MIRRORS);
        for (; i < NUM_MIRRORS; i++)
            DelayCommand(i * delay, spawn(i, mia_spawn));
    }
    else if (GetObjectByTag(PIXEL_TAG) == OBJECT_INVALID)
    {
        SetLocked(GetObjectByTag("game_over_plate"), FALSE);
        ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectCutsceneImmobilize(),
            pc, 6.0);
    }
}

void spawn(int i, int mia_spawn)
{
    location spawn_point = GetLocation(GetObjectByTag(MIRROR_TAG + IntToString(i)));

    if (i == mia_spawn)
        spawn_mia_shadow(spawn_point);
    else
        spawn_shadow(spawn_point);
}

void spawn_shadow(location spawn_point)
{
    CreateObject(OBJECT_TYPE_CREATURE, SHADOW_BLUEPRINT, spawn_point, FALSE,
        SHADOW_TAG);
}

void spawn_mia_shadow(location spawn_point)
{
    CreateObject(OBJECT_TYPE_CREATURE, MIA_SHADOW_BLUEPRINT, spawn_point,
        FALSE, MIA_SHADOW_TAG);
}