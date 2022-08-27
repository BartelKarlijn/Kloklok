#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  setupSerial();
  delay(1000);
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  setupBacklight();
  // Create the Sprites
//  needle1 = createNeedle( NEEDLE_CLEAR1 );
//  needle2 = createNeedle( NEEDLE_CLEAR2 );
//  needle3 = createNeedle( NEEDLE_CLEAR3 );
//  needle4 = createNeedle( NEEDLE_CLEAR4 );
  createNeedle1();
  createNeedle2();
  createNeedle3();
  createNeedle4();
  createAxis();
  // tft
  setupTft();

  SetupFinished();
}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  switch (operationMode)
  {
  case OPERATION_CHECKFPS:
    modeCheckFpsLoop();
    break;
  case OPERATION_CLOCK:
    modeClockLoop();
    break;
  case OPERATION_CLOCKDEMO:
    modeClockDemoLoop();
    break;
  case OPERATION_DIGITSHOW:
    modeDigitShowLoop();
    break;
  case OPERATION_DIGITDANCE:
    modeDigitDanceLoop();
    break;
  case OPERATION_SLAVE:
    modeSlaveLoop();
    break;
  default:
    Println("Impossible operationMode in loop");
    break;
  }
}
