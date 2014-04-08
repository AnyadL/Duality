#include "global"

void main()
{
    object telescope = GetObjectByTag("musical_telescope");
    object music_source = GetArea(telescope);

    MusicBackgroundChangeDay(GetArea(pc), MusicBackgroundGetDayTrack(music_source));
    MusicBackgroundChangeNight(GetArea(pc), MusicBackgroundGetDayTrack(music_source));
    MusicBackgroundPlay(GetArea(pc));
}