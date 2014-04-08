#include "in_g_cutscene"
#include "global"

float delay = 1.0;
float fade_duration = 2.5;

void scene_gestalt();
void play_audio(float delay);
void ghost();

void main()
{
    if (GetEnteringObject() == pc)
        scene_gestalt();
        //DelayCommand(delay/10, scene_gestalt());
}

void play_audio(float delay)
{
    DelayCommand(delay, SoundObjectPlay(GetObjectByTag("mia_fin_mono")));
}

void scene_gestalt()
{
    float time = 0.0;
    float offset = 1.0;
    object p1 = GetObjectByTag("intro_p1_start");
    object p2 = GetObjectByTag("intro_p2_start");
    object p2e = GetObjectByTag("intro_p2_end");
    object p3 = GetObjectByTag("intro_p3");

    /* Initialize */
    GestaltStartCutscene(pc);
    GestaltCameraFade(time, pc, FADE_CROSS, FADE_SPEED_MEDIUM, fade_duration);
    ghost();

    /* Setup */
    time = 2*delay;
    GestaltInvisibility(time, pc);
    GestaltCameraFacing(time, 63.0, 10.0, 85.0, pc);
    play_audio(time);

    /* Pass 1 */
    GestaltJump(time, pc, p1);
    GestaltActionMove(time + offset, pc, p2, FALSE, 0.0, 5*delay);

    /* Pass 2 */
    time = 7*delay;
    GestaltCameraFade(time - offset, pc, FADE_CROSS, FADE_SPEED_MEDIUM, fade_duration);
    GestaltCameraFacing(time + offset, 293.0, 10.0, 85.0, pc);
    GestaltJump(time, pc, p2);
    GestaltActionMove(time + offset, pc, p2e, FALSE, 0.0, 5*delay);


    /* Pass 3 (zoom into shadow) */
    time = 12*delay;
    GestaltCameraFade(time - offset, pc, FADE_CROSS, FADE_SPEED_MEDIUM, fade_duration);
    GestaltJump(time + offset, pc, p3);
    GestaltCameraMove(time + offset, 260.0, 20.0, 85.0, 280.0, 10.0, 85.0, 5*delay, 60.0, pc);

    /* Clean up and end cutscene */
    time = 16 * delay;
    DelayCommand(time, FadeToBlack(pc));
    //GestaltCameraFade(time - offset, pc, FADE_CROSS, FADE_SPEED_MEDIUM, fade_duration);

    /* Trigger ScriptEase */
    time = 18 * delay;
    GestaltClearEffect(time, pc);
    GestaltStopCutscene(time, pc, "intro_end");

    time = time + offset;
    // GestaltCameraFacing(time, 270.0, 10.0, 75.0, pc);
    AssignCommand(pc, SetCameraFacing(270.0, 10.0));
    DelayCommand(time, AssignCommand(pc, SetFacing(270.0)));
    DelayCommand(time, SetLocked(GetObjectByTag("activate_easel_trigger"), FALSE));
    DelayCommand(time, FadeFromBlack(pc));
}

void ghost()
{
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectCutsceneGhost(), pc, 14.0);
}