void modeClockDemoLoop(){
  uint8_t time_X000new, time_0X00new, time_00X0new, time_000Xnew;
  checkStillSameMode ();

  if (flag_timeSetManually == true) {
    time_X000new = time_hh.charAt(0);
    time_0X00new = time_hh.charAt(1);
    time_00X0new = time_mm.charAt(0);
    time_000Xnew = time_mm.charAt(1);
  }
  else {
   time_000Xnew = time_000Xnew + 1;
   if (time_000Xnew > 9) {
     time_000Xnew = 0;
     time_00X0new = time_00X0new + 1;
     if (time_00X0new > 5) {
       time_0X00new = time_0X00new + 1;
       if (time_0X00new > 9) {
        time_0X00new = 0;
       }
     }
   }
  }
  
  distributeCommand(COMMAND_MOVETO, time_0X00new, time_00X0new, time_000Xnew);
  calculateMovementToNr(time_X000new);
  moveNextDigit();
  showDigit(time_X000new, false);

  delay(waitDelay * 1000 + 150);

}
