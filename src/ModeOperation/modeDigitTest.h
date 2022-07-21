void modeDigitTestSetup(){
  clearScreens(COLOR_TEST, true);
  currentNr = 0;
  showDigit(currentNr);
  Println("Showing test color with 0");
  delay(2000);
}

void modeDigitTestLoop(){
    Print("CurrentNr is ");
    Println(String(currentNr));
    calculateMovement(currentNr, currentNr + 1);
    moveNextDigit();
    currentNr++;
    if (currentNr >= 1) {currentNr = 0;}
    delay(5000);
}
