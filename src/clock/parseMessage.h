void parseMessage() {
  String cmdClockString;
  char intToChar[3];

  // commands start with 
  // structure:
  //     <         (CMD_BEGIN)
  //     command    (length 1)
  //     clocknr
  //     parameter (digit)
  //     >         (CMD_STOP)
  // eg "<438>"  = clock 3 moveto 8
  //    "<525>"  = clock 2 setmode 5 = Slave
  //    "<524>"  = clock 2 setmode 4 = digitTest
  

  messageChanged = false;
  for (int i = 4; i < serialMessage.length(); i++) {
    if( (serialMessage.charAt(i) == CMD_START) and (serialMessage.charAt(i+4)== CMD_STOP)) {
      cmdClockString = serialMessage.charAt(i+2);
      //cmdClockString = serialMessage(i+2);
      if( cmdClockString.toInt() == namePtr ) {
      cmdClockString = serialMessage.charAt(i+1);
      cmdCommand = cmdClockString.toInt();
      cmdClockString = serialMessage.charAt(i+2);
      cmdClock   = cmdClockString.toInt();
      cmdClockString = serialMessage.charAt(i+3);
      cmdParam   =  cmdClockString.toInt();
      cmdAction  = true;
     
      Print("Command= ");
      Print(String(cmdCommand));
      Print(" Clock= ");
      Print(String(cmdClock));
      Print("  param= ");
      Println(String(cmdParam));
      break;           // don't process message further
    }
    }
  }
  serialMessage = "";
  
}