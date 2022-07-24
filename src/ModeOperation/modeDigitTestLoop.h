void modeDigitTestLoop(){
  checkStillSameMode ();
  uint16_t nextNr = currentNr + 1;
  if (nextNr > 9) {nextNr = 0;}
    showDigit(currentNr);
    Print("Showing digit ");
    Println(String(currentNr));
    delay(10);

    calculateMovementToNr(nextNr);

    moveNextDigit();
    Println("Dance finished");
    currentNr = nextNr;

    delay(2000);
}
