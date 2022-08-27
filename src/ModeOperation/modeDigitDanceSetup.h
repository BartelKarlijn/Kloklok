void modeDigitDanceSetup(){
  time_X000 = OPERATION_DIGITDANCE;
  startWifi();
  clearScreens(COLOR_TEST, true);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  distributeCommand(COMMAND_SHOWDG, time_X000, time_X000, time_X000);  // Showing 0 on all screens
  showDigit(time_X000, true);
  Println("Showing test color with 0");
  delay(waitDelay * 1000 + 150);
  Println("Now in mode DigitDance");
  delay(100);
}
