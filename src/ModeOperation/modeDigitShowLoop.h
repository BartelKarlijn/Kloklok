void modeDigitShowLoop(){
  checkStillSameMode ();

  time_X000 = (time_X000 + 1) % 10;
  time_0X00 = (time_X000 + 1) % 10;
  time_00X0 = (time_0X00 + 1) % 10;
  time_000X = (time_00X0 + 1) % 10;

  distributeCommand(COMMAND_SHOWDG, time_0X00, time_00X0, time_000X);
  showDigit(time_X000, true);

  delay(waitDelay * 1000 + 150);
  Print("Showing nr: ");
  Println(time_X000);
}
