// =======================================================================================
// Create the needle Sprite
// =======================================================================================
void createNeedle(void) {
  needle.setColorDepth(COLOR_BITS_PER_PIXEL);
  needle.createSprite(NEEDLE_WIDTH , NEEDLE_LENGTH );  // create the needle Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needle.setPivot(NEEDLE_RADIUS, 0);     // Set pivot point in this Sprite

  needle.fillSprite(COLOR_NEEDLE); 

  // Punch circle hole
  needle.fillCircle( NEEDLE_RADIUS, 0, NEEDLE_RADIUS, COLOR_TRANSP); //punch hole in centre
}
