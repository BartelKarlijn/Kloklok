void readSerial(){
  if (Serial.available() > 0) {
    // read the incoming string:
    serialMessage = Serial.readString();
    messageChanged = true;
  }
  WebSerial.msgCallback(recvMsg);
  if (incomingMessage != "" ) {
    messageChanged = true;
    serialMessage = incomingMessage;
    incomingMessage = "";
  }
}
