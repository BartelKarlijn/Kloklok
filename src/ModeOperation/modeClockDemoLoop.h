void modeClockDemoLoop(){
  checkStillSameMode ();

  uint16_t nextNr = currentNr + 1;
  if (nextNr > 9) {nextNr = 0;}
  time_X000 = nextNr - 10;

  time_0X00 = currentNr + 2;
  if (time_0X00 > 9) {time_0X00 = time_0X00 -10;}
  
  time_00X0 = currentNr + 3;
  if (time_00X0 > 9) {time_00X0 = time_00X0 -10;}
  
  time_000X = currentNr + 4;
  if (time_000X > 9) {time_000X = time_000X -10;}
  
  distributeCommand(COMMAND_MOVETO, time_0X00, time_00X0, time_000X);
  calculateMovementToNr(nextNr);
  moveNextDigit();
  currentNr = nextNr;
  showDigit(currentNr);

  delay(3000);

}
