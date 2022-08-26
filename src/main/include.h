#include <Arduino.h>


// External libraries
// read and save dta
#include <Preferences.h>   // om op ESP32 eeprom te kunnen lezen en schrijven
// TFT
#include <TFT_eSPI.h>
// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <WebSerial.h>
#include <time.h>

// Own libraries
// variables
#include <configuration.h>
#include <main/globalvariables.h>
#include <main/digit.h>

// Own subroutines
//   main
#include <main/setupSerial.h>
#include <main/setupBacklight.h>
#include <main/print.h>
#include <main/save_eprom.h>
#include <main/readSerial.h>

// clock
#include <clock/parseMessage.h>
#include <clock/distributeCommand.h>

//   tft
#include <tft/setupTft.h>
#include <tft/clearScreens.h>
#include <tft/createNeelde.h>
#include <tft/createAxis.h>
#include <tft/plotNeedle.h>
#include <tft/showDigit.h>
#include <tft/calculateMovementToNr.h>
#include <tft/calculateMovementRandom.h>
#include <tft/moveNextDigit.h>

//wifi
#include <wifi/html_buttonSimple.h>  // routine to create simpel pushbutton
#include <wifi/html_buttonUpDown.h>  // routine to change parameter up or down
#include <wifi/html_buttonLink.h>    // routine to create button with a link
#include <wifi/html_doubleInput.h>   // 2 input fields + submit button
#include <wifi/html_sendPage.h>      // send the (config) html string
#include <wifi/html_processor.h>     // replaces placeholder in sendPage
#include <wifi/buttonChange.h>       // actions happening if you ckick a button
#include <wifi/setup_AsyncWebserver.h> 
#include <wifi/setup_ConnectKnownWifi.h>
#include <wifi/setup_CreateAccessPoint.h>
#include <wifi/startWifi.h>
#include <wifi/stopWifi.h>

//  operationModes
#include <ModeOperation/modeCheckFpsSetup.h>
#include <ModeOperation/modeClockSetup.h>
#include <ModeOperation/modeClockDemoSetup.h>
#include <ModeOperation/modeDigitShowSetup.h>
#include <ModeOperation/modeDigitDanceSetup.h>
#include <ModeOperation/modeSlaveSetup.h>
#include <ModeOperation/checkStillSameMode.h>
#include <ModeOperation/modeCheckFpsLoop.h>
#include <ModeOperation/modeClockLoop.h>
#include <ModeOperation/modeClockDemoLoop.h>
#include <ModeOperation/modeDigitShowLoop.h>
#include <ModeOperation/modeDigitDanceLoop.h>
#include <ModeOperation/modeSlaveLoop.h>
