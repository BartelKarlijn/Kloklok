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
  uint16_t rot0_eeprom = pref_eeprom.getUInt("rot0_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot0 = ");
  Serial.println(rot0_eeprom);
  uint16_t rot1_eeprom = pref_eeprom.getUInt("rot1_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot1 = ");
  Serial.println(rot1_eeprom);
  uint16_t rot2_eeprom = pref_eeprom.getUInt("rot2_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot2 = ");
  Serial.println(rot2_eeprom);
  uint16_t rot3_eeprom = pref_eeprom.getUInt("rot3_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot3 = ");
  Serial.println(rot3_eeprom);
  uint16_t rot4_eeprom = pref_eeprom.getUInt("rot4_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot4 = ");
  Serial.println(rot4_eeprom);
  uint16_t rot5_eeprom = pref_eeprom.getUInt("rot5_eeprom", 0);
  Serial.print("Uit eprom uitgelezen waarde voor rot5 = ");
  Serial.println(rot5_eeprom);
  bool flag_read = pref_eeprom.getBool("flag_read", false);
  if (flag_read) {
    mode = mode_eeprom;
    namePtr = namePtr_eeprom;
    clockRotation[0] = rot0_eeprom;
    clockRotation[1] = rot1_eeprom;
    clockRotation[2] = rot2_eeprom;
    clockRotation[3] = rot3_eeprom;
    clockRotation[4] = rot4_eeprom;
    clockRotation[5] = rot5_eeprom;
  }
}

void save_ConfigToEeprom () {
  pref_eeprom.putUInt("mode_eeprom", mode);
  pref_eeprom.putUInt("namePtr_eeprom", namePtr);
  pref_eeprom.putUInt("rot0_eeprom", clockRotation[0]);
  pref_eeprom.putUInt("rot1_eeprom", clockRotation[1]);
  pref_eeprom.putUInt("rot2_eeprom", clockRotation[2]);
  pref_eeprom.putUInt("rot3_eeprom", clockRotation[3]);
  pref_eeprom.putUInt("rot4_eeprom", clockRotation[4]);
  pref_eeprom.putUInt("rot5_eeprom", clockRotation[5]);
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