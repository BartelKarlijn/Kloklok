void modeCheckFpsSetup(){
  startWifi();
  moveFront = 1; //Start with slowest movemnent
  moveBack  = 1;
  for (int i = 0; i <= 5; i++ ) {
    angleBack[i] = random(360);
  }
  fpsCnt = 0;
  clearScreens(COLOR_BACKGROUND, true);
  myTime = millis();
  
  Println("Now in mode CheckFPS");
  delay(100);
}
