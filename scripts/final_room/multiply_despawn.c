/* Filename: multiply_despawn
 * Author: Alexander Cheung
 */
#include "global"

float delay = 0.25;
float delay2 = 0.10;
float anim_speed = 1.0;
float anim_duration = 2.0;

void DestroyShadow();

void main()
{
    int i;
    for (; i <= NUM_MIRRORS; i++)
    {
        DelayCommand(i * delay, DestroyShadow());
    }
}

void DestroyShadow()
{
    object shadow = GetObjectByTag(SHADOW_CUTSCENE_TAG);
    location l = GetLocation(shadow);
    effect death_effect = EffectVisualEffect(VFX_IMP_DEATH_WARD);

    AssignCommand(shadow, PlayAnimation(ANIMATION_LOOPING_MEDITATE, anim_speed, anim_duration));
    ApplyEffectAtLocation(DURATION_TYPE_INSTANT, death_effect, l);
    DelayCommand(delay2, DestroyObject(shadow));
}