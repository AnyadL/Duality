#include "global"
#include "structs"

void ClearCanvas();
void ConvertPixel(object pixel);

void main()
{
    ClearCanvas();
}

void ClearCanvas()
{
    location l = GetLocation(GetObjectByTag("canvas_center"));
    object pixel;

    int i = 0;
    for (; i < NUM_PIXELS; i++)
    {
        pixel = array_get_object(pc, PIXELS, i);
        ConvertPixel(pixel);
    }
}

void ConvertPixel(object pixel)
{
    location l = GetLocation(pixel);
    CreateObject(OBJECT_TYPE_PLACEABLE, DARK_PIXEL_BLUEPRINT, l);
    DestroyObject(pixel);
}