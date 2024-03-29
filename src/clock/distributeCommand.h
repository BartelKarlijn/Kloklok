void distributeCommandSingle(uint8_t command, uint8_t clock, uint8_t param) {
  String commandString = String(CMD_START);
  commandString        += String(command);
  commandString        += String(clock);
  commandString        += String(param);
  commandString        += String(CMD_STOP);
  Println(commandString);
}


void distributeCommand(uint8_t command, uint8_t p1, uint8_t p2, uint8_t p3) {
  distributeCommandSingle(command, 3, p3);
  distributeCommandSingle(command, 2, p2);
  distributeCommandSingle(command, 1, p1);
}
