// Configuration file

///////////////// Serial  ///////////////////////////
// Een, beide of geen enkele van de 2 onderstaande opties kunnen gebruikt worden
#define PRINTWEBSERIAL   //om Serial via webpagina ipadres/webserial te volgen
#define PRINTSERIAL      //om Serial via serial connectie te volgen
#define SERIALSPEED 115200

///////////////// Pins  //////////////////////////////
// already used in user_setup.h:
// Default pinmapping for SPI = MOSI gpio23, MISO gpio19, CLK gpio18, CS gpio5 (but this we're doing ourselves)

/*   part below is copied from User_Setup.h
#define GC9A01_DRIVER
#define TFT_SDA_READ
#define TFT_MOSI   23 // In some display driver board, it might be written as "SDA" and so on.
//#define TFT_MISO 19 // On our module, there is no MISO or "SDI"
#define TFT_SCLK   18
//#define TFT_CS    5 // Chip select control pin
#define TFT_DC     21 // Data Command control pin
#define TFT_RST    22 // Reset pin (could connect to Arduino RESET pin)
#define SPI_FREQUENCY  40000000
*/
#define TFT__BL    19    //Backlight

#define TFT0_CS    33    //Chip Select pin tftx
#define TFT1_CS    32    //Chip Select pin tftx
#define TFT2_CS    26    //Chip Select pin tftx
#define TFT3_CS    25    //Chip Select pin tftx
#define TFT4_CS    13    //Chip Select pin tftx
#define TFT5_CS    27    //Chip Select pin tftx

///////////////// TFT backlight  //////////////////////////////
#define PWMFreq    5000
#define PWMChannel    0
#define PWMResolution 8  // 8bit = 25
#define BACKLIGHT   255  // brightness 0-255
#define BACKL_BLINK   5  // nr of times the BL blinks at startup

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

///////////////// Screen Orientation  //////////////////////////////
#define ROT_UP    0
#define ROT_RIGHT 90
#define ROT_DOWN  180
#define ROT_LEFT  270
#define TFT_ORIENTATION (ROT_RIGHT / 90)  // the same for all 6 screens as we're using only 1 tft object

///////////////// Colors  //////////////////////////////
#define COLOR_BITS_PER_PIXEL 16     //16 appeared to be the most performant
#define COLOR_BACKGROUND TFT_BLUE   //  TFT_BLACK
#define COLOR_NEEDLE     TFT_YELLOW //  TFT_WHITE
#define COLOR_TRANSP     TFT_PINK
#define COLOR_TEST       TFT_RED

///////////////// wifi  //////////////////////////////
// names below are used as AccessPoint name and calls from master
#define NAME_MASTER "KloKlok_masterX000"
#define NAME_SLAVE2 "KloKlok_slave_0X00" 
#define NAME_SLAVE3 "KloKlok_slave_00X0" 
#define NAME_SLAVE4 "KloKlok_slave_000X" 

///////////////// working modes  //////////////////////////////
#define MODE_CLOCK         0       // Regular clock mode
#define MODE_CLOCKDEMO     1       // 'Demo' clock by rapidly browsing nrs
#define MODE_CHECKFPS      2       // check how many fps we can achieve
#define MODE_DIGITSHOW     3       // Test digits one by one (no movement in between)
#define MODE_DIGITTEST     4       // Do movement betwen digits
#define MODE_SLAVE         5
#define MODEDESC_CHECKFPS  "CheckPFS"
#define MODEDESC_CLOCK     "Clock"
#define MODEDESC_CLOCKDEMO "ClockDemo"
#define MODEDESC_DIGITSHOW "DigitShow"
#define MODEDESC_DIGITTEST "DigitTest" 
#define MODEDESC_SLAVE     "Slave"
#define COUNT_MODES 6
String modeTbl[COUNT_MODES] = {MODEDESC_CLOCK, MODEDESC_CLOCKDEMO, MODEDESC_CHECKFPS, MODEDESC_DIGITSHOW, MODEDESC_DIGITTEST, MODEDESC_SLAVE};

///////////////// Commands  //////////////////////////////
// Commmands are fixed lenght of 1
#define COMMAND_CLEARS    1  // Clear screen without.                     Param 0=clear axis, 1=plot axis
#define COMMAND_SHOWDG    3  // Show digit                                Param = digit to show
#define COMMAND_MOVETO    4  // Move to digit                             Param = digit moving to
#define COMMAND_SETMOD    5  // Set in specific mode                      Param = new mode
#define REACTIONTIME   1000  // Slaves are reacting 1000s after command  