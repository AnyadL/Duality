/* Filename: shadow_spawn.c
 * Author: Alexander Cheung
 *
 * This file contains the heartbeat script for an in-game controller to spawn
 * shadows during the final encounter.
 */

#include "global"
#include "dialogue"

void spawn_mia_shadow(location spawn_point);
void spawn_shadow(location spawn_point);

void main()
{
    location spawn_point;
    int i;
    int mia_spawn = Random(NUM_MIRRORS);

    if (GetObjectByTag(PIXEL_TAG) != OBJECT_INVALID &&
        GetObjectByTag(MIA_SHADOW_TAG) == OBJECT_INVALID &&
        GetObjectByTag(SHADOW_TAG) == OBJECT_INVALID)
    {
        for (; i < NUM_MIRRORS; i++)
        {
            spawn_point = GetLocation(GetObjectByTag(MIRROR_TAG
                + IntToString(i)));

            if (i == mia_spawn)
            {
                spawn_mia_shadow(spawn_point);
            }
            else
            {
                spawn_shadow(spawn_point);
            }
        }
    }
    else if (GetObjectByTag(PIXEL_TAG) == OBJECT_INVALID)
    {
        SetLocked(GetObjectByTag("game_over_plate"), FALSE);
        ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectCutsceneImmobilize(),
            pc, 6.0);
    }
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