void modeCheckFpsSetup(){
  startWifi();
  moveFront = 1; //Start with slowest movemnent
  moveBack  = 1;
  for (int i = 0; i <= 5; i++ ) {
    angleBack[i] = random(360);
  }
  cnt = 0;
  clearScreens(COLOR_BACKGROUND, true);
  myTime = millis();

}
