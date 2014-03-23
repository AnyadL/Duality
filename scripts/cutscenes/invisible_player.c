void main()
{
    object oPC = GetFirstPC();
    location lPlayer = GetLocation(oPC);
    object oSun = GetObjectByTag("Sun"); //"Sun" is a waypoint tag
    location lSun = GetLocation(oSun);
	
	
    effect eInvisible = EffectVisualEffect(VFX_DUR_CUTSCENE_INVISIBILITY); /*There's an effect
	called VFX_DUR_INVISIBILITY. That effect only makes the player transparent. This one is 
	full invisibility*/
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eInvisible, oPC, 3.0f); /*The 3.0f is the 
	number of seconds you want the player to be invisible for*/
	
    AssignCommand(oPC, ActionJumpToLocation(lSun));
    AssignCommand(oPC, ActionWait(2.0));
    AssignCommand(oPC, ActionJumpToLocation(lPlayer));
}