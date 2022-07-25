void modeSlaveSetup(){
  startWifi();   // Moet eigenlijk stop zijn
  clearScreens(COLOR_TEST, true);
  Println("Now in mode Slave");
  delay(100);
}
