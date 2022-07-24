void parseMessage() {
  String cmdClockString;
  // commands start with "hey"
  // structure:
  //     hey
  //     clocknr
  //     command  -- length 6 !(ClearS, ShowDG, MoveTo)
  //     parameter (digit)
  // eg "hey 3 MoveTo 8"
  messageChanged = false;
  cmdHey = serialMessage.substring(0, 4);
  if (cmdHey == "hey "){
    // continue parsing
    cmdClock   = serialMessage.substring(4, 5).toInt();
    cmdCommand = serialMessage.substring(6, 12);
    cmdParam   = serialMessage.substring(13, 14).toInt();
    Print("Hey= ");
    Print(cmdHey);
    Print("  Clock= ");
    Print(String(cmdClock));
    Print("  command= ");
    Print(cmdCommand);
    Print("  param= ");
    Println(String(cmdParam));

  } 
  cmdHey = "";
  serialMessage = "";
  
}