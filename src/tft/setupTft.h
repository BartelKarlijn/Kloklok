void setupTft() {
  tft.begin();
  tft.setRotation(3);       // 0 1 2 3 : rotate 90°
  tft.fillScreen(COLOR_TEST);

  // Define where the needle pivot point is on the TFT before
  // creating the needle so boundary calculation is correct
  tft.setPivot(SCREEN_CENTER, SCREEN_CENTER);
}