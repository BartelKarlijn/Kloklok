void modeDigitShowSetup(){
  clearScreens(COLOR_TEST);
  Println("TestColor showed");
  delay(500);
}

void modeDigitShowLoop(){
  for (int nr = 0; nr <=9; nr++){
    clearScreens(COLOR_BACKGROUND);
    needleAxis.pushRotated(90, COLOR_TRANSP);
    showDigit(nr);
    Print("Showing nr ");
    Println(String(nr));
    delay(2000);
  }
}
