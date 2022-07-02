void plotNeedle(int16_t angleBack, int16_t movementBack, int16_t angleFront, int16_t MovementFront, uint8_t cs_pin) {
  // Pull cs_pin low to write to screen
  digitalWrite( cs_pin, LOW);

  //clear trail back
  switch (movementBack)
  {
  case 1:
    needleClear1.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 2:
    needleClear2.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 3:
    needleClear3.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 4:
    needleClear4.pushRotated( angleBack, COLOR_TRANSP);
    break;
 
  default:
    break;
  }
  needle.pushRotated( angleBack, COLOR_TRANSP);       //nothing transparant

  //clear trail front
  switch (MovementFront)
  {
  case 1:
    needleClear1.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 2:
    needleClear2.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 3:
    needleClear3.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 4:
    needleClear4.pushRotated( angleFront, COLOR_TRANSP);
    break;
 
  default:
    break;
  }
  needle.pushRotated( angleFront, COLOR_BACKGROUND);       //background transparant

  // Pull cs_pin low to end write to screen
  digitalWrite( cs_pin, HIGH);
}