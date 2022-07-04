void setupBacklight(){
  // configure LED PWM functionalitites
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(TFT__BL , PWMChannel);
  for (int i = 0; i < BACKL_BLINK; i++) {
    ledcWrite(PWMChannel, 255);
    delay(200);
    ledcWrite(PWMChannel, 0);
    delay(200);
    }
  Serial.println("backlight heeft geknipperd");
  ledcWrite(PWMChannel, BACKLIGHT);
}