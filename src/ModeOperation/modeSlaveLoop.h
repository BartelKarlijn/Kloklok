void modeSlaveLoop(){
  String incomingString;
  checkStillSameMode ();
  
  if (Serial.available() > 0) {
    // read the incoming string:
    incomingString = Serial.readString();

    // prints the received data
    Print("I received: ");
    Println(incomingString);
  }
}
