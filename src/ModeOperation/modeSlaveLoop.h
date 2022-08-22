void modeSlaveLoop(){
  checkStillSameMode ();
  readSerial();
  if (messageChanged) {
    Print("Message= ");
    Println(serialMessage);
    Print("lenght=");
    Println(String(serialMessage.length()));
    messageChanged = false;
  }
  parseMessage();
  if (cmdAction) {
    switch (cmdCommand)
    {
    case COMMAND_CLEARS:
      if(cmdParam == 0){
        clearScreens(COLOR_BACKGROUND, false);
      } else {
        clearScreens(COLOR_BACKGROUND, true);
      }
      break;
    case COMMAND_SHOWDG:
      showDigit(cmdParam, true);
      break;
    case COMMAND_MOVETO:
      calculateMovementToNr(cmdParam);
      moveNextDigit();
      showDigit(cmdParam, false);              //Just to be sure that we don't leave any artefacts behind
      break;    
    case COMMAND_SETMOD:
      mode = cmdParam;
      break;
    default:
      break;
    }
  }
  cmdAction = false;   // Be ready when next action is coming
  
}
