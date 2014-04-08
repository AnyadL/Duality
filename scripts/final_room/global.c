/* Filename: global.c
 * Author: Alexander Cheung
 *
 * This file contains declarations for global parameters used throughout the
 * final room module. These include scenario specific integers, string tags,
 * etc.
 */

const int NUM_PIXELS = 36;
const int NUM_ROUNDS = 5;
const int DIM = 6;
const int NUM_MIRRORS = 7;
const int SPLASH = 2;
const float SPACING = 1.8;
const float START_X = 15.0;
const float START_Y = 15.0;
const int SECS_PER_HB = 6;

const string PIXELS = "pixel_array";
const string PIXEL_TAG = "pixel";
const string PIXEL_BLUEPRINT = "solwhite001";
const string CANVAS_BLUEPRINT = "solwhite002";
const string DARK_PIXEL_BLUEPRINT = "solwhite003";
const string ROW = "row";
const string COLUMN = "column";
const string MIRROR_TAG = "shadow_mirror";
const string MIA_SHADOW_BLUEPRINT = "spectre001";
const string SHADOW_BLUEPRINT = "spectre002";
const string SHADOW_TAG = "shadow_kara";
const string MIA_SHADOW_TAG = "shadow";
const string ROUNDS_PASSED = "num_rounds_completed";
const string DYING = "dying";
const string SHADOW_CUTSCENE_BLUEPRINT = "spectre005";
const string SPAWNER_BLUEPRINT = "prssplate2";

const int NUM_TAUNTS = 6;
const int NUM_WRONGS = 4;
const int NUM_ATTACKS = 7;
const int NUM_APPROACHES = 4;

object pc = GetFirstPC();

const string SHADOW_TAUNT_TAG = "shadow_taunt_";
const string SHADOW_ATTACK_TAG = "shdw_atk";
const string MIA_WRONG_TAG = "mia_wrong_";
const string MIA_RIGHT_TAG = "mia_right_";
const string MIA_GIVE_UP_TAG = "mia_give_up";
const string SHADOWS_APPROACH_1_TAG = "mia_have_stop";
const string SHADOWS_APPROACH_2_TAG = "mia_too_many";
const string SHADOWS_APPROACH_3_TAG = "mia_stay_alive";
const string SHADOWS_APPROACH_4_TAG = "mia_dont_panic";
const string SHADOW_CUTSCENE_TAG = "shadow_kara_cutscene";

const string SHADOW_MULTIPLY_POINT_TAG = "shadow_multiply_";

const string SHADOW_RIGHT_1_TAG = "shadow_right_1";
const string MIA_RIGHT_2_TAG = "mia_right_2";
const string SHADOW_RIGHT_2_TAG = "shadow_right_2";
const string SHADOW_RIGHT_3_TAG = "shadow_right_3";
const string MIA_RIGHT_4_TAG = "mia_right_4";

void debug_print(string msg)
{
    SendMessageToPC(pc, msg);
}