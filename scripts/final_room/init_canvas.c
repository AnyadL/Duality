/* Filename: init_canvas.c
 * Author: Alexander Cheung
 *
 * This file contains functions for initializing the center area of the final
 * room at the start of the shadow encounter.
 */

#include "structs"
#include "global"

const float delay = 0.02;

void init();
void create_pixel(location l, string tag, int index);
void create_canvas(location l, string tag, int index);

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
    float z_pixel;
    float z_canvas;
    vector v_canvas;
    vector v_pixel;
    location spawn_point_canvas;
    location spawn_point_pixel;

    array_create(pc, PIXELS);
    SetLocalInt(pc, ROUNDS_PASSED, 0);

    x = START_X;
    y = START_Y;
    z_canvas = -0.9;
    z_pixel = 0.1;

    for (; i < NUM_PIXELS; i++)
    {
        v_canvas = Vector(x, y, z_canvas);
        v_pixel = Vector(x, y, z_pixel);
        spawn_point_canvas = Location(GetArea(pc), v_canvas, 0.0);
        spawn_point_pixel = Location(GetArea(pc), v_pixel, 0.0);

        DelayCommand(i*delay, create_pixel(spawn_point_pixel, PIXEL_TAG, i));

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

void create_pixel(location l, string tag, int index)
{
    object pixel;
    effect appear;

    appear = EffectVisualEffect(VFX_IMP_HOLY_AID);
    ApplyEffectAtLocation(DURATION_TYPE_INSTANT, appear, l);
    CreateObject(OBJECT_TYPE_PLACEABLE, PIXEL_BLUEPRINT, l, TRUE, tag);
    pixel = GetObjectByTag(tag);
    array_set_object(pc, PIXELS, index, pixel);
}

void create_canvas(location l, string tag, int index)
{
    object canvas;
    CreateObject(OBJECT_TYPE_PLACEABLE, CANVAS_BLUEPRINT, l, TRUE, tag);
}