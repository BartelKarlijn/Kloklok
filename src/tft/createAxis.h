void createAxis() {
  needleAxis.setColorDepth(COLOR_BITS_PER_PIXEL);
  needleAxis.createSprite( NEEDLE_WIDTH , NEEDLE_WIDTH );  // create the Axis Sprite

  // Define needle pivot point relative to top left corner of Sprite
  needleAxis.setPivot(NEEDLE_RADIUS, NEEDLE_RADIUS);     // Set pivot point in this Sprite

  needleAxis.fillSprite(COLOR_BACKGROUND); 

  // Draw the Axis in the Sprite
  needleAxis.fillCircle(NEEDLE_RADIUS, NEEDLE_RADIUS, NEEDLE_RADIUS, COLOR_NEEDLE);
}
