void modeDigitDanceSetup(){
  startWifi();
  clearScreens(COLOR_TEST, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  Println("Now in mode DigitDance");
  delay(100);
}
