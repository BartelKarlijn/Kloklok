void modeDigitShowLoop(){
  checkStillSameMode ();
  for (int nr = 0; nr <=9; nr++){
    clearScreens(COLOR_BACKGROUND, true);
    showDigit(nr);
    Print("Showing nr ");
    Println(String(nr));
    delay(waitDelay);
  }
}
