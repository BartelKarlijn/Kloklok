void setupSerial () {
  Serial.begin(SERIALSPEED);
  delay(100);
  Serial.println("Starting ESP32");
  Serial.print("Setup running on core: ");
  Serial.println(xPortGetCoreID());
}

void SetupFinished() {
  Serial.println("All started up correctly");
}