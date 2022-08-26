void modeClockDemoLoop(){
  uint8_t time_X000new, time_0X00new, time_00X0new, time_000Xnew;
  checkStillSameMode ();

  if (flag_timeSetManually == true) {
    time_hh = timeString_hh.toInt();
    if (time_hh > 23) {time_hh = 0;}
    time_mm = timeString_mm.toInt();
    if (time_mm > 59) {time_mm = 0;}
    flag_timeSetManually = false;
  }
  else {
    time_mm ++;
    if (time_mm > 59) {
      time_mm = 0;
      time_hh ++;
      if (time_hh > 23) {time_hh = 0;}
      }
  }
  time_X000new = time_hh / 10;
  time_0X00new = time_hh - (time_X000new * 10);
  time_00X0new = time_mm / 10;
  time_000Xnew = time_mm - (time_00X0new * 10);

  switch (randomMode) {
    case RANDOM_OFF:
//    do nothing, just the regular    
      break;    
    case RANDOM_ON:
      distributeCommand(COMMAND_RANDOM, time_0X00new, time_00X0new, time_000Xnew);
      calculateMovementRandom();
      moveNextDigit();    
      break;    
    default:
      Println("Impossible RandomMode");
      break;
  }
  distributeCommand(COMMAND_MOVETO, time_0X00new, time_00X0new, time_000Xnew);
  calculateMovementToNr(time_X000new);
  moveNextDigit();
  showDigit(time_X000new, false);

  delay(waitDelay * 1000 + 150);

}
