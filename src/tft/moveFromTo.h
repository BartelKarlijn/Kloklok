int16_t calculateRotation(int16_t angleFrom, int16_t angleTo){
  int16_t rotation = angleFrom - angleTo;
  if (rotation < 0 ) { rotation = 360 + rotation ; }
}

void moveFromTo(int16_t angleBackFrom, int16_t angleBackTo, int16_t angleFrontFrom, int16_t angleFrontTo) {
// The idea is to rotate from one position (per 90deg + 225deg) to any other
  int16_t rotationBack2Back, rotationBack2Front, rotationFront2Back, rotationFront2Front;
  int16_t anglefrom1, angleto1, anglefrom2, angleto2;

  // calculate rotation angles
  //option1
  rotationBack2Back   = calculateRotation(angleBackFrom, angleBackTo);
  rotationFront2Front = calculateRotation(angleFrontFrom, angleFrontTo);
  //option2
  rotationBack2Front  = calculateRotation(angleBackFrom, angleFrontTo);
  rotationFront2Back  = calculateRotation(angleFrontFrom, angleBackTo);

  anglefrom1 = angleBackFrom;
  anglefrom2 = angleFrontFrom;

  switch (movementMode)
  {
  case MOVEMENTMODEMIN:
    // find the min movement as one with a difference of 0
    if ( (rotationBack2Back = 0) or (rotationFront2Front = 0) ) {
      // min movement found
      angleto1   = angleBackTo;
      angleto2   = angleFrontTo;
    }
    else {
      angleto1   = angleFrontTo;
      angleto2   = angleBackTo;
    }
    break;
  case MOVEMENTMODEMAX:
    // Similar to Min mode, but we add 360 to one of the 0 steps
    if (rotationBack2Back = 0) {
      // Add 360 to movement found
      angleto1   = angleBackTo + 360;
      angleto2   = angleFrontTo;
    }
    else if ( rotationBack2Back = 0 ) {
      // Add 360 to movement found
      angleto1   = angleBackTo;
      angleto2   = angleFrontTo + 360;
    }
    else {
      angleto1   = angleFrontTo;
      angleto2   = angleBackTo;
    }
    break;
  case MOVEMENTMODEFUN:
    // Both dials should be moving
    if ( (rotationBack2Front != 0) and (rotationFront2Back != 0) ) {
      // non 0 movement found
      angleto1   = angleFrontTo;
      angleto2   = angleBackTo;
    }
    else if (rotationBack2Back = 0 ) {
      angleto1   = angleBackTo + 360;
      angleto2   = angleFrontTo;
    }
    else if (rotationFront2Front = 0 ) {
      angleto1   = angleBackTo ;
      angleto2   = angleFrontTo + 360;
    }
    else {
      angleto1   = angleBackTo ;
      angleto2   = angleFrontTo;
    }
  default:
    break;
  }

}
