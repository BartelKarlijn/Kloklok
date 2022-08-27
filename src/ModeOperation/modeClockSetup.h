void modeClockSetup(){
  startWifi();
  clearScreens(COLOR_TEST, true);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  time_X000 = 0;
  distributeCommand(COMMAND_SHOWDG, time_X000, time_X000, time_X000);  // Showing 0 on all screens
  showDigit(time_X000, true);
  Println("Showing test color with 0");

  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Println("Now in mode Clock");
  delay(waitDelay * 1000 + 150);
}
