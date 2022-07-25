void modeClockDemoSetup(){
  startWifi();
  clearScreens(COLOR_BACKGROUND, true);
  currentNr = 0;
  Println("Showing test color with 0");
  Println("Give slaves time to catch up");
  delay(5000);
  distributeCommand(COMMAND_CLEARS, 1, 1, 1);  // clear screens reploting axis
  delay(1000);
  distributeCommand(COMMAND_SHOWDG, currentNr, currentNr, currentNr);  // Showing 0 on all screens
  showDigit(currentNr);
  delay(2000);
  Println("Now in mode ClockDemo");
  delay(100);  
}
