#include "structs"
#include "global"

void destroy();

void main()
{
    destroy();
}

void destroy()
{
    object user;

    user = GetLastUsedBy();

    //if (user != pc)
    if (user == pc)
    {
        ApplyEffectAtLocation(DURATION_TYPE_INSTANT,
            EffectVisualEffect(VFX_IMP_DEATH_WARD), GetLocation(OBJECT_SELF));
        DestroyObject(OBJECT_SELF);
    }
}