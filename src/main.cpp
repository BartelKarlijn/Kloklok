#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  setupSerial();
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
  switch (mode)
  {
  case MODE_CHECKFPS:
    modeCheckFpsLoop();
    break;
  case MODE_CLOCK:
    modeClockLoop();
    break;
  case MODE_CLOCKDEMO:
    modeClockDemoLoop();
    break;
  case MODE_DIGITSHOW:
    modeDigitShowLoop();
    break;
  case MODE_DIGITTEST:
    modeDigitTestLoop();
    break;
  case MODE_SLAVE:
    modeSlaveLoop();
    break;
  default:
    Println("Impossible modeOperation in loop");
    break;
  }
}
