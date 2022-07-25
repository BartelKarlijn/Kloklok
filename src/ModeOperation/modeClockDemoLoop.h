void modeClockDemoLoop(){
  checkStillSameMode ();

  uint16_t nextNr = currentNr + 1;
  if (nextNr > 9) {nextNr = 0;}
  time_X000 = nextNr;
  time_0X00 = nextNr + 1;
  if (time_0X00 > 9) {time_0X00 = 0;}
  time_00X0 = time_0X00 + 1;
  if (time_00X0 > 9) {time_00X0 = 0;}
  time_000X = time_00X0 + 1;
  if (time_000X > 9) {time_000X = 0;}
  distributeCommand(COMMAND_MOVETO);

  calculateMovementToNr(nextNr);
  moveNextDigit();
  currentNr = nextNr;
  showDigit(currentNr);
  Print("Showing digit ");
  Println(String(currentNr));

  delay(2000);


}
