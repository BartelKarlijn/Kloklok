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
#define NEEDLE_LENGTH DIAL_CENTRE - NEEDLE_RADIUS // Visible length without rounded corners
#define DIAL_WIDTH    DIAL_CENTRE * 2

#define COLOR_BITS_PER_PIXEL 16
#define COLOR_BACKGROUND TFT_BLUE
#define COLOR_NEEDLE     TFT_YELLOW
#define COLOR_TRANSP     TFT_PINK


#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite needleFront = TFT_eSprite(&tft); // Sprite object for needle
TFT_eSprite needleBack  = TFT_eSprite(&tft); // Sprite object for needle

//uint16_t* tft_buffer;
//bool      buffer_loaded = false;
//uint16_t  spr_width = 0;
//uint16_t  bg_color =0;

// Angles
int16_t angleBack;  // random speed in range 0 to 360
int16_t angleFront; // random speed in range 0 to 360

// timing
unsigned long myTime;
int cnt;


// =======================================================================================
// Create the needle Sprite
// =======================================================================================
void createNeedleBack(void)
{
  needleBack.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleBack.createSprite(DIAL_WIDTH , DIAL_WIDTH );  // create the needle Sprite

  needleBack.fillSprite(COLOR_BACKGROUND); // Fill with black

  // Define needle pivot point relative to top left corner of Sprite
  needleBack.setPivot(DIAL_CENTRE, DIAL_CENTRE);     // Set pivot point in this Sprite

  // Draw the red needle in the Sprite
  needleBack.fillRect(DIAL_CENTRE - NEEDLE_RADIUS, DIAL_CENTRE, NEEDLE_WIDTH, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleBack.fillCircle( DIAL_CENTRE, DIAL_WIDTH - NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE);

  // Bounding box parameters to be populated
  //int16_t min_x;
  //int16_t min_y;
  //int16_t max_x;
  //int16_t max_y;

  // Work out the worst case area that must be grabbed from the TFT,
  // this is at a 45 degree rotation
  //needleBack.getRotatedBounds(45, &min_x, &min_y, &max_x, &max_y);

  // Calculate the size and allocate the buffer for the grabbed TFT area
  // tft_buffer =  (uint16_t*) malloc( ((max_x - min_x) + 2) * ((max_y - min_y) + 2) * 2 );
}

void createNeedleFront(void)
{
  needleFront.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleFront.createSprite(NEEDLE_WIDTH, NEEDLE_LENGTH + NEEDLE_WIDTH );  // create the needle Sprite

  needleFront.fillSprite(COLOR_TRANSP); // Fill with black

  // Define needle pivot point relative to top left corner of Sprite
  needleFront.setPivot(NEEDLE_RADIUS, NEEDLE_RADIUS);     // Set pivot point in this Sprite

  // Draw the red needle in the Sprite
  needleFront.fillRect(0, NEEDLE_RADIUS, NEEDLE_WIDTH, NEEDLE_LENGTH, COLOR_NEEDLE);
  needleFront.fillCircle( NEEDLE_RADIUS, NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE);                //centre
  needleFront.fillCircle( NEEDLE_RADIUS, NEEDLE_LENGTH + NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE); //end


  // Bounding box parameters to be populated
//  int16_t min_x;
//  int16_t min_y;
//  int16_t max_x;
//  int16_t max_y;

  // Work out the worst case area that must be grabbed from the TFT,
  // this is at a 45 degree rotation
  //needleFront.getRotatedBounds(45, &min_x, &min_y, &max_x, &max_y);

  // Calculate the size and allocate the buffer for the grabbed TFT area
  //tft_buffer =  (uint16_t*) malloc( ((max_x - min_x) + 2) * ((max_y - min_y) + 2) * 2 );
}

void plotNeedle(int16_t angleBack, int16_t angleFront, uint8_t cs_pin) {
  // Pull cs_pin low to write to screen
  digitalWrite( cs_pin, LOW);
  // Plot needle at random angle in range 0 to 240, speed 40ms per increment
  needleBack.pushRotated(angleBack, COLOR_TRANSP);  //Pink because black is default backgroundcolor
  needleFront.pushRotated(angleFront, COLOR_TRANSP);
  // Pull cs_pin low to end write to screen
  //delay(1000);
  digitalWrite( cs_pin, HIGH);
}

// =======================================================================================
// Move the needle to a new position
// =======================================================================================
/*void plotNeedle(int16_t angle, uint16_t ms_delay)
{
  static int16_t old_angle = -120; // Starts at -120 degrees

  // Bounding box parameters
  static int16_t min_x;
  static int16_t min_y;
  static int16_t max_x;
  static int16_t max_y;

  if (angle < 0) angle = 0; // Limit angle to emulate needle end stops
  if (angle > 240) angle = 240;

  angle -= 120; // Starts at -120 degrees

  // Move the needle until new angle reached
  while (angle != old_angle || !buffer_loaded) {

    if (old_angle < angle) old_angle++;
    else old_angle--;

    // Only plot needle at even values to improve plotting performance
    if ( (old_angle & 1) == 0)
    {
      if (buffer_loaded) {
        // Paste back the original needle free image area
        tft.pushRect(min_x, min_y, 1 + max_x - min_x, 1 + max_y - min_y, tft_buffer);
      }

      if ( needle.getRotatedBounds(old_angle, &min_x, &min_y, &max_x, &max_y) )
      {
        // Grab a copy of the area before needle is drawn
        tft.readRect(min_x, min_y, 1 + max_x - min_x, 1 + max_y - min_y, tft_buffer);
        buffer_loaded = true;
      }

      // Draw the needle in the new position, black in needle image is transparent
      needle.pushRotated(old_angle, TFT_BLACK);

      // Wait before next update
      delay(ms_delay);
    }

    // Slow needle down slightly as it approaches the new position
    if (abs(old_angle - angle) < 10) ms_delay += ms_delay / 5;
  }
}
*/


// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  Serial.begin(115200); // Debug only
  Serial.println("Setup begonnen");

  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  // Define where the needle pivot point is on the TFT before
  // creating the needle so boundary calculation is correct
  tft.setPivot(DIAL_CENTRE, DIAL_CENTRE);

  // Create the needle Sprite
  createNeedleBack();
  createNeedleFront();

  angleBack  = random(359); // random speed in range 0 to 360
  angleFront = random(359); // random speed in range 0 to 360

  // Reset needle position to 0
  for (int i = 0; i <= 5; i++ ) {
    pinMode( tft_cs[0], OUTPUT);
    // Chip Select is active low.  So HIGH switches screen off
    plotNeedle(0, 30 + 15 * i,  tft_cs[0]);
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
    plotNeedle(angleBack - 15 * i, angleFront + 15 * i,  tft_cs[i]);
  }

  // Pause at new position
  //delay(1000);

  // timing
  cnt++;
  //Serial.println(cnt);
  if ( cnt >= 20 ) {
    myTimeRef = millis() - myTime;
    Serial.print(cnt);
    Serial.print(" screens in ");
    Serial.print(myTimeRef);
    Serial.println(" ms:");
    myTime = millis();
    cnt = 0;
    angleBack  = random(359); // random speed in range 0 to 360
    angleFront = random(359); // random speed in range 0 to 360
  }
  else {
    angleBack  = angleBack + 14;
    angleFront = angleFront - 14;
  }

}
