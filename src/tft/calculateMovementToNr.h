int16_t calculateRotation(int16_t angleFrom, int16_t angleTo) {
    int16_t rotation = (angleTo - angleFrom + 720) % 360; 
    return rotation;
}

void calculateMovementToNr(uint8_t nr_to) {
    // This shoudl update the even and uneven movement variables for Front and back
    // The idea is to rotate from one position (per 90deg + 225deg) to any other
    int16_t rotB2B,  rotB2F,  rotF2B,  rotF2F;
    int16_t angleto1, angleto2, angleBTo, angleFTo, angleBFr, angleFFr;
    int16_t rot90framesBack, rot90framesFront;
    int16_t rotBEven,  rotBUneven,  rotFEven,  rotFUneven;
    int16_t extraBack, extraFront; 

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

if(i == 0) {
Print("RotB2B ");
Println(String(rotB2B));
Print("RotF2F ");
Println(String(rotF2F));
Print("RotB2F ");
Println(String(rotB2F));
Print("RotF2B ");
Println(String(rotF2B));
}

        switch (movementMode) {
        case MOVEMENTMODEMIN:  // find the min movement as one with a difference of 0
            if (( rotB2B == 0) or ( rotF2F == 0)) {
                // min movement found
                angleto1   = angleBTo;
                angleto2   = angleFTo;
                extraBack  = 0;
                extraFront = 0;
if(i == 0) { Println("case 1");}
            }
            else {
                angleto1   = angleFTo;
                angleto2   = angleBTo;
                extraBack  = 0;
                extraFront = 0;
if(i == 0) {Println("case 2");}
            }
            break;
        case MOVEMENTMODEMAX: // Similar to Min mode, but we add 360 to one of the 0 steps
            if ( rotB2B == 0) {
                // Add 360 to movement found
                angleto1   = angleBTo;
                angleto2   = angleFTo;
                extraBack  = 360;
                extraFront = 0;
if(i == 0) {Println("case 3");}
            }
            else if ( rotF2F == 0) {
                // Add 360 to movement found
                angleto1   = angleBTo;
                angleto2   = angleFTo;
                extraBack  = 0;
                extraFront = 360;
if(i == 0) {Println("case 4");}
            }
            else {
                angleto1   = angleFTo;
                angleto2   = angleBTo;
                extraBack  = 0;
                extraFront = 0;
if(i == 0) {Println("case 5");}
            }
            break;
        case MOVEMENTMODEFUN: // Both dials should be moving
            if (( rotB2F != 0) and ( rotF2B != 0)) {
                // non 0 movement found
                angleto1   = angleFTo;
                angleto2   = angleBTo;
                extraBack  = 0;
                extraFront = 0;
if(i == 0) {Println("case 6");}
            }
            else if ( rotB2B == 0)  {
                angleto1   = angleBTo;
                angleto2   = angleFTo;
                extraBack  = 360;
                extraFront = 0;
if(i == 0) {Println("case 7");}
            }
            else if ( rotF2F == 0) {
                angleto1   = angleBTo;
                angleto2   = angleFTo;
                extraBack  = 0;
                extraFront = 360;

if(i == 0) {Println("case 8");}
            }
            else {
                angleto1   = angleBTo;
                angleto2   = angleFTo;
                extraBack  = 0;
                extraFront = 0;
if(i == 0) {Println("case 9");}
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