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
// rotation/frame = 1-4 deg
// sin(rotation/frame) * DIAL_CENTER
#define NEEDLE_CLEAR1 2   // area of needle to clear
#define NEEDLE_CLEAR2 4   // area of needle to clear
#define NEEDLE_CLEAR3 6   // area of needle to clear
#define NEEDLE_CLEAR4 8   // area of needle to clear
#define NEEDLE_EXTRA 2   // Exra area to clear out

#define COLOR_BITS_PER_PIXEL 16
#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_NEEDLE     TFT_WHITE
#define COLOR_TRANSP     TFT_PINK
#define COLOR_TEST       TFT_RED

#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite needle       = TFT_eSprite(&tft); // Sprite object for needle
TFT_eSprite needleAxis   = TFT_eSprite(&tft); // Sprite object for centre Axis
TFT_eSprite needleClear1 = TFT_eSprite(&tft); // Sprite object for clearing left side of needle
TFT_eSprite needleClear2 = TFT_eSprite(&tft); // Sprite object for clearing right side of needle
TFT_eSprite needleClear3 = TFT_eSprite(&tft); // Sprite object for clearing right side of needle
TFT_eSprite needleClear4 = TFT_eSprite(&tft); // Sprite object for clearing right side of needle
TFT_eSprite needleExtra  = TFT_eSprite(&tft); // Sprite object for clearing right side of needle

// Angles
int16_t angleBack[6];      // Angle of back needle
int16_t angleFront[6];     

// timing
unsigned long myTime;
int cnt;


