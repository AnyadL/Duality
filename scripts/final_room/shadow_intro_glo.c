#include "global"

void main()
{
    int i = 0;
    effect glow = EffectVisualEffect(VFX_DUR_AURA_PULSE_RED_BLACK);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, glow, OBJECT_SELF);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, glow, GetObjectByTag(SHADOW_CUTSCENE_TAG, 1));
}