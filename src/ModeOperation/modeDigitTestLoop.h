void modeDigitTestLoop(){
  checkStillSameMode ();
  uint16_t nextNr = currentNr + 1;
  if (nextNr > 9) {nextNr = 0;}
  calculateMovementToNr(nextNr);

  moveNextDigit();
  currentNr = nextNr;
  showDigit(currentNr);
  Print("Showing digit ");
  Println(String(currentNr));

  delay(waitDelay * 1000 + 150);
}
