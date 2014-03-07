const int NUM_TILES = 9;
const int DIM = 3;
const int OFF = 0;
const int ON = 1;

const string TILES = "TileArray";
const string TILE_TAG = "PressurePlate";
const string ROW = "row";
const string COLUMN = "column";
const string STATE = "state";
const string LIGHT = "solwhite001";
const string LIGHT_TAG = "Light";

object pc = GetFirstPC();

void debug_print(string msg)
{
    SendMessageToPC(pc, msg);
}