/* Filename: shadow_consume.c
 * Author: Alexander Cheung
 *
 * This file contains heartbeat behaviour for the "decoy" shadows.
 */
#include "global"

void consume();

object target;
float delay = 1.0;

void main()
{
    int i;
    i = 0;

    for (; i < SECS_PER_HB; i++)
    {
        DelayCommand(i * delay, consume());
    }
}

void consume()
{
    ClearAllActions();
    target = GetNearestObjectByTag(PIXEL_TAG);
    if (target == OBJECT_INVALID)
        DestroyObject(OBJECT_SELF);
    ActionInteractObject(target);
}