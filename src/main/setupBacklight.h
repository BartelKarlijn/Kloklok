void setupBacklight(){
  // configure LED PWM functionalitites
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(TFT__BL , PWM_CHANNEL);
  for (int i = 0; i < BACKL_BLINK; i++) {
    ledcWrite(PWM_CHANNEL, 255);
    delay(200);
    ledcWrite(PWM_CHANNEL, 0);
    delay(200);
    }
  Serial.println("backlight heeft geknipperd");
  ledcWrite(PWM_CHANNEL, BACKLIGHT);
}