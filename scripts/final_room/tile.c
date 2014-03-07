#include "structs"
#include "global"

void flipRowCol(int row, int col);
void toggle(object tile);

void main()
{
    int row = GetLocalInt(OBJECT_SELF, ROW);
    int column = GetLocalInt(OBJECT_SELF, COLUMN);

    flipRowCol(row, column);
}

void flipRowCol(int row, int col)
{
    int row_current;
    int column_current;
    object tile;
    location loc;

    int i;
    for (i = 0; i < NUM_TILES; i++)
    {
        debug_print("i = " + IntToString(i));
        tile = array_get_object(pc, TILES, i);
        row_current = GetLocalInt(tile, ROW);
        column_current = GetLocalInt(tile, COLUMN);
        debug_print("Comparing current row " + IntToString(row_current) + " and column " 
			+ IntToString(column_current) + " to R: " + IntToString(row) + " C: " + IntToString(col));
        if (row_current == row || column_current == col)
            toggle(tile);
    }
}

void toggle(object tile)
{
    location loc;
    object light;

    if (GetLocalInt(tile, STATE) == OFF)
    {
        SetLocalInt(tile, STATE, ON);
        loc = GetLocation(tile);
        CreateObject(OBJECT_TYPE_PLACEABLE, LIGHT, loc);
    }
    else
    {
        SetLocalInt(tile, STATE, OFF);
        light = GetNearestObjectByTag(LIGHT_TAG, tile, 1);
        DestroyObject(light);
    }
}