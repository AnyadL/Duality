const int NUM_PIXELS = 25;
const int DIM = 5;
const float SPACING = 2.5;
const float START_X = 15.0;
const float START_Y = 15.0;

const string PIXELS = "pixel_array";
const string PIXEL_TAG = "pixel";
const string PIXEL_BLUEPRINT = "solwhite001";
const string ROW = "row";
const string COLUMN = "column";
const string MIRROR_TAG = "shadow_mirror";

object pc = GetFirstPC();

void debug_print(string msg)
{
    SendMessageToPC(pc, msg);
}