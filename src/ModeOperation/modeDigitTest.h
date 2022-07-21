void modeDigitTestSetup(){
  clearScreens(COLOR_TEST, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  delay(500);
}

void modeDigitTestLoop(){
    uint8_t nextNr = currentNr + 1;
    if (nextNr >= 2) {nextNr = 0;}
    Println(".");
    Print("CurrentNr is ");
    Print(String(currentNr));
    Print("  Next is ");
    Println(String(nextNr));
    clearScreens(COLOR_BACKGROUND, true);
    showDigit(currentNr);

    calculateMovementToNr(nextNr);
    moveNextDigit();
    currentNr = nextNr;

    delay(5000);
}
