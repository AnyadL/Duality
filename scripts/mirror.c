/* FILE: mirror.c
 * AUTHOR: Alexander Cheung
 *
 * This script defines the behavior of interacting with a mirror.
 */

#include "area_lighting"

float TIME_SEPARATION = 0.5;
string DESTINATION_TAG = ""; // THIS MUST BE DEFINED

void main()
{
    object oUsingObject = GetLastUsedBy();
    object oPlayer = GetFirstPC();

    /* If the using object is the player, change the lighting */
    if(oUsingObject == oPlayer)
    {
        /* Fade to black, darken the lighting */
        FadeToBlack(oPlayer, FADE_SPEED_FAST);
        DelayCommand(TIME_SEPARATION * 1, DarkenArea());

        /* Teleport the using object to the destination */
        DelayCommand(TIME_SEPARATION * 2, AssignCommand(oUsingObject, ActionJumpToObject(GetObjectByTag(DESTINATION_TAG))));

        /* Fade from black */
        DelayCommand(TIME_SEPARATION * 3, FadeFromBlack(oPlayer, FADE_SPEED_FASTEST));
    }
    else
    {
        /* Teleport the using object to the corresponding mirror */
        AssignCommand(oUsingObject, ActionJumpToObject(GetObjectByTag(DESTINATION_TAG)));
    }
}