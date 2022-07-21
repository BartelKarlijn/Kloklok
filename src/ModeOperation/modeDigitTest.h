void modeDigitTestSetup(){
  clearScreens(COLOR_TEST, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  delay(2000);
}

void modeDigitTestLoop(){
    uint8_t nextNr = currentNr + 1;
    if (nextNr >= 2) {nextNr = 0;}
    Print("CurrentNr is ");
    Print(String(currentNr));
    Print("  Next is ");
    Println(String(nextNr));

    calculateMovementToNr(nextNr);
    moveNextDigit();
    currentNr = nextNr;

    delay(5000);
    clearScreens(COLOR_BACKGROUND, true);
}
