#include "global"

void main()
{
    object telescope = GetObjectByTag("musical_telescope");
    object music_source = GetArea(telescope);
    MusicBackgroundStop(GetArea(pc));

    MusicBackgroundChangeDay(GetArea(pc), MusicBackgroundGetNightTrack(music_source));
    MusicBackgroundChangeNight(GetArea(pc), MusicBackgroundGetNightTrack(music_source));
}