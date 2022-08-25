void readSerial(){
  //Serial message
  if (Serial.available() > 0) {
    // read the incoming string:
    serialMessage = Serial.readStringUntil(CMD_START);  // forget start CMD_START
    serialMessage = Serial.readStringUntil(CMD_STOP);   // doesn't include CMD_STOP
    if (serialMessage.length() == 3 ) {
      messageChanged = true;        // only processing valid commands
    }
  }

  //Webserial
  if (flagWifiOn) {
    WebSerial.msgCallback(recvMsg);
    if (     (incomingMessage.charAt(0) == CMD_START )
         and (incomingMessage.charAt(4) == CMD_STOP  ) ){
      // only process valid commands
      messageChanged = true;
      serialMessage = incomingMessage;
      incomingMessage = "";
    }
  }
}
