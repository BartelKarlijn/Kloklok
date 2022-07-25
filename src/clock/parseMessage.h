void parseMessage() {
  String cmdClockString;
  // commands start with "hey"
  // structure:
  //     hey
  //     command    (length 1)
  //     clocknr
  //     parameter (digit)
  // eg "hey 3 4 8"  = clock 3 moveto 8
  //    "hey 2 5 5"  = clock 2 setmode 5 = Slave
  //    "hey 2 5 5"  = clock 2 setmode 4 = digitTest
  

  messageChanged = false;
  cmdHey = serialMessage.substring(0, 4);
  if (cmdHey == "hey "){
    // continue parsing
    cmdCommand = serialMessage.substring(4, 5).toInt();
    cmdClock   = serialMessage.substring(6, 7).toInt();
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