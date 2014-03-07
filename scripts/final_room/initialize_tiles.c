#include "structs"
#include "global"

void init();

void main()
{
    init();
}

void init()
{
    int i = 0;
    int row = 0;
    int col = 0;
    string tag;
    object tile;

    array_create(pc, TILES);

    for (; i < NUM_TILES; i++)
    {
        tag = TILE_TAG + IntToString(i);
        tile = GetObjectByTag(tag);

        array_set_object(pc, TILES, i, tile);
        SetLocalInt(tile, ROW, row);
        SetLocalInt(tile, COLUMN, col);
        SetLocalInt(tile, STATE, OFF);
		
		/*
        debug_print("Setting tile " + IntToString(i) + " to R:" + IntToString(row)
			+ " C:" + IntToString(col));
		*/
		
        col++;
        if (col == DIM)
        {
            row++;
            col = 0;
        }
    }
}