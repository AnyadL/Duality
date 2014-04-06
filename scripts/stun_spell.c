void main()
{
	//Goes in OnItemActivate in module properties
    object oUsed = GetItemActivated();

    if(GetTag(oUsed)=="Intontimento")
    {
        object oPC = GetItemActivator();
        object oShadow = GetObjectByTag("Shadow");
        effect eParalyze = EffectCutsceneImmobilize();
        effect eVisualParalyze = EffectVisualEffect(VFX_FNF_SOUND_BURST_SILENT);

        ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eParalyze, oShadow, 10.0f);
        ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eVisualParalyze, oShadow, 5.0f);



    }
}