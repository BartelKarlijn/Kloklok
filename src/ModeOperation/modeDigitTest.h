void modeDigitTestSetup(){
  clearScreens(COLOR_TEST, true);
  delay(500);
}

void modeDigitTestLoop(){
  for (int nr = 0; nr <=9; nr++){
    showDigit(nr);
    calculateMovement(nr, nr + 1);
    moveNextDigit();
    delay(2000);
  }

}
