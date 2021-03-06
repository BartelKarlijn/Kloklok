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

//   tft
#include <tft/setupTft.h>
#include <tft/clearScreens.h>
#include <tft/createNeelde.h>
#include <tft/createAxis.h>
#include <tft/plotNeedle.h>
#include <tft/showDigit.h>
#include <tft/calculateMovementToNr.h>
#include <tft/moveNextDigit.h>

//wifi
#include <wifi\html_buttonSimple.h>  // routine om simpele pushbutton te maken
#include <wifi\html_buttonUpDown.h>  // routine om PID parameters up/down aan te passen
#include <wifi\html_buttonLink.h>    // routine om knoppen met link te maken
#include <wifi\html_joystick.h>      // Poging om joystick te maken
#include <wifi\html_sendPage.h>      // send the (config) html string
#include <wifi\html_processor.h>     // vervangt placeholder in sendPage
#include <wifi\buttonChange.h>       // acties die gebeuren als je op knop drukt
#include <wifi\setup_AsyncWebserver.h> 
#include <wifi\setup_ConnectKnownWifi.h>
#include <wifi\setup_CreateAccessPoint.h>

//  operationModes
#include <ModeOperation/modeCheckFps.h>
#include <ModeOperation/modeClock.h>
#include <ModeOperation/modeClockDemo.h>
#include <ModeOperation/modeDigitShow.h>
#include <ModeOperation/modeDigitTest.h>