// =======================================================================================
// Create the needle Sprite
// =======================================================================================
void createNeedle(void) {
  needle.setColorDepth(COLOR_BITS_PER_PIXEL);
  needle.createSprite(NEEDLE_WIDTH , NEEDLE_LENGTH );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needle.setPivot(NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needle.fillSprite(COLOR_NEEDLE); 

  // Punch circle hole
  needle.fillCircle( NEEDLE_RADIUS, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createAxis() {
  needleAxis.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleAxis.createSprite( NEEDLE_WIDTH , NEEDLE_WIDTH );  // create the Axis Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleAxis.setPivot(NEEDLE_RADIUS, NEEDLE_RADIUS);     // Set pivot point in this Sprite

  needleAxis.fillSprite(COLOR_BACKGROUND); 

  // Draw the Axis in the Sprite
  needleAxis.fillCircle(NEEDLE_RADIUS, NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE);

}

void createClear1() {
  needleClear1.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleClear1.createSprite( NEEDLE_CLEAR1 , NEEDLE_LENGTH );  // create the Clearing Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleClear1.setPivot( NEEDLE_CLEAR1 - NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needleClear1.fillSprite(COLOR_NEEDLE);

  // Draw part to be deleted
  //needleClear1.drawLine(0, 0, NEEDLE_CLEAR1, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleClear1.fillTriangle( NEEDLE_CLEAR1, 0, 0, NEEDLE_LENGTH, NEEDLE_CLEAR1, NEEDLE_LENGTH, COLOR_BACKGROUND);
  // Punch circle hole
  needleClear1.fillCircle( 0, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createClear2() {
  needleClear2.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleClear2.createSprite( NEEDLE_CLEAR2 , NEEDLE_LENGTH );  // create the Clearing Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleClear2.setPivot( NEEDLE_CLEAR2 - NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needleClear2.fillSprite(COLOR_NEEDLE);

  // Draw part to be deleted
  //needleClear2.drawLine(0, 0, NEEDLE_CLEAR2, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleClear2.fillTriangle( NEEDLE_CLEAR2, 0, 0, NEEDLE_LENGTH, NEEDLE_CLEAR2, NEEDLE_LENGTH, COLOR_BACKGROUND);
  // Punch circle hole
  needleClear2.fillCircle( 0, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createClear3() {
  needleClear3.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleClear3.createSprite( NEEDLE_CLEAR3 , NEEDLE_LENGTH );  // create the Clearing Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleClear3.setPivot( NEEDLE_CLEAR3 - NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needleClear3.fillSprite(COLOR_NEEDLE);

  // Draw part to be deleted
  //needleClear3.drawLine(0, 0, NEEDLE_CLEAR3, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleClear3.fillTriangle( NEEDLE_CLEAR3, 0, 0, NEEDLE_LENGTH, NEEDLE_CLEAR3, NEEDLE_LENGTH, COLOR_BACKGROUND);
  // Punch circle hole
  needleClear3.fillCircle( 0, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createClear4() {
  needleClear4.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleClear4.createSprite( NEEDLE_CLEAR4 , NEEDLE_LENGTH );  // create the Clearing Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleClear4.setPivot( NEEDLE_CLEAR4 - NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needleClear4.fillSprite(COLOR_NEEDLE);

  // Draw part to be deleted
  //needleClear4.drawLine(0, 0, NEEDLE_CLEAR4, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleClear4.fillTriangle( NEEDLE_CLEAR4, 0, 0, NEEDLE_LENGTH, NEEDLE_CLEAR4, NEEDLE_LENGTH, COLOR_BACKGROUND);
  // Punch circle hole
  needleClear4.fillCircle( 0, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createExtra() {
  needleExtra.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleExtra.createSprite( NEEDLE_EXTRA , NEEDLE_LENGTH );  // create the Clearing Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleExtra.setPivot( - NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needleExtra.fillSprite(COLOR_BACKGROUND);
}

void plotNeedle(int16_t angleBack, int16_t movementBack, int16_t angleFront, int16_t MovementFront, uint8_t cs_pin) {
  int16_t angle;
  // Pull cs_pin low to write to screen
  digitalWrite( cs_pin, LOW);

  //clear trail back
  switch (movementBack)
  {
  case 1:
    needleClear1.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 2:
    needleClear2.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 3:
    needleClear3.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 4:
    needleClear4.pushRotated( angleBack, COLOR_TRANSP);
    break;
 
  default:
    break;
  }
  needleExtra.pushRotated(angleBack, COLOR_TRANSP);
  angle = angleBack + movementBack;

  needle.pushRotated( angle, COLOR_TRANSP);       //nothing transparant

  //clear trail front
  switch (MovementFront)
  {
  case 1:
    needleClear1.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 2:
    needleClear2.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 3:
    needleClear3.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 4:
    needleClear4.pushRotated( angleFront, COLOR_TRANSP);
    break;
 
  default:
    break;
  }
  needleExtra.pushRotated(angleFront, COLOR_TRANSP);
  angle = angleFront + MovementFront;

  needle.pushRotated( angle, COLOR_BACKGROUND);       //background transparant
  // Pull cs_pin low to end write to screen
  digitalWrite( cs_pin, HIGH);
}

void plotTest(int16_t angle, uint8_t cs_pin){
  digitalWrite( cs_pin, LOW);
  needleExtra.pushRotated( angle, TFT_TRANSPARENT);
  delay(1000);
  needleClear4.pushRotated( angle, TFT_TRANSPARENT);
  digitalWrite( cs_pin, HIGH);
  delay(1000);
}

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  Serial.begin(115200); // Debug only
  Serial.println("Setup begonnen");
  tft.begin();
  tft.setRotation(3);       // 0 1 2 3 : rotate 90°
  tft.fillScreen(COLOR_TEST);

  // Define where the needle pivot point is on the TFT before
  // creating the needle so boundary calculation is correct
  tft.setPivot(DIAL_CENTRE, DIAL_CENTRE);

  // Create the needle Sprite
  createNeedle();
  createAxis();
  createClear1();
  createClear2();
  createClear3();
  createClear4();
  createExtra();

  // Reset needle position to 0
  for (int i = 0; i <= 5; i++ ) {
    pinMode( tft_cs[i], OUTPUT);   // Chip Select is active low.
    
    digitalWrite( tft_cs[i], LOW);
    needleAxis.pushRotated( 90, COLOR_TRANSP);
    digitalWrite( tft_cs[i], HIGH);

    angleBack[i]  = random(359); // random speed in range 0 to 360
    angleFront[i] = random(359); // random speed in range 0 to 360
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
//    plotTest(0, tft_cs[i]);
//  plotTest(90, tft_cs[i]);
    plotNeedle(angleBack[i], 3, angleBack[i], 3, tft_cs[i]);
    angleBack[i] = angleBack[i] + 4;
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

    myTime = millis();
    cnt = 0;
  }

}
