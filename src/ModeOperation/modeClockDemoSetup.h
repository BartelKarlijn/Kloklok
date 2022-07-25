void modeClockDemoSetup(){
  startWifi();
  clearScreens(COLOR_BACKGROUND, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  Println("Give slaves time to catch up");
  delay(5000);
  distributeCommand(COMMAND_SHOWDG);
  delay("1000");
  Println("Now in mode ClockDemo");
  delay(100);  
}
