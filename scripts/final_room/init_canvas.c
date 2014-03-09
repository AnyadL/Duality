#include "structs"
#include "global"

const float delay = 0.05;

void init();
void create(location l, string tag, int index);

void main()
{
    init();
}

void init()
{
    int i = 0;
    int row = 0;
    int column = 0;
    float x;
    float y;
    vector v;
    location spawn_point;
    string tag;

    array_create(pc, PIXELS);

    x = START_X;
    y = START_Y;

    for (; i < NUM_PIXELS; i++)
    {
        v = Vector(x, y, 0.0);
        spawn_point = Location(GetArea(pc), v, 0.0);

        tag = PIXEL_TAG + IntToString(i);

        /* Create the pixel */
        DelayCommand(i*delay, create(spawn_point, tag, i));

        column++;
        x += SPACING;

        if (column == DIM)
        {
            row++;
            column = 0;
            y += SPACING;
            x = START_X;
        }
    }
}

void create(location l, string tag, int index)
{
    object pixel;
    effect appear;

    appear = EffectVisualEffect(VFX_IMP_HOLY_AID);
    ApplyEffectAtLocation(DURATION_TYPE_INSTANT, appear, l);
    //CreateObject(OBJECT_TYPE_PLACEABLE, PIXEL_BLUEPRINT, l, TRUE, tag);
    CreateObject(OBJECT_TYPE_PLACEABLE, PIXEL_BLUEPRINT, l, TRUE, PIXEL_TAG);
    pixel = GetObjectByTag(tag);
    array_set_object(pc, PIXELS, index, pixel);
}