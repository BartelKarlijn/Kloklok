void modeClockDemoSetup(){

  startWifi();
  clearScreens(COLOR_TEST, true);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  time_X000 = 0;
  time_0X00 = 0;
  time_00X0 = 0;
  time_000X = 0;
  time_hh = 0;
  time_mm = 0;
  distributeCommand(COMMAND_SHOWDG, time_0X00, time_00X0, time_000X);  // Showing 0 on all screens
  distributeCommand(COMMAND_SHOWDG, time_0X00, time_00X0, time_000X);  // Showing 0 on all screens
  showDigit(time_X000, true);
  Println("Showing test color with 0");
  delay(waitDelay * 1000 + 150);
  Println("Now in mode ClockDemo");
  delay(100);  
}
