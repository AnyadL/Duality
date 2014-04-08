/* Filename: pixel_use.c
 * Author: Alexander Cheung
 *
 * This file contains scripts fired when a Ray of Light is used. On use, the
 * rays should destroy themselves and be replaced by the lighter rays to
 * signify being consumed by the shadows.
 */

#include "structs"
#include "global"
#include "dialogue"

void destroy();
void ConvertPixel(object pixel);
void ShadowsApproach();

effect despawn = EffectVisualEffect(VFX_IMP_MAGICAL_VISION);

void main()
{
    destroy();
}

void destroy()
{
    object user;
    object to_destroy;
    int i;
    vector v;
    location l;

    SetLocked(GetObjectByTag("journal_hint_trigger"), FALSE);
    user = GetLastUsedBy();

    if (user != pc)
    {
        l = GetLocation(OBJECT_SELF);
        v = GetPositionFromLocation(l);
        v.z = 0.0;
        l = Location(GetArea(OBJECT_SELF), v, 0.0);

        ApplyEffectAtLocation(DURATION_TYPE_INSTANT,
            EffectVisualEffect(VFX_IMP_DEATH_WARD), l);
        ApplyEffectAtLocation(DURATION_TYPE_INSTANT, despawn, GetLocation(user));

        if (user == GetObjectByTag(MIA_SHADOW_TAG))
            ShadowsApproach();

        DestroyObject(user);

        i=0;
        for (; i < SPLASH; i++)
        {
            to_destroy = GetNearestObjectByTag(PIXEL_TAG, OBJECT_SELF, i);
            ConvertPixel(to_destroy);
        }
        ConvertPixel(OBJECT_SELF);
    }
}

void ConvertPixel(object pixel)
{
    location l = GetLocation(pixel);
    CreateObject(OBJECT_TYPE_PLACEABLE, DARK_PIXEL_BLUEPRINT, l);
    DestroyObject(pixel);
}

void ShadowsApproach()
{
    int line;

    line = Random(NUM_APPROACHES) + 1;

    switch(line)
    {
        case 1:
            AssignCommand(pc, SpeakString(SHADOWS_APPROACH_1));
            SoundObjectPlay(GetObjectByTag(SHADOWS_APPROACH_1_TAG));
            break;
        case 2:
            AssignCommand(pc, SpeakString(SHADOWS_APPROACH_2));
            SoundObjectPlay(GetObjectByTag(SHADOWS_APPROACH_2_TAG));
            break;
        case 3:
            AssignCommand(pc, SpeakString(SHADOWS_APPROACH_3));
            SoundObjectPlay(GetObjectByTag(SHADOWS_APPROACH_3_TAG));
            break;
        case 4:
            AssignCommand(pc, SpeakString(SHADOWS_APPROACH_3));
            SoundObjectPlay(GetObjectByTag(SHADOWS_APPROACH_3_TAG));
            break;
    }
}