void setupTft() {
  tft.begin();
  tft.setRotation(TFT_ORIENTATION);       // 0 1 2 3 : rotate 90°
  tft.fillScreen(COLOR_TEST);

  // Define where the needle pivot point is on the TFT before
  // creating the needle so boundary calculation is correct
  tft.setPivot(SCREEN_CENTER, SCREEN_CENTER);

  // Reset needle position to 0
  for (int i = 0; i <= 5; i++ ) {
    pinMode( tft_cs[i], OUTPUT);   // Chip Select is active low.
    
    digitalWrite( tft_cs[i], LOW);
    needleAxis.pushRotated( 90, COLOR_TRANSP);
    digitalWrite( tft_cs[i], HIGH);

    angleBack[i]  = random(359); // random speed in range 0 to 360
    angleFront[i] = random(359); // random speed in range 0 to 360
  }

}