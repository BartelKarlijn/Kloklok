void modeSlaveLoop(){
  checkStillSameMode ();
  readSerial();
  if (messageChanged) {
    Print("Message= ");
    Println(serialMessage);
  }
  parseMessage();
  if (cmdAction) {
    switch (cmdCommand)
    {
    case COMMAND_CLEARS:
      clearScreens(COLOR_BACKGROUND, false);
      break;
    case COMMAND_CLEARA:
      clearScreens(COLOR_BACKGROUND, true);
      break;
    case COMMAND_SHOWDB:
      showDigit(cmdParam);
      break;
    case COMMAND_MOVETO:
      calculateMovementToNr(cmdParam);
      moveNextDigit();
      break;    
    case COMMAND_SETMOD:
      mode = cmdParam;
      break;
    default:
      break;
    }
  }

  cmdAction = false;
  delay(100);
}
