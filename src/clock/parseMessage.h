void parseMessage() {
  String cmdClockString;

  // commands start with 
  // structure:
  //     <         (CMD_START)
  //     command    (length 1)
  //     clocknr
  //     parameter (digit)
  //     >         (CMD_STOP)
  // eg "<438>"  = clock 3 moveto 8
  //    "<525>"  = clock 2 setmode 5 = Slave
  //    "<524>"  = clock 2 setmode 4 = digitDance
  // However, readserial strips CMD_START/STOP

  messageChanged = false;
  cmdClockString = serialMessage.charAt(1);
  if( cmdClockString.toInt() == namePtr ) {
    cmdClockString = serialMessage.charAt(0);
    cmdCommand = cmdClockString.toInt();
    cmdClockString = serialMessage.charAt(1);
    cmdClock   = cmdClockString.toInt();
    cmdClockString = serialMessage.charAt(2);
    cmdParam   =  cmdClockString.toInt();
    cmdAction  = true;
    }
  serialMessage = "";
}
