#include "global"

effect eParalyze = EffectCutsceneImmobilize();
effect eVisualParalyze = EffectVisualEffect(VFX_FNF_SOUND_BURST_SILENT);
//effect eVisualParalyze = EffectVisualEffect(VFX_FNF_TIME_STOP);

void stun(object victim);

void main()
{
    //Goes in OnItemActivate in module properties
    object oUsed = GetItemActivated();

    if(GetTag(oUsed)=="Intontimento")
    {
        int i = 0;
        object oPC = GetItemActivator();
        object oShadow = GetObjectByTag("shadow");
        stun(oShadow);
        for (; i < NUM_MIRRORS; i++)
        {
            oShadow = GetObjectByTag(SHADOW_TAG, i);
            stun(oShadow);
        }
    }
}

void stun(object victim)
{
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eParalyze, victim, 10.0f);
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eVisualParalyze, victim, 5.0f);
}