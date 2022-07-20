int16_t calculateRotation(int16_t angleFrom, int16_t angleTo) {
    int16_t rotation = angleFrom - angleTo;
    if (rotation < 0)
    {
        rotation = 360 + rotation;
    }
    return rotation;
}

void calculateMovement(int nr_from, int nr_to) {
    // This shoudl update the even and uneven movement variables for Front and back
    // The idea is to rotate from one position (per 90deg + 225deg) to any other
    int16_t rotationBack2Back, rotationBack2Front, rotationFront2Back, rotationFront2Front;
    int16_t angleto1, angleto2, angleBackTo, angleFrontTo, angleBackFrom, angleFrontFrom;
    int8_t rotation90framesBack, rotation90framesFront;
    int8_t rotationBackEven, rotationBackUneven, rotationFrontEven, rotationFrontUneven;

    for (int i = 0; i <= 5; i++) {
        // calculate rotation angles
        angleBackFrom  = digit[nr_from, i]->angleBack;
        angleFrontFrom = digit[nr_from, i]->angleFront;
        angleBackTo    = digit[nr_to, i]->angleBack;
        angleFrontTo   = digit[nr_to, i]->angleFront;

        // option1
        rotationBack2Back   = calculateRotation(angleBackTo  , angleBackFrom);
        rotationFront2Front = calculateRotation(angleFrontTo , angleFrontFrom);
        // option2
        rotationBack2Front  = calculateRotation(angleFrontTo , angleBackFrom);
        rotationFront2Back  = calculateRotation(angleBackTo  , angleFrontFrom);


        switch (movementMode)
        {
        case MOVEMENTMODEMIN:
            // find the min movement as one with a difference of 0
            if ((rotationBack2Back = 0) or (rotationFront2Front = 0))
            {
                // min movement found
                angleto1 = angleBackTo;
                angleto2 = angleFrontTo;
            }
            else
            {
                angleto1 = angleFrontTo;
                angleto2 = angleBackTo;
            }
            break;
        case MOVEMENTMODEMAX:
            // Similar to Min mode, but we add 360 to one of the 0 steps
            if (rotationBack2Back = 0)
            {
                // Add 360 to movement found
                angleto1 = angleBackTo + 360;
                angleto2 = angleFrontTo;
            }
            else if (rotationBack2Back = 0)
            {
                // Add 360 to movement found
                angleto1 = angleBackTo;
                angleto2 = angleFrontTo + 360;
            }
            else
            {
                angleto1 = angleFrontTo;
                angleto2 = angleBackTo;
            }
            break;
        case MOVEMENTMODEFUN:
            // Both dials should be moving
            if ((rotationBack2Front != 0) and (rotationFront2Back != 0))
            {
                // non 0 movement found
                angleto1 = angleFrontTo;
                angleto2 = angleBackTo;
            }
            else if (rotationBack2Back = 0)
            {
                angleto1 = angleBackTo + 360;
                angleto2 = angleFrontTo;
            }
            else if (rotationFront2Front = 0)
            {
                angleto1 = angleBackTo;
                angleto2 = angleFrontTo + 360;
            }
            else
            {
                angleto1 = angleBackTo;
                angleto2 = angleFrontTo;
            }
        default:
            break;
        }

        // Calculate rotation angles per frame
        rotation90framesBack = angleto1 - angleBackFrom;
        rotation90framesFront = angleto2 - angleFrontFrom;

        moveEvenBack[i]  = rotation90framesBack / 90;            // rounded down as we calculate with integers
        moveUnEvBack[i]  = (rotation90framesBack + 45) / 90;   // rounded up
        moveEvenFront[i] = rotation90framesFront / 90;          // rounded down as we calculate with integers
        moveUnEvFront[i] = (rotation90framesFront + 45) / 90; // rounded up
    }
}