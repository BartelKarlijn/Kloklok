void showDigit(int nr, bool flag_clear ){
  // Showing the digit 'nr' with the 6 screens
  // nr should be 0-9
  if (flag_clear) {
    clearScreens(COLOR_BACKGROUND, true);
  }
  for (int i = 0; i <= 5; i++) {
    //Movement is 0
    angleBack[i] = digit[nr][i].angleBack;
    angleFront[i] = digit[nr][i].angleFront;
    plotNeedle( angleBack[i], 0, angleFront[i], 0, i);
  }
}
