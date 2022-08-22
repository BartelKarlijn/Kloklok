void modeClockLoop(){
  struct tm timeinfo;
  char timeHour[3];
  char timeMin[3];
  char timeFull[40];
  uint8_t time_000X_new, time_00X0_new;

  checkStillSameMode ();
  if(!getLocalTime(&timeinfo)){
    Print("Failed to obtain time");
    return;
  }

  strftime(timeMin, 3, "%M", &timeinfo);
  time_00X0_new = timeMin[0] - '0';
  time_000X_new = timeMin[1] - '0';

  if ( (time_00X0_new != time_00X0) 
    or (time_000X_new != time_000X) ) {
    strftime(timeHour, 3, "%H", &timeinfo);
    strftime(timeFull, 40, "%A, %d %B %Y %H:%M:%S", &timeinfo);
    Print("Hour: ");
    Println(String(timeHour));
    Print("Minute: ");
    Println(String(timeMin));
    Print("FullTime");
    Println(String(timeFull));
    Println("");

    //Calculate new values & redraw clocks
    time_X000 = timeHour[0] - '0';
    time_0X00 = timeHour[1] - '0';
    time_00X0 = time_00X0_new;
    time_000X = time_000X_new;
    
    distributeCommand(COMMAND_MOVETO, time_0X00, time_00X0, time_000X);
    calculateMovementToNr(time_X000);
    moveNextDigit();

  }
  delay(500);
}
