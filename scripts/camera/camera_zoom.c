void main()
{
    //Goes in onEnter event in Area Properties

    //I don't fully understand the numbers but this sets the camera to the correct
    //height. The -1.0f is the direction - it's just telling it to keep it as it is
    object oPC = GetFirstPC();
    SetCameraFacing(-1.0f, 6.0f, 0.0f);
    SetCameraMode(oPC, CAMERA_MODE_STIFF_CHASE_CAMERA);

    //Trigger has a script to lock the camera

    /* Removed because this is causing bugs
    object oTrigger = GetObjectByTag("CameraLockTrigger");
    location lTrigger = GetLocation(oTrigger);
    AssignCommand(oPC,ActionForceMoveToLocation(lTrigger, FALSE, 3.0));
    */
}
