void readSerial(){
  String incomingMessage;
  if (Serial.available() > 0) {
    // read the incoming string:
    serialMessage = Serial.readString();

    // prints the received data
    Print("received via Serial: ");
  }
  WebSerial.msgCallback(recvMsg);
  if (incomingMessage != "" ) {
    Print("received via WebSerial: ");
    serialMessage = incomingMessage;   
    incomingMessage = "";
  }
  Println(serialMessage);
}
