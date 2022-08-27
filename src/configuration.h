// Configuration file

///////////////// Serial  ///////////////////////////
// One, both or none of the Print options below can be used
#define PRINTWEBSERIAL   // follow print statements via web Serial.  Page adress: ipadres/webserial
#define PRINTSERIAL      // follow prints via serial connection
#define SERIALSPEED 115200

///////////////// Pins  //////////////////////////////
// already used in user_setup.h, and platformio.ini
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
#define TFT2_CS    27    //Chip Select pin tftx
#define TFT3_CS    13    //Chip Select pin tftx
#define TFT4_CS    25    //Chip Select pin tftx
#define TFT5_CS    26    //Chip Select pin tftx
#define TFT_COUNT   6
uint8_t tft_csTbl[TFT_COUNT] = {TFT0_CS, TFT1_CS, TFT2_CS, TFT3_CS, TFT4_CS, TFT5_CS };

///////////////// TFT backlight  //////////////////////////////
#define PWM_FREQ    5000
#define PWM_CHANNEL    0
#define PWM_RESOLUTION 8  // 8bit = 25
#define BACKLIGHT    255  // brightness 0-255
#define BACKL_BLINK    5  // nr of times the BL blinks at startup

///////////////// TFT objects  //////////////////////////////
#define SCREEN_CENTER 120                // center of screen
#define NEEDLE_RADIUS  16                // diameter of needle
#define NEEDLE_WIDTH  1+(NEEDLE_RADIUS * 2)   // Width of needle
#define NEEDLE_LENGTH SCREEN_CENTER // Visible length without rounded corners
#define DIAL_WIDTH    SCREEN_CENTER * 2
// Extra margin for the sprite width to cover the rotation from previous position
// rotation/frame = 1-4 deg
// sin(rotation/frame) * DIAL_CENTER
#define NEEDLE_CLEAR1 3   // area of needle to clear
#define NEEDLE_CLEAR2 5   // area of needle to clear
#define NEEDLE_CLEAR3 7   // area of needle to clear
#define NEEDLE_CLEAR4 9   // area of needle to clear

///////////////// Screen Orientation  //////////////////////////////
#define ROT_UP      0
#define ROT_RIGHT  90
#define ROT_DOWN  180
#define ROT_LEFT  270
#define ROT_COUNT   4
int16_t rotationTbl[ROT_COUNT] = {ROT_UP, ROT_RIGHT, ROT_DOWN, ROT_LEFT};
#define TFT_ORIENTATION (ROT_RIGHT / 90)  // the same for all 6 screens as we're using only 1 tft object

///////////////// Colors  //////////////////////////////
#define COLOR_BITS_PER_PIXEL 16     //16 appeared to be the most performant
#define COLOR_BACKGROUND TFT_BLUE   //  TFT_BLACK
#define COLOR_NEEDLE     TFT_YELLOW //  TFT_WHITE
#define COLOR_TRANSP     TFT_PINK
#define COLOR_TEST       TFT_RED

///////////////// Time  //////////////////////////////
const char* ntpServer          = "pool.ntp.org";
const long  gmtOffset_sec      = 3600;
const int   daylightOffset_sec = 3600;
#define DELAY_CATCHUP  5000     // Give slaves time to catch up after boot
#define DELAY_COOLDOWN 2000     // Waiting time between 2 mode Operation changes

///////////////// wifi  //////////////////////////////
// names below are used as AccessPoint name and calls from master
#define NAME_DESC_MASTER "KloKlok_masterX000"
#define NAME_DESC_SLAVE1 "KloKlok_slave_0X00" 
#define NAME_DESC_SLAVE2 "KloKlok_slave_00X0" 
#define NAME_DESC_SLAVE3 "KloKlok_slave_000X" 
#define NAME_DESC_COUNT 4
String nameTbl[NAME_DESC_COUNT] = {NAME_DESC_MASTER, NAME_DESC_SLAVE1, NAME_DESC_SLAVE2, NAME_DESC_SLAVE3};

///////////////// movement modes  //////////////////////////////
// Describing how much action is shown when moving from one to another digit
#define MOVEMENT_MIN 0   // as little movement as possible
#define MOVEMENT_MAX 1   // as much movement as possible
#define MOVEMENT_FUN 2   // balanced
#define MOVEMENT_DESC_MIN "minimum"
#define MOVEMENT_DESC_MAX "maximum"
#define MOVEMENT_DESC_FUN "balanced"
#define MOVEMENT_COUNT 3
String movementTbl[MOVEMENT_COUNT] = {MOVEMENT_DESC_MIN, MOVEMENT_DESC_MAX, MOVEMENT_DESC_FUN };
#define RANDOM_OFF 0
#define RANDOM_ON  1
#define RANDOM_DESC_OFF "normal"
#define RANDOM_DESC_ON  "random"
#define RANDOM_DESCCOUNT 2
String randomTbl[RANDOM_DESCCOUNT] = {RANDOM_DESC_OFF, RANDOM_DESC_ON};

///////////////// working modes  //////////////////////////////
#define OPERATION_CLOCK          0       // Regular clock mode
#define OPERATION_CLOCKDEMO      1       // 'Demo' clock by rapidly browsing nrs
#define OPERATION_CHECKFPS       2       // check how many fps we can achieve
#define OPERATION_DIGITSHOW      3       // Test digits one by one (no movement in between)
#define OPERATION_DIGITDANCE     4       // Do movement betwen digits
#define OPERATION_SLAVE          5
#define OPERATION_DESC_CHECKFPS   "CheckPFS"
#define OPERATION_DESC_CLOCK      "Clock"
#define OPERATION_DESC_CLOCKDEMO  "ClockDemo"
#define OPERATION_DESC_DIGITSHOW  "DigitShow"
#define OPERATION_DESC_DIGITDANCE "DigitDance" 
#define OPERATION_DESC_SLAVE      "Slave"
#define OPERATION_DESC_COUNT 6
String operationTbl[OPERATION_DESC_COUNT] = {OPERATION_DESC_CLOCK, OPERATION_DESC_CLOCKDEMO, OPERATION_DESC_CHECKFPS, OPERATION_DESC_DIGITSHOW, OPERATION_DESC_DIGITDANCE, OPERATION_DESC_SLAVE};

///////////////// Commands  //////////////////////////////
// Commmands are fixed lenght of 1
#define COMMAND_CLEARS    1  // Clear screen without.                     Param 0=clear axis, 1=plot axis
#define COMMAND_SHOWDG    3  // Show digit                                Param = digit to show
#define COMMAND_MOVETO    4  // Move to digit                             Param = digit moving to
#define COMMAND_RANDOM    5  // Move to random digit
#define COMMAND_SETMOD    6  // Set in specific mode                      Param = new mode
#define COMMAND_SETROT    7  // Set rotation
#define COMMAND_SETMOV    8  // Set movementmode
#define COMMAND_SETSAV    9  // Save settings
#define CMD_START        '<' // char
#define CMD_STOP         '>' // char
