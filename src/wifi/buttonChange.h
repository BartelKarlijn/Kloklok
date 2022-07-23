float buttonChangeStep(float var_Change, String Change_Oms) {
  var_Change = var_Change * 10;
  if (var_Change > 100.0 ) {var_Change = 1; }
  Print("Changing ");
  Print(Change_Oms);
  Print(", new value ");
  Println(String(var_Change));
  return var_Change;
}

uint8_t  buttonChangeUp(uint8_t var, int8_t varChange, String Change_Oms) {
  var = var + varChange;
  Print("Changing ");
  Print(Change_Oms);
  Print(", new value ");
  Println(String(var));
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
