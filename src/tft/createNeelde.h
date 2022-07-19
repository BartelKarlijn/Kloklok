// =======================================================================================
// Create the needle Sprites
// We create one sprite per degree of rotation
// This is to clear pixels when rotating at eg 1/2/3/4 deg
// =======================================================================================
void createNeedle1(void) {
  needle1.setColorDepth(COLOR_BITS_PER_PIXEL);
  // Needles create at 3 oclock point
  needle1.createSprite(NEEDLE_LENGTH , NEEDLE_WIDTH + NEEDLE_CLEAR1 );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needle1.setPivot(0, NEEDLE_RADIUS + NEEDLE_CLEAR1);     // Set pivot point in this Sprite

  needle1.fillSprite(COLOR_BACKGROUND); 
  // Keep needle tip 1 pixel inside dial circle to avoid leaving stray pixels
  needle1.fillRect(0, NEEDLE_CLEAR1, NEEDLE_LENGTH - 1, NEEDLE_WIDTH + NEEDLE_CLEAR1, COLOR_NEEDLE ); 

  // Punch circle hole
  //needle1.fillCircle( NEEDLE_RADIUS, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createNeedle2(void) {
  needle2.setColorDepth(COLOR_BITS_PER_PIXEL);
  // Needles create at 3 oclock point
  needle2.createSprite(NEEDLE_LENGTH , NEEDLE_WIDTH + NEEDLE_CLEAR2 );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needle2.setPivot(0, NEEDLE_RADIUS + NEEDLE_CLEAR2);     // Set pivot point in this Sprite

  needle2.fillSprite(COLOR_BACKGROUND); 
  // Keep needle tip 1 pixel inside dial circle to avoid leaving stray pixels
  needle2.fillRect(0, NEEDLE_CLEAR2, NEEDLE_LENGTH - 1, NEEDLE_WIDTH + NEEDLE_CLEAR2, COLOR_NEEDLE ); 

  // Punch circle hole
  //needle2.fillCircle( NEEDLE_RADIUS, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createNeedle3(void) {
  needle3.setColorDepth(COLOR_BITS_PER_PIXEL);
  // Needles create at 3 oclock point
  needle3.createSprite(NEEDLE_LENGTH , NEEDLE_WIDTH + NEEDLE_CLEAR3 );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needle3.setPivot(0, NEEDLE_RADIUS + NEEDLE_CLEAR3);     // Set pivot point in this Sprite

  needle3.fillSprite(COLOR_BACKGROUND); 
  // Keep needle tip 1 pixel inside dial circle to avoid leaving stray pixels
  needle3.fillRect(0, NEEDLE_CLEAR3, NEEDLE_LENGTH - 1, NEEDLE_WIDTH + NEEDLE_CLEAR3, COLOR_NEEDLE ); 

  // Punch circle hole
  //needle3.fillCircle( NEEDLE_RADIUS, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}

void createNeedle4(void) {
  needle4.setColorDepth(COLOR_BITS_PER_PIXEL);
  // Needles create at 3 oclock point
  needle4.createSprite(NEEDLE_LENGTH , NEEDLE_WIDTH + NEEDLE_CLEAR4 );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needle4.setPivot(0, NEEDLE_RADIUS + NEEDLE_CLEAR4);     // Set pivot point in this Sprite

  needle4.fillSprite(COLOR_BACKGROUND); 
  // Keep needle tip 1 pixel inside dial circle to avoid leaving stray pixels
  needle4.fillRect(0, NEEDLE_CLEAR4, NEEDLE_LENGTH - 1, NEEDLE_WIDTH + NEEDLE_CLEAR4, COLOR_NEEDLE ); 

  // Punch circle hole
  //needle4.fillCircle( NEEDLE_RADIUS, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}
