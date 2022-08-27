void readSerial(){
  String cmdString1, cmdString4;
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
    if (incomingMessage != "" ) {
      //check if valid command
      cmdString1 = incomingMessage[0];
      cmdString4 = incomingMessage[4];
    }
    if (  (cmdString1 == String(CMD_START) )
      and (cmdString4 == String(CMD_STOP ) ) ){
      // only process valid commands
      messageChanged = true;
      serialMessage = incomingMessage.substring(1, 4);
    }
    incomingMessage = "";
  }
}
