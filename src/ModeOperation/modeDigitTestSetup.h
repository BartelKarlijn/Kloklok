void modeDigitTestSetup(){
  startWifi();
  clearScreens(COLOR_TEST, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  Println("Now in mode DigitTest");
  delay(100);
}
