#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

void plottest() {
  for (int i = 0; i <= 5; i++ ) {
    digitalWrite( tft_cs[i], LOW);
    needle.pushRotated( 90, COLOR_TRANSP);
    digitalWrite( tft_cs[i], HIGH);
    needle.pushRotated( 90, COLOR_TRANSP);
  }
}


// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  setupSerial();
  setupBacklight();
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)

  //wifi
  setup_ConnectKnownWifi();  // Aan gekende wifi connecteren
  setup_AsyncWebserver();    // webserver om html te tonen 
  setup_CreateAccessPoint(); // Toch eigen AccessPoint opzetten als gekende wifi niet gelukt.


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

  myTime = millis();
  SetupFinished();
}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  unsigned long myTimeRef;
  
  // Plot needle at random angle 
  for (int i = 0; i <= 5; i++ ) {
    //plottest();
    plotNeedle(angleBack[i], moveBack, angleFront[i], moveFront, tft_cs[i]);
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
    Print(String(cnt));
    Print(" screens in ");
    Print(String(myTimeRef));
    Print(" ms = ");
    Print(String( cnt * 1000/ myTimeRef));
    Println("fps");
    //tft.fillScreen(COLOR_BACKGROUND);
    moveFront++;
    backlight = backlight + 50;
    if (backlight > 255) {
      backlight = 0;
//      ledcWrite(PWMChannel, backlight);
      }
    Print("Backlight ");
    Println(String(backlight));

    if (moveFront >= 5) { 
      moveFront = 1; 
      moveBack++;
      if (moveBack >= 5) { moveBack = 1;}
    }
    myTime = millis();
    cnt = 0;
  }

}
