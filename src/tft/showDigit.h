void showDigit(int nr ){
  // Showing the digit 'nr' with the 6 screens
  // nr should be 0-9
  for (int i = 0; i <= 5; i++) {
    //Movement is 0
    plotNeedle( digit[nr, i]->angleBack, 0, digit[nr, i]->angleFront, 0, tft_cs[i]);
  }
}
