/* Filename: shadow_start_hb.c
 * Author: Alexander Cheung
 *
 * This file contains the heartbeat behaviour of the shadow standing by the
 * easel before starting the final encounter.
 */

void main()
{
    SetFacing(270.0);
    ActionPlayAnimation(ANIMATION_LOOPING_CONJURE1, 1.0, 5.0);
}