#include <Arduino.h>

// This example draws an animated dial with a rotating needle.

// The dial is a jpeg image, the needle is created using a rotated
// Sprite. The example operates by reading blocks of pixels from the
// TFT, thus the TFT setup must support reading from the TFT CGRAM.

// The sketch operates by creating a copy of the screen block where
// the needle will be drawn, the needle is then drawn on the screen.
// When the needle moves, the original copy of the screen area is
// pushed to the screen to over-write the needle graphic. A copy
// of the screen where the new position will be drawn is then made
// before drawing the needle in the new position. This technique
// allows the needle to move over other screen graphics.

// The sketch calculates the size of the buffer memory required and
// reserves the memory for the TFT block copy.

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

//Pins
// already used in user_setup.h:
//#define TFT_MOSI 23 // In some display driver board, it might be written as "SDA" and so on.
//#define TFT_SCLK 18
//#define TFT_DC   16 // Data Command control pin
//#define TFT_RST  4  // Reset pin (could connect to Arduino RESET pin)
//#define TFT_BL   32 // LED back-light

#define TFT0_CS       22    //Chip Select pin tftx
#define TFT1_CS       17    //Chip Select pin tftx
#define TFT2_CS       19    //Chip Select pin tftx
#define TFT3_CS       21    //Chip Select pin tftx
#define TFT4_CS       25    //Chip Select pin tftx
#define TFT5_CS       26    //Chip Select pin tftx
uint8_t tft_cs[6] = {TFT0_CS, TFT1_CS, TFT2_CS, TFT3_CS, TFT4_CS, TFT5_CS };

#define DIAL_CENTRE   120
#define NEEDLE_RADIUS  16                // diameter of needle
#define NEEDLE_WIDTH  NEEDLE_RADIUS * 2   // Width of needle
#define NEEDLE_LENGTH DIAL_CENTRE // Visible length without rounded corners
#define DIAL_WIDTH    DIAL_CENTRE * 2
// Extra margin for the sprite width to cover the rotation from previous position
// calculation = sin( max rotation / time / fps ) * DIAL_WIDTH
//    max rotation      = 360 deg
//    time for rotation = 5   sec
//    fps               = 20 
//    rotation/frame = 3.6deg
// this works out to 0.62 * 120px = 8.3
#define NEEDLE_CLEAR 4   // area of needle to clear

#define COLOR_BITS_PER_PIXEL 16
#define COLOR_BACKGROUND TFT_BLUE
#define COLOR_NEEDLE     TFT_YELLOW
#define COLOR_TRANSP     TFT_PINK


#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite needleFront = TFT_eSprite(&tft); // Sprite object for needle
TFT_eSprite needle      = TFT_eSprite(&tft); // Sprite object for needle
TFT_eSprite needleLeft  = TFT_eSprite(&tft); // Sprite object for clearing left side of needle
TFT_eSprite needleRight = TFT_eSprite(&tft); // Sprite object for clearing right side of needle

// Angles
int16_t angleBack[6];      // Angle of back needle
int16_t angleBackPrev[6];  // previous
int16_t angleFront[6];     
int16_t angleFrontPrev[6]; 

// timing
unsigned long myTime;
int cnt;


// =======================================================================================
// Create the needle Sprite
// =======================================================================================
void createNeedleFront(void){


}

void createNeedleFront(void)
{
  needleFront.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleFront.createSprite(NEEDLE_WIDTH + (2 * SPRITE_MARGIN), NEEDLE_LENGTH + NEEDLE_WIDTH );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleFront.setPivot(NEEDLE_RADIUS + SPRITE_MARGIN, NEEDLE_RADIUS);     // Set pivot point in this Sprite

  needleFront.fillSprite(COLOR_BACKGROUND); 

  // Draw the needle in the Sprite
  needleFront.fillRect(SPRITE_MARGIN, NEEDLE_RADIUS, NEEDLE_WIDTH, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleFront.fillCircle( NEEDLE_RADIUS + SPRITE_MARGIN, NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE);                //centre
  needleFront.fillCircle( NEEDLE_RADIUS + SPRITE_MARGIN, NEEDLE_LENGTH + NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE); //end
}

void plotNeedle(int16_t angleBack, int16_t angleBackPrev, int16_t angleFront, int16_t angleFrontPrev, uint8_t cs_pin) {
  // Pull cs_pin low to write to screen
  digitalWrite( cs_pin, LOW);
  needleFront.pushRotated( angleBack, COLOR_TRANSP);       //nothing transparant
  needleFront.pushRotated( angleFront, COLOR_BACKGROUND);  //background transparant
  // Pull cs_pin low to end write to screen
  //delay(1000);
  digitalWrite( cs_pin, HIGH);
}


// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  Serial.begin(115200); // Debug only
  Serial.println("Setup begonnen");
  tft.begin();
  tft.setRotation(1);       // 0 1 2 3 : rotate 90°
  tft.fillScreen(TFT_RED);

  // Define where the needle pivot point is on the TFT before
  // creating the needle so boundary calculation is correct
  tft.setPivot(DIAL_CENTRE, DIAL_CENTRE);

  // Create the needle Sprite
  createNeedleFront();


  // Reset needle position to 0
  for (int i = 0; i <= 5; i++ ) {
    pinMode( tft_cs[i], OUTPUT);   // Chip Select is active low.
    angleBack[i]  = random(359); // random speed in range 0 to 360
    angleFront[i] = random(359); // random speed in range 0 to 360
    angleFrontPrev[i] = angleFront[i];
    angleBackPrev[i]  = angleBack[i];
  }

  myTime = millis();
  Serial.println("Setup gedaan");

}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {

  unsigned long myTimeRef;
  
  // Plot needle at random angle 
  for (int i = 0; i <= 5; i++ ) {
//    plotNeedle(angleBack[i], angleFront[i], angleBackPrev[i], angleFrontPrev[i], tft_cs[i]);
    plotNeedle(angleBack[i], angleBackPrev[i], angleFront[i], angleFrontPrev[i], tft_cs[i]);
    angleBackPrev[i] = angleBack[i];
    angleFrontPrev[i] = angleFront[i];
//    angleBack[i] = angleBack[i] + 2;
    angleFront[i] = angleFront[i] + 2;

  }

  // timing
  cnt++;
  //Serial.println(cnt);
  if ( cnt >= 20 ) {
    myTimeRef = millis() - myTime;
    Serial.print(cnt);
    Serial.print(" screens in ");
    Serial.print(myTimeRef);
    Serial.print(" ms = ");
    Serial.print(cnt * 1000/ myTimeRef);
    Serial.println("fps");
    tft.fillScreen(COLOR_BACKGROUND);
    for (int i = 0; i <= 5; i++ ) {
      angleBackPrev[i] = angleBack[i];
      angleFrontPrev[i] = angleFront[i];
  }

    myTime = millis();
    cnt = 0;
  }

}
