void readSerial(){
  if (Serial.available() > 0) {
    // read the incoming string:
    serialMessage = Serial.readString();
    messageChanged = true;
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
