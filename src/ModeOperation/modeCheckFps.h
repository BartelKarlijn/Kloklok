void modeCheckFpsSetup(){
  modeOld = mode;
  moveFront = 1; //Start with slowest movemnent
  moveBack  = 1;
  for (int i = 0; i <= 5; i++ ) {
    angleBack[i] = random(360);
  }
  cnt = 0;
  clearScreens(COLOR_BACKGROUND, true);
  myTime = millis();
}

void modeCheckFpsLoop(){
  unsigned long myTimeRef;

  // Plot needle at random angle 
  for (int i = 0; i <= 5; i++ ) {
    angleBack[i] = angleBack[i] + moveBack;
    if (angleBack[i] >= 360) {angleBack[i] = 0; }
    angleFront[i] = angleFront[i] + moveFront;
    if (angleFront[i] >= 360) {angleFront[i] = 0; }
    plotNeedle(angleBack[i], moveBack, angleFront[i], moveFront, i);
  }
  delay(1);

  // timing
  cnt++;
  //Serial.println(cnt);
  if ( cnt >= 90 ) {
    myTimeRef = millis() - myTime;
    Print(String(cnt));
    Print(" screens in ");
    Print(String(myTimeRef));
    Print(" ms = ");
    Print(String( cnt * 1000/ myTimeRef));
    Println("fps");
    delay(100);
    moveFront++;

    if (moveFront >= 5) { 
      moveFront = 1; 
      moveBack++;
      if (moveBack >= 5) { moveBack = 1;}
    }
    myTime = millis();
    cnt = 0;
  }

}
