// Configuration file

///////////////// Serial  ///////////////////////////
// Een, beide of geen enkele van de 2 onderstaande opties kunnen gebruikt worden
#define PrintWebserial   //om Serial via webpagina ipadres/webserial te volgen
#define PrintSerial      //om Serial via serial connectie te volgen
#define SerialSpeed 115200

///////////////// Pins  //////////////////////////////
// already used in user_setup.h:
//#define TFT_MOSI 23 // In some display driver board, it might be written as "SDA" and so on.
//#define TFT_SCLK 18
//#define TFT_DC   16 // Data Command control pin
//#define TFT_RST  4  // Reset pin (could connect to Arduino RESET pin)
//#define TFT_BL   32 // LED back-light

#define TFT1_CS       17    //Chip Select pin tftx
#define TFT2_CS       19    //Chip Select pin tftx
#define TFT3_CS       21    //Chip Select pin tftx
#define TFT0_CS       22    //Chip Select pin tftx
#define TFT4_CS       25    //Chip Select pin tftx
#define TFT5_CS       26    //Chip Select pin tftx
#define TFT__BL       27    //Backlight
#define LED_PIN        2    //Internal LED

///////////////// TFT backlight  //////////////////////////////
#define PWMFreq 5000
#define PWMChannel 0
#define PWMResolution 8
#define LEDSTARTBLINK 4  // How many blinks at start?

///////////////// TFT objects  //////////////////////////////
#define SCREEN_CENTER 120                // center of screen
#define NEEDLE_RADIUS  16                // diameter of needle
// Extra margin for the sprite width to cover the rotation from previous position
// rotation/frame = 1-4 deg
// sin(rotation/frame) * DIAL_CENTER
#define NEEDLE_CLEAR1 3   // area of needle to clear
#define NEEDLE_CLEAR2 5   // area of needle to clear
#define NEEDLE_CLEAR3 7   // area of needle to clear
#define NEEDLE_CLEAR4 9   // area of needle to clear

///////////////// Colors  //////////////////////////////
#define COLOR_BITS_PER_PIXEL 16     //16 appeared to be the most performant
#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_NEEDLE     TFT_WHITE
#define COLOR_TRANSP     TFT_PINK
#define COLOR_TEST       TFT_RED
