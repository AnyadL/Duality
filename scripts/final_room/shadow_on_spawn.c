/* Filename: shadow_on_spawn.c
 * Author: Alexander Cheung
 *
 * Thie file contains the animation effects which play when shadows are spawned
 * at the dark mirrors during the final encounter.
 */

float anim_speed = 1.0;
float anim_duration = 2.0;

void main()
{
    effect spawn_effect = EffectVisualEffect(VFX_FNF_SUMMON_EPIC_UNDEAD);
    ApplyEffectAtLocation(DURATION_TYPE_TEMPORARY, spawn_effect,
        GetLocation(OBJECT_SELF), anim_duration);
    PlayAnimation(ANIMATION_LOOPING_MEDITATE, anim_speed, anim_duration);
}