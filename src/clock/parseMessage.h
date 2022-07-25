void parseMessage() {
  String cmdClockString;
  // commands start with "hey"
  // structure:
  //     hey
  //     clocknr
  //     command    (length 1)
  //     parameter (digit)
  // eg "hey 3 4 8"  = clock 3 moveto 8

  messageChanged = false;
  cmdHey = serialMessage.substring(0, 4);
  if (cmdHey == "hey "){
    // continue parsing
    cmdClock   = serialMessage.substring(4, 5).toInt();
    cmdCommand = serialMessage.substring(6, 7).toInt();
    cmdParam   = serialMessage.substring(8, 9).toInt();
    cmdAction  = true;
    
    Print("Hey= ");
    Print(cmdHey);
    Print("  Clock= ");
    Print(String(cmdClock));
    Print("  command= ");
    Print(String(cmdCommand));
    Print("  param= ");
    Println(String(cmdParam));

  } 
  cmdHey = "";
  serialMessage = "";
  
}