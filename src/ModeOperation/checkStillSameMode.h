void checkStillSameMode () {
// check we're still on the same mode.  If not, run appropriate setup before continuing
  if (operationMode != operationModeOld) {
    // cooldown period
    operationModeOld = operationMode;
    delay(DELAY_COOLDOWN);
    if (operationMode != operationModeOld) {
      // not changed in cooldown period
      switch (operationMode)
      {
      case OPERATION_CHECKFPS:
        modeCheckFpsSetup();
        break;
      case OPERATION_CLOCK:
        modeClockSetup();
        break;
      case OPERATION_CLOCKDEMO:
        modeClockDemoSetup();
        break;
      case OPERATION_DIGITSHOW:
        modeDigitShowSetup();
        break;
      case OPERATION_DIGITDANCE:
        modeDigitDanceSetup();
        break;
      case OPERATION_SLAVE:
        modeSlaveSetup();
        break;
      default:
        Println("Impossible operationMode in setup");
        break;
      }
    }
  }
}
