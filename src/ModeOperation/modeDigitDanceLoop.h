void modeDigitDanceLoop(){
  checkStillSameMode ();

  time_X000 = (time_X000 + 1) % 10;
  time_0X00 = (time_X000 + 1) % 10;
  time_00X0 = (time_0X00 + 1) % 10;
  time_000X = (time_00X0 + 1) % 10;
  
  distributeCommand(COMMAND_MOVETO, time_0X00, time_00X0, time_000X);
  calculateMovementToNr(time_X000);
  moveNextDigit();
  showDigit(time_X000, false);

  delay(waitDelay * 1000 + 150);
}
