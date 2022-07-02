void setupIntledStart() {
  // Onboard ledje enkele keren laten pinken.  Pas als alles OK is, dit weer uitzetten.
  pinMode(LED_PIN, OUTPUT);
  startupError = false;  
  
  digitalWrite(LED_PIN, LOW);    //ledje uitzetten, en pas aanzetten nadat alles is opgestart
  delay(200);
  for (int i = 0; i < LEDSTARTBLINK; i++)
  {
    digitalWrite(LED_PIN, HIGH); 
    delay(200);
    digitalWrite(LED_PIN, LOW); 
    delay(200);
  }
  
}

void setupIntledAllOK() {
  if ( not startupError ) {
    digitalWrite(LED_PIN, HIGH);
  }
  Serial.println("Everything started");
}