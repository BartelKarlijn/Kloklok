void distributeCommandSingle(uint8_t clock, uint8_t command, uint8_t param) {
  String commandString = "hey ";
  commandString        += String(clock) + " ";
  commandString        += String(command) + " ";
  commandString        += String(param);
  Print(commandString);
}


void distributeCommand(uint8_t command, uint8_t p1, uint8_t p2, uint8_t p3) {
  distributeCommandSingle(3, command, p3);
  distributeCommandSingle(2, command, p2);
  distributeCommandSingle(1, command, p1);
  delay(REACTIONTIME);
}
