void modeClockSetup(){
  startWifi();
  clearScreens(COLOR_TEST, false);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  time_X000 = OPERATION_CLOCK;
  distributeCommand(COMMAND_SHOWDG, time_X000, time_X000, time_X000);
  showDigit(time_X000, true);
  Println("Showing test color with 0");

  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Println("Now in mode Clock");
  delay(waitDelay * 1000 + 150);
}
