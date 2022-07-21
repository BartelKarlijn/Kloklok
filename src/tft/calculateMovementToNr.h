int16_t calculateRotation(int16_t angleFrom, int16_t angleTo) {
    int16_t rotation = (angleTo - angleFrom + 720) % 360; 
    return rotation;
}

void calculateMovementToNr(uint8_t nr_to) {
    // This shoudl update the even and uneven movement variables for Front and back
    // The idea is to rotate from one position (per 90deg + 225deg) to any other
    int16_t rotB2B,  rotB2F,  rotF2B,  rotF2F;
    int16_t angleto1, angleto2, angleBTo, angleFTo, angleBFr, angleFFr;
    int8_t rot90framesBack, rot90framesFront;
    int8_t  rotBEven,  rotBUneven,  rotFEven,  rotFUneven;

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
         rotF2B  = calculateRotation(angleBTo, angleFFr);
    if (i = 0 ){
    Print("angle Back: ");
    Print(String(angleBFr));
    Print(" to ");
    Print(String(angleBTo));
    Print("  angle Front: ");
    Print(String(angleFFr));
    Print(" to ");
    Println(String(angleFTo));
    delay(100);

    Print("rotB2B= ");
    Print(String(rotB2B));
    Print("  rotF2F= ");
    Print(String(rotF2F));
    Print("  rotB2F= ");
    Print(String(rotB2F));
    Print("  rotB2F= ");
    Println(String(rotB2F));
    delay(100);

    Print(" rotB = ");
    Print(String(rot90framesBack));
    Print("   rotF = ");
    Println(String(rot90framesFront));
    delay(100);
    }

        switch (movementMode) {
        case MOVEMENTMODEMIN:  // find the min movement as one with a difference of 0
            if (( rotB2B = 0) or ( rotF2F = 0)) {
                // min movement found
                angleto1 = angleBTo;
                angleto2 = angleFTo;
            }
            else {
                angleto1 = angleFTo;
                angleto2 = angleBTo;
            }
            break;
        case MOVEMENTMODEMAX: // Similar to Min mode, but we add 360 to one of the 0 steps
            if ( rotB2B = 0) {
                // Add 360 to movement found
                angleto1 = angleBTo + 360;
                angleto2 = angleFTo;
            }
            else if ( rotF2F = 0) {
                // Add 360 to movement found
                angleto1 = angleBTo;
                angleto2 = angleFTo + 360;
            }
            else {
                angleto1 = angleFTo;
                angleto2 = angleBTo;
            }
            break;
        case MOVEMENTMODEFUN: // Both dials should be moving
            if (( rotB2F != 0) and ( rotF2B != 0)) {
                // non 0 movement found
                angleto1 = angleFTo;
                angleto2 = angleBTo;
            }
            else if ( rotB2B = 0)  {
                angleto1 = angleBTo + 360;
                angleto2 = angleFTo;
            }
            else if ( rotF2F = 0) {
                angleto1 = angleBTo;
                angleto2 = angleFTo + 360;
            }
            else {
                angleto1 = angleBTo;
                angleto2 = angleFTo;
            }
            break;
        default:
            Println("Impossible movementMode");
            break;
        }

        // Calculate rotation angles per frame
        rot90framesBack = calculateRotation(angleBFr, angleto1);
        rot90framesFront = calculateRotation(angleFFr, angleto2);

        moveEvenBack[i]  = rot90framesBack / 90;            // rounded down as we calculate with integers
        moveUnEvBack[i]  = (rot90framesBack + 45) / 90;   // rounded up
        moveEvenFront[i] = rot90framesFront / 90;          // rounded down as we calculate with integers
        moveUnEvFront[i] = (rot90framesFront + 45) / 90; // rounded up

    }
    
    Print("moveEvenBack= ");
    Print(String(moveEvenBack[0]));
    Print("  moveUnEvBack= ");
    Print(String(moveUnEvBack[0]));
    Print("  moveEvenFront= ");
    Print(String(moveEvenFront[0]));
    Print("  moveUnEvFront= ");
    Print(String(moveUnEvFront[0]));
    Println(" ");
    delay(1000);
}