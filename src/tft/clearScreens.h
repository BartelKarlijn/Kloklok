void clearScreens(int8_t color) {
  for (int i = 0; i <= 5; i++) {
    // Clear screen if needed
    // Pull cs_pin low to write to screen
    digitalWrite( tft_cs[i], LOW);
    tft.fillScreen(color);
    digitalWrite( tft_cs[i], HIGH);
  }
}
