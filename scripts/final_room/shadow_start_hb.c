/* Filename: shadow_start_hb.c
 * Author: Alexander Cheung
 *
 * This file contains the heartbeat behaviour of the shadow standing by the
 * easel before starting the final encounter.
 */

void main()
{
    effect glow = EffectVisualEffect(VFX_DUR_AURA_PULSE_PURPLE_BLACK);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, glow, OBJECT_SELF);
    SetFacing(270.0);
    ActionPlayAnimation(ANIMATION_LOOPING_CONJURE1, 1.0, 5.0);
}