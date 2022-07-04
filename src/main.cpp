#include <Arduino.h>

#define TFT_MOSI 23 // In some display driver board, it might be written as "SDA" and so on.
#define TFT_SCLK 18
#define TFT_DC   21 // Data Command control pin
#define TFT_RST  22 // Reset pin (could connect to Arduino RESET pin)
#define TFT__BL  19    //Backlight

#define TFT0_CS  32    //Chip Select pin tftx
#define TFT1_CS  33    //Chip Select pin tftx
#define TFT2_CS  25    //Chip Select pin tftx
#define TFT3_CS  26    //Chip Select pin tftx
#define TFT4_CS  27    //Chip Select pin tftx
#define TFT5_CS  13    //Chip Select pin tftx

///////////////// TFT backlight  //////////////////////////////
#define PWMFreq 5000
#define PWMChannel 0
#define PWMResolution 8
#define LEDSTARTBLINK 4  // How many blinks at start?

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

void led(int pin) {
  ledcDetachPin(TFT_MOSI);
  ledcDetachPin(TFT_SCLK);
  ledcDetachPin(TFT_DC  );
  ledcDetachPin(TFT_RST );
  ledcDetachPin(TFT__BL );
  ledcDetachPin(TFT0_CS );
  ledcDetachPin(TFT0_CS );
  ledcDetachPin(TFT1_CS );
  ledcDetachPin(TFT2_CS );
  ledcDetachPin(TFT3_CS );
  ledcDetachPin(TFT4_CS );
  ledcDetachPin(TFT5_CS );

  ledcAttachPin(pin , PWMChannel);
}

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("beginnen") ; 
  
  // configure LED PWM functionalitites
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  
  // attach the channel to the GPIO to be controlled
  Serial.println("We zijn er klaar voor") ; 
  Serial.println("Mosi sClk, Dc, Rst, Bl, cs0-6");
}


// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  if (Serial.available() > 0) {
    // read the incoming string:
    String incomingString = Serial.readString();

    // prints the received data
    Serial.print("I received: ");
    Serial.println(incomingString);
    switch (toupper(incomingString[0]))
    {
    case 'M':
      led(TFT_MOSI);
      break;
    case 'C':
      led(TFT_SCLK);
      break;
    case 'D':
      led(TFT_DC);
      break;
    case 'R':
      led(TFT_RST);
      break;
    case 'B':
      led(TFT__BL);
      break;
    case '0':
      led(TFT0_CS);
      break;
    case '1':
      led(TFT1_CS);
      break;
    case '2':
      led(TFT2_CS);
      break;
    case '3':
      led(TFT3_CS);
      break;
    case '4':
      led(TFT4_CS);
      break;
    case '5':
      led(TFT5_CS);
      break;
    
    default:
      break;
    }  
  }

  ledcWrite(PWMChannel, 0);
  delay(3000);
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(PWMChannel, dutyCycle);
    delay(15);
    }
  ledcWrite(PWMChannel, 255);
  delay(3000);
}