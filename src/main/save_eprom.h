// Complete project details at https://RandomNerdTutorials.com/esp32-save-data-permanently-preferences/
// Start instance of Preferences


void get_datafrom_eeprom () {
  // Open Preferences with KlokKlok namespace. Each application module, library, etc
  // has to use a namespace name to prevent key name collisions. We will open storage in
  // RW-mode (second parameter has to be false).
  // Note: Namespace name is limited to 15 chars.
  pref_eeprom.begin("KlokKlok", false);

  String ssid_eeprom = pref_eeprom.getString("ssid_eeprom","");
  String pwd_eeprom = pref_eeprom.getString("pwd_eeprom","");

  // Get the counter value, if the key does not exist, return a default value of 0
  // Note: Key name is limited to 15 chars.
  wifi_ssid = pref_eeprom.getString("ssid_eeprom","");
  Serial.print("Uit eprom uitgelezen waarde voor SSID = ");
  Serial.println(wifi_ssid);
  wifi_pwd = pref_eeprom.getString("pwd_eeprom","");
  Serial.print("Uit eprom uitgelezen waarde voor PWD = ");
  Serial.println("*****");
  uint8_t mode_eeprom = pref_eeprom.getUInt("mode_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor mode = ");
  Serial.println(mode_eeprom);
  uint8_t namePtr_eeprom = pref_eeprom.getUInt("namePtr_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor namePtr = ");
  Serial.println(namePtr_eeprom);
  uint16_t waitDelay_eeprom = pref_eeprom.getUInt("waitDel_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor waitDelay = ");
  Serial.println(waitDelay_eeprom);
  uint16_t rot_eeprom = pref_eeprom.getUInt("rot0_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot = ");
  Serial.println(rot_eeprom);
  bool flag_read = pref_eeprom.getBool("flag_read", false);
  if (flag_read) {
    mode = mode_eeprom;
    namePtr = namePtr_eeprom;
    waitDelay   = waitDelay_eeprom;
    clockRotation = rot_eeprom;
  }
}

void save_ConfigToEeprom () {
  pref_eeprom.putUInt("mode_eeprom", mode);
  pref_eeprom.putUInt("namePtr_eeprom", namePtr);
  pref_eeprom.putUInt("waitDel_eeprom", waitDelay);
  pref_eeprom.putUInt("rot0_eeprom", clockRotation);
  pref_eeprom.putBool("flag_read", true);
  
  Println("Config saved");
}

void save_WIFIdatato_eeprom () {
  pref_eeprom.putString("ssid_eeprom", wifi_ssid);
  pref_eeprom.putString("pwd_eeprom" , wifi_pwd);

  Println("Wifi data saved");

  delay(1000);
  Println("nog eens uitlezeen");
  String ssid_eeprom = pref_eeprom.getString("ssid_eeprom","");
  Print("Uit eprom uitgelezen waarde voor SSID = ");
  Println(ssid_eeprom);
  String pwd_eeprom = pref_eeprom.getString("pwd_eeprom","");
  Serial.print("Uit eprom uitgelezen waarde voor PWD = ");
  Println(pwd_eeprom);
}