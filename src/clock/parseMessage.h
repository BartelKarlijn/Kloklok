void parseMessage() {
  String cmdClockString;
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
  for (int i = 0; i < serialMessage.length(); i++) {
    if( (serialMessage[i] == CMD_BEGIN) and (serialMessage[i+2] == namePtr) and (serialMessage[i+4]== CMD_STOP) ) {
      cmdCommand = serialMessage[i+1];
      cmdClock   = serialMessage[i+2];
      cmdParam   = serialMessage[i+3];
      cmdAction  = true;
     
      Print("Command= ");
      Print(String(cmdCommand));
      Print(" Clock= ");
      Print(String(cmdClock));
      Print("  param= ");
      Println(String(cmdParam));
    }
  }
  serialMessage = "";
  
}