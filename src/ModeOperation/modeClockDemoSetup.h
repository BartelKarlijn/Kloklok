void modeClockDemoSetup(){

  startWifi();
  clearScreens(COLOR_TEST, true);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  time_X000 = OPERATION_CLOCKDEMO;
  distributeCommand(COMMAND_SHOWDG, time_X000, time_X000, time_X000);  // Showing 0 on all screens
  showDigit(time_X000, true);
  time_X000 = 0;
  time_0X00 = 0;
  time_00X0 = 0;
  time_000X = 0;
  time_hh = 0;
  time_mm = 0;
  Println("Showing operation mode Clockdemo");
  delay(waitDelay * 1000 + 150);
  Println("Now in mode ClockDemo");
  delay(100);  
}
