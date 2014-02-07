void main()
{
	//Goes in OnHeartbeat event in Area Properties - Should theoretically work in OnEnter, but
	//does not for some reason
	
	//Locks the camera height of the main Pc. TRUE is lock, FALSE is unlock

    LockCameraDistance(GetFirstPC(),TRUE);
}