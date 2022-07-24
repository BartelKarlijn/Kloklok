void parseMessage() {
  // commands start with "hey"
  // structure:
  //     hey
  //     clocknr
  //     command  (ClearS, ShowDG, MoveTo)
  //     parameter (digit)
  messageChanged = false;
  cmdHey = serialMessage.substring(0, 4);
  if (cmdHey = "hey "){
    // continue parsing
    cmdClock = serialMessage.substring(4, 10);

  } 
  serialMessage = "";
  
}