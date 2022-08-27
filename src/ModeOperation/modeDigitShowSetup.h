void modeDigitShowSetup(){
  time_X000 = OPERATION_DIGITSHOW;  
  startWifi();
  clearScreens(COLOR_TEST, false);
  Print("Give slaves time to catch up");
  delay(DELAY_CATCHUP);
  distributeCommand(COMMAND_SHOWDG, time_X000, time_X000, time_X000);  // Showing 0 on all screens
  showDigit(time_X000, true);
  Println("Showing test color with 0");
  delay(waitDelay * 1000 + 150);
  Println("Now in mode DigitShow");
  delay(100);
}

