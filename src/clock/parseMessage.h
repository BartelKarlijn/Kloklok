void parseMessage() {
  String cmdString;

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
  cmdString      = serialMessage.charAt(1);
  if( cmdString.toInt() == namePtr ) {
    cmdString  = serialMessage.charAt(0);
    cmdCommand = cmdString.toInt();
    cmdString  = serialMessage.charAt(1);
    cmdClock   = cmdString.toInt();
    cmdString  = serialMessage.charAt(2);
    cmdParam   = cmdString.toInt();
    cmdAction  = true;
    Print("cmd= ");
    Println(serialMessage);
    }
  serialMessage = "";
}
