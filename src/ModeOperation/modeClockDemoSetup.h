void modeClockDemoSetup(){
  startWifi();
  clearScreens(COLOR_BACKGROUND, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  Println("Now in mode ClockDemo");
  delay(100);  
}
