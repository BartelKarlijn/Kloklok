void plotNeedle(int16_t angleBack, int16_t movementBack, int16_t angleFront, int16_t MovementFront, uint8_t cs_pin) {
  // Pull cs_pin low to write to screen
  digitalWrite( cs_pin, LOW);

  //clear trail back
  switch (movementBack)
  {
  case 1:
    needle1.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 2:
    needle2.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 3:
    needle3.pushRotated( angleBack, COLOR_TRANSP);
    break;
  case 4:
    needle4.pushRotated( angleBack, COLOR_TRANSP);
    break;
 
  default:
    break;
  }

  //clear trail front
  switch (MovementFront)
  {
  case 1:
    needle1.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 2:
    needle2.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 3:
    needle3.pushRotated( angleFront, COLOR_TRANSP);
    break;
  case 4:
    needle4.pushRotated( angleFront, COLOR_TRANSP);
    break;
 
  default:
    break;
  }

  // Pull cs_pin low to end write to screen
  digitalWrite( cs_pin, HIGH);
}