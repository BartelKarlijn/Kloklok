void modeClockLoop(){
  struct tm timeinfo;
  char timeHour[3];
  char timeMin[3];
  char timeFull[40];
  uint8_t time_X000new, time_0X00new, time_00X0new, time_000Xnew;

  checkStillSameMode ();
  if(!getLocalTime(&timeinfo)){
    Print("Failed to obtain time");
    return;
  }

  strftime(timeMin, 3, "%M", &timeinfo);
  time_00X0new = timeMin[0] - '0';
  time_000Xnew = timeMin[1] - '0';

  if ( (time_00X0new != time_00X0) 
    or (time_000Xnew != time_000X) ) {
    strftime(timeHour, 3, "%H", &timeinfo);
    strftime(timeFull, 40, "%A, %d %B %Y %H:%M:%S", &timeinfo);
    Print("Hour: ");
    Println(timeHour);
    Print("Minute: ");
    Println(timeMin);
    Print("FullTime");
    Println(timeFull);
    Println("");

    //Calculate new values & redraw clocks
    time_X000new = timeHour[0] - '0';
    time_0X00new = timeHour[1] - '0';
    time_X000 = time_X000new;
    time_0X00 = time_0X00new;
    time_00X0 = time_00X0new;
    time_000X = time_000Xnew;

    switch (randomMode) {
      case RANDOM_OFF:
        distributeCommand(COMMAND_MOVETO, time_0X00, time_00X0, time_000X);
        calculateMovementToNr(time_X000);
        moveNextDigit();
        showDigit(time_X000, false);
        break;    
    case RANDOM_ON:
        distributeCommand(COMMAND_RANDOM, time_0X00, time_00X0, time_000X);
        calculateMovementRandom();
        moveNextDigit();    
        calculateMovementToNr(time_X000);
        moveNextDigit();
        showDigit(time_X000, false);
        break;
      default:
        Println("Impossible RandomMode");
        break;
    }
  }
  delay(500);
}
