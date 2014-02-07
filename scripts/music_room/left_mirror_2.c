#include "area_lighting"

void main()
{
    object oUsingObject = GetLastUsedBy();
    object oPlayer = GetFirstPC();

    /* If the using object is the player, change the lighting */
    if(oUsingObject == oPlayer) DarkenArea();

    /* Teleport the using object to the corresponding mirror */
    AssignCommand(oUsingObject, ActionJumpToObject(GetObjectByTag("right_music_mirror_2")));
}