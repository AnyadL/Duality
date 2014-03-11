/* Time in seconds between day-to-night and night-to-day transitions */
const float FADE_TRANSITION_TIME = 0.0;

/* Sets the area lighting to the Night setting */
void DarkenArea() {
    DayToNight(GetFirstPC(), FADE_TRANSITION_TIME);
}

/* Sets the area lighting to the Day setting */
void BrightenArea() {
    NightToDay(GetFirstPC(), FADE_TRANSITION_TIME);
}