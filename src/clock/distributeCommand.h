void distributeCommandSingle(uint8_t clock, uint8_t command, uint8_t param) {
  String commandString = "hey ";
  commandString        += String(clock) + " ";
  commandString        += String(command) + " ";
  commandString        += String(param);
  Print(commandString);
}


void distributeCommand(uint8_t command) {
  distributeCommandSingle(3, command, time_000X);
  distributeCommandSingle(2, command, time_00X0);
  distributeCommandSingle(1, command, time_0X00);
}
