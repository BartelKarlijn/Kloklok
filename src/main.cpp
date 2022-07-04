#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

void plottest() {
  for (int i = 0; i <= 5; i++ ) {
    digitalWrite( tft_cs[i], LOW);
    needle.pushRotated( 90, COLOR_TRANSP);
    digitalWrite( tft_cs[i], HIGH);
}
}

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  setupSerial();
  setupIntledStart();

  // Create the Sprites
  createNeedle();
  createAxis();
  createClear1();
  createClear2();
  createClear3();
  createClear4();
  // tft
  setupTft();

  moveFront = 4;
  moveBack  = 2;

  // Backlight
  backlight = 50;
  pinMode(TFT__BL, OUTPUT);
  digitalWrite(TFT__BL, HIGH);
  //ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  //ledcAttachPin(TFT__BL, PWMChannel);
  //ledcWrite(PWMChannel, backlight);

  myTime = millis();
  setupIntledAllOK();
}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  unsigned long myTimeRef;
  
  // Plot needle at random angle 
  for (int i = 0; i <= 5; i++ ) {
    plottest();
    //plotNeedle(angleBack[i], moveBack, angleFront[i], moveFront, tft_cs[i]);
    angleBack[i] = angleBack[i] + moveBack;
    if (angleBack[i] >= 360) {angleBack[i] = 0; }
    angleFront[i] = angleFront[i] + moveFront;
    if (angleFront[i] >= 360) {angleFront[i] = 0; }
  }

  // timing
  cnt++;
  //Serial.println(cnt);
  if ( cnt >= 90 ) {
    myTimeRef = millis() - myTime;
    Serial.print(cnt);
    Serial.print(" screens in ");
    Serial.print(myTimeRef);
    Serial.print(" ms = ");
    Serial.print(cnt * 1000/ myTimeRef);
    Serial.println("fps");
    tft.fillScreen(COLOR_BACKGROUND);
    moveFront++;
    backlight = backlight + 50;
    if (backlight > 255) {
      backlight = 0;
//      ledcWrite(PWMChannel, backlight);
      }
    Serial.print("Backlight ");
    Serial.println(backlight);

    if (moveFront >= 5) { 
      moveFront = 1; 
      moveBack++;
      if (moveBack >= 5) { moveBack = 1;}
    }
    myTime = millis();
    cnt = 0;
  }

}
