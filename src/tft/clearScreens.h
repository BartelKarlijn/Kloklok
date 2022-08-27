void clearScreens(int color, bool replotAxis) {
  for (int i = 0; i <= 5; i++) {
    // Clear screen if needed
    // Pull cs_pin low to write to screen
    digitalWrite( tft_csTbl[i], LOW);
    tft.fillScreen(color);
    if (replotAxis){
      needleAxis.pushRotated(90, COLOR_TRANSP);
    }
    digitalWrite( tft_csTbl[i], HIGH);
  }
}
