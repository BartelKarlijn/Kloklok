///////////////// TFT  //////////////////////////////
uint8_t tft_cs[6] = {TFT0_CS, TFT1_CS, TFT2_CS, TFT3_CS, TFT4_CS, TFT5_CS };

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite needle       = TFT_eSprite(&tft); // Sprite object for needle
TFT_eSprite needleAxis   = TFT_eSprite(&tft); // Sprite object for centre Axis
TFT_eSprite needleClear1 = TFT_eSprite(&tft); // Sprite object for clearing left side of needle
TFT_eSprite needleClear2 = TFT_eSprite(&tft); // Sprite object for clearing right side of needle
TFT_eSprite needleClear3 = TFT_eSprite(&tft); // Sprite object for clearing right side of needle
TFT_eSprite needleClear4 = TFT_eSprite(&tft); // Sprite object for clearing right side of needle

///////////////// Object sizes  //////////////////////////////
#define NEEDLE_WIDTH  NEEDLE_RADIUS * 2   // Width of needle
#define NEEDLE_LENGTH SCREEN_CENTER // Visible length without rounded corners
#define DIAL_WIDTH    SCREEN_CENTER * 2

// Angles
int16_t angleBack[6];      // Angle of back needle
int16_t angleFront[6];     
// How fast is the movement
int16_t moveFront;
int16_t moveBack;
// Backlight
int backlight;

// timing
unsigned long myTime;
int cnt;

//////////////// LED ///////////////////////
boolean startupError;

