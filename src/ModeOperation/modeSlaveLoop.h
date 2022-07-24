void modeSlaveLoop(){
  checkStillSameMode ();
  readSerial();
  if (messageChanged) {
    Print("Message= ");
    Println(serialMessage);
  }
  processMessage();
  delay(1000);
}
