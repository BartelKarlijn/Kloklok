void modeDigitShowSetup(){
  clearScreens(COLOR_TEST, false);
  Println("TestColor showed");
  delay(500);
}

void modeDigitShowLoop(){
  for (int nr = 0; nr <=9; nr++){
    clearScreens(COLOR_BACKGROUND, true);
    showDigit(nr);
    Print("Showing nr ");
    Println(String(nr));
    delay(1000);
  }
}
