void modeDigitShowSetup(){
  currentNr = 0;  
  startWifi();
  clearScreens(COLOR_TEST, false);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  distributeCommand(COMMAND_SHOWDG, currentNr, currentNr, currentNr);  // Showing 0 on all screens
  showDigit(currentNr, true);
  Println("Showing test color with 0");
  delay(waitDelay * 1000 + 150);
  Println("Now in mode DigitShow");
  delay(100);
}

