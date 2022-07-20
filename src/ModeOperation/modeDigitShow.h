void modeDigitShowSetup(){
  clearScreens(COLOR_TEST);
  delay(500);
  Println("TestColor showed");
}

void modeDigitShowLoop(){
  for (int nr = 0; nr <=9; nr++){
    clearScreens(COLOR_BACKGROUND);
    showDigit(nr);
    Print("Showing nr ");
    Println(String(nr));
    delay(2000);
  }
}
