#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI


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




void plotTest(int16_t angle, uint8_t cs_pin){
  digitalWrite( cs_pin, LOW);
  delay(1000);
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
  tft.setPivot(SCREEN_CENTER, SCREEN_CENTER);

  // Create the needle Sprite
  createNeedle();
  createAxis();
  createClear1();
  createClear2();
  createClear3();
  createClear4();
  moveFront = 4;
  moveBack  = 2;

  // Reset needle position to 0
  for (int i = 0; i <= 5; i++ ) {
    pinMode( tft_cs[i], OUTPUT);   // Chip Select is active low.
    
    digitalWrite( tft_cs[i], LOW);
    needleAxis.pushRotated( 90, COLOR_TRANSP);
    digitalWrite( tft_cs[i], HIGH);

    angleBack[i]  = random(359); // random speed in range 0 to 360
    angleFront[i] = random(359); // random speed in range 0 to 360
  }

  // Backlight
  backlight = 50;
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(TFT__BL, PWMChannel);
  ledcWrite(PWMChannel, backlight);

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
    plotNeedle(angleBack[i], moveBack, angleFront[i], moveFront, tft_cs[i]);
    angleBack[i] = angleBack[i] + moveBack;
    angleFront[i] = angleFront[i] + moveFront;
  }

  // timing
  cnt++;
  //Serial.println(cnt);
  if ( cnt >= 90 ) {
    myTimeRef = millis() - myTime;
    Serial.print(cnt);
    Serial.print(" screens in ");
    Serial.print(myTimeRef);
    Serial.print(" ms = ");
    Serial.print(cnt * 1000/ myTimeRef);
    Serial.println("fps");
    tft.fillScreen(COLOR_BACKGROUND);
    moveFront++;
    backlight = backlight + 50;
    if (backlight > 250) {
      backlight = 0;
      ledcWrite(PWMChannel, backlight);
      }
    Serial.print("Backlight ");
    Serial.println(backlight);

    if (moveFront >= 5) { 
      moveFront = 1; 
      moveBack++;
      if (moveBack >= 5) { moveBack = 1;}
    }
    myTime = millis();
    cnt = 0;
  }

}
