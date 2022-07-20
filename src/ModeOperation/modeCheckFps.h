void modeCheckFpsSetup(){
  moveFront = 1;
  moveBack  = 1;

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
    plotNeedle(angleBack[i], moveBack, angleFront[i], moveFront, tft_cs[i]);
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
//    backlight = backlight + 50;
//    if (backlight > 255) {
//      backlight = 0;
//      ledcWrite(PWMChannel, backlight);
//      }
//    Print("Backlight ");
//    Println(String(backlight));

    if (moveFront >= 5) { 
      moveFront = 1; 
      moveBack++;
      if (moveBack >= 5) { moveBack = 1;}
    }
    myTime = millis();
    cnt = 0;
  }

}
