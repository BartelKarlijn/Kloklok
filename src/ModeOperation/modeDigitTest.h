void modeDigitTestSetup(){
  clearScreens(COLOR_TEST, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  delay(500);
}

void modeDigitTestLoop(){
    uint16_t nextNr = currentNr + 1;
    if (nextNr > 9) {nextNr = 0;}
    showDigit(currentNr);
    Println("Showing digit currentNr");
    delay(10);

    calculateMovementToNr(nextNr);

    moveNextDigit();
    Println("Dance finished");
    currentNr = nextNr;

    delay(2000);
}
