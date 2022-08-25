float buttonChangeStep(float var_Change, String Change_Oms) {
  var_Change = var_Change * 10;
  if (var_Change > 100.0 ) {var_Change = 1; }
  Print("Changing ");
  Print(Change_Oms);
  Print(", new value ");
  Println(var_Change);
  return var_Change;
}

uint8_t  buttonChangeUp(uint16_t var, int16_t varChange, String Change_Oms, uint16_t varMax) {
  int32_t varTmp;
  varTmp = var + varChange;
  if (varTmp < 0) {varTmp = varMax -1;}
  if (varTmp >= varMax) {varTmp = 0;}
  var = varTmp;
  Print("Changing ");
  Print(Change_Oms);
  Print(", new value ");
  Println(var);
  return var;
}

void buttonChangeConfig() {
  save_ConfigToEeprom ();  
  Println("Paramters stored to eeprom");
}

void buttonChangeRestart() {
//  digitalWrite(ledpin, LOW);
  Println("Restarting ESP");
  delay(100);
  ESP.restart();
}
