void readSerial(){
  if (Serial.available() > 0) {
    // read the incoming string:
    serialMessage = Serial.readStringUntil(CMD_START);  // forget start CMD_START
    serialMessage = Serial.readStringUntil(CMD_STOP);   // doesn't include CMD_STOP
    if (serialMessage.length() == 3 ) {
      messageChanged = true;        // only processing valid commands
    }
  }
  if (flagWifiOn) {
    WebSerial.msgCallback(recvMsg);
    if (incomingMessage != "" ) {
      messageChanged = true;
      serialMessage = incomingMessage;
      incomingMessage = "";
    }
  }
}
