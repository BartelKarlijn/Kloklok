void modeSlaveLoop(){
  String incomingString;
  checkStillSameMode ();
  
  if (Serial.available() > 0) {
    // read the incoming string:
    incomingString = Serial.readString();

    // prints the received data
    Print("I received via Serial: ");
    Println(incomingString);
  }
 WebSerial.msgCallback(recvMsg);
 if (serialMessage != "" ) {
   Print("I received via WebSerial: ");
   Println(serialMessage);
 }
}
