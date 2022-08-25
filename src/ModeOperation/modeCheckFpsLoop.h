void modeCheckFpsLoop(){
  unsigned long myTimeRef;
  
  checkStillSameMode ();
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
    Print(cnt);
    Print(" screens in ");
    Print(myTimeRef);
    Print(" ms = ");
    Print(cnt * 1000/ myTimeRef);
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
