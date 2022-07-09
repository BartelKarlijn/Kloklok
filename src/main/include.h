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

// variables
#include <configuration.h>
#include <main/globalvariables.h>

// Own subroutines
//   main
#include <main/setupSerial.h>
#include <main/setupBacklight.h>
//   tft
#include <tft/setupTft.h>
#include <tft/createClear.h>
#include <tft/createNeelde.h>
#include <tft/createAxis.h>
#include <tft/plotneedle.h>
//wifi
//#include <wifi\setup_AsyncWebserver.h>

