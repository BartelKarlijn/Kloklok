void modeClockDemoSetup(){
  currentNr = 0;
  startWifi();
  clearScreens(COLOR_BACKGROUND, true);
  Println("Give slaves time to catch up");
  delay(5000);
  distributeCommand(COMMAND_CLEARS, 1, 1, 1);  // clear screens reploting axis
  delay(1000);
  distributeCommand(COMMAND_SHOWDG, currentNr, currentNr, currentNr);  // Showing 0 on all screens
  showDigit(currentNr);
  Println("Showing test color with 0");
  delay(2000);
  Println("Now in mode ClockDemo");
  delay(100);  
}
