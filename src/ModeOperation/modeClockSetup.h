void modeClockSetup(){
  startWifi();
  clearScreens(COLOR_TEST, true);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  distributeCommand(COMMAND_SHOWDG, currentNr, currentNr, currentNr);  // Showing 0 on all screens
  showDigit(currentNr, true);
  Println("Showing test color with 0");

  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Println("Now in mode Clock");
  delay(waitDelay * 1000 + 150);
}
