void plotNeedle(int16_t angleBack, int16_t movementBack, int16_t angleFront, int16_t MovementFront, uint16_t kloknr) {
  uint16_t rotationOffset = rotationTbl[clockRotation[kloknr]];
  // Pull cs_pin low to write to screen
  digitalWrite( tft_cs[kloknr], LOW);

  //clear trail back
  switch (movementBack)
  {
  case 0:
    needle1.pushRotated( angleBack + rotationOffset, COLOR_TRANSP);
    break;
  case 1:
    needle1.pushRotated( angleBack + rotationOffset, COLOR_TRANSP);
    break;
  case 2:
    needle2.pushRotated( angleBack + rotationOffset, COLOR_TRANSP);
    break;
  case 3:
    needle3.pushRotated( angleBack + rotationOffset, COLOR_TRANSP);
    break;
  case 4:
    needle4.pushRotated( angleBack + rotationOffset, COLOR_TRANSP);
    break;
 
  default:
    Print("Impossible movementBack value");
    break;
  }

  //clear trail front
  switch (MovementFront)
  {
  case 0:
    needle1.pushRotated( angleFront + rotationOffset, COLOR_TRANSP);
    break;
  case 1:
    needle1.pushRotated( angleFront + rotationOffset, COLOR_TRANSP);
    break;
  case 2:
    needle2.pushRotated( angleFront + rotationOffset, COLOR_TRANSP);
    break;
  case 3:
    needle3.pushRotated( angleFront + rotationOffset, COLOR_TRANSP);
    break;
  case 4:
    needle4.pushRotated( angleFront + rotationOffset, COLOR_TRANSP);
    break;
 
  default:
    Print("Impossible movementFront value");
    break;
  }

  // Pull cs_pin low to end write to screen
  digitalWrite( tft_cs[kloknr], HIGH);
}