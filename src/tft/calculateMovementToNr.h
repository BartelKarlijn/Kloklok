int16_t calculateRotation(int16_t angleFrom, int16_t angleTo) {
    int16_t rotation = (angleTo - angleFrom + 720) % 360;   // have angle 0-359
    return rotation;
}

void mapAngles(bool flag_B2B, int16_t valExtraBack, int16_t valExtraFront){
    if (flag_B2B) {
        angleto1   = angleBTo;
        angleto2   = angleFTo;
    } else {
        angleto1   = angleFTo;
        angleto2   = angleBTo;
    }
    extraBack  = valExtraBack;
    extraFront = valExtraFront;
}

void calculateMovementToNr(uint8_t nr_to) {
    // This shoudl update the even and uneven movement variables for Front and back
    // The idea is to rotate from one position (per 90deg + 225deg) to any other
    int16_t rotB2B,  rotB2F,  rotF2B,  rotF2F;
    int16_t rot90framesBack, rot90framesFront;
    int16_t rotBEven,  rotBUneven,  rotFEven,  rotFUneven;


    for (int i = 0; i <= 5; i++) {
        // calculate rotation angles
        angleBFr = angleBack[i];
        angleFFr = angleFront[i];
        angleBTo = digit[nr_to][i].angleBack;
        angleFTo = digit[nr_to][i].angleFront;

        // option1
         rotB2B = calculateRotation(angleBFr, angleBTo);
         rotF2F = calculateRotation(angleFFr , angleFTo);
        // option2
         rotB2F  = calculateRotation(angleBFr, angleFTo);
         rotF2B  = calculateRotation(angleFFr, angleBTo);

        switch (movementMode) {
        case MOVEMENT_MIN:  // find the min movement as one with a difference of 0
            if (( rotB2B == 0) or ( rotF2F == 0)) {
                mapAngles(true, 0, 0);  // min movement found
            }
            else {
                mapAngles(false, 0, 0);
            }
            break;
        case MOVEMENT_MAX: // Similar to Min mode, but we add 360 to one of the 0 steps
            if ( rotB2B == 0) {
                mapAngles(true, 360, 0);    // Add 360 to movement found
            }
            else if ( rotF2F == 0) {
                mapAngles(true, 0, 360);    // Add 360 to movement found
            }
            else {
                mapAngles(false, 0, 360);
            }
            break;
        case MOVEMENT_FUN: // Both dials should be moving
            if (( rotB2F != 0) and ( rotF2B != 0)) {
                mapAngles(false, 0, 0);    // non 0 movement found
            }
            else if ( rotB2B == 0)  {
                mapAngles(true, 360, 0);
            }
            else if ( rotF2F == 0) {
                mapAngles(true, 0, 360);
            }
            else {
                mapAngles(true, 0, 0);
            }
            break;
        default:
            Println("Impossible movementMode");
            break;
        }

        // Calculate rotation angles per frame
        rot90framesBack = calculateRotation(angleBFr, angleto1) + extraBack;
        rot90framesFront = calculateRotation(angleFFr, angleto2) + extraFront;

        moveEvenBack[i]  = rot90framesBack / 90;            // rounded down as we calculate with integers
        moveUnEvBack[i]  = (rot90framesBack + 45) / 90;   // rounded up
        moveEvenFront[i] = rot90framesFront / 90;          // rounded down as we calculate with integers
        moveUnEvFront[i] = (rot90framesFront + 45) / 90; // rounded up
    }
}