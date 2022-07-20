void modeDigitShowSetup(){
  clearScreens(COLOR_TEST);
  delay(500);
  
}

void modeDigitShowLoop(){
  for (int nr = 0; nr <=9; nr++){
    clearScreens(COLOR_BACKGROUND);
    showDigit(nr);
    delay(5000);
  }
}
