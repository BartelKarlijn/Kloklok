void modeSlaveLoop(){
  checkStillSameMode ();
  readSerial();
  if (messageChanged) {
    Print("Message= ");
    Println(serialMessage);
  }
  parseMessage();
  delay(1000);
}
