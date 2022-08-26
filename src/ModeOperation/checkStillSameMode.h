void checkStillSameMode () {
// check we're still on the same mode.  If not, run appropriate setup before continuing
  if (operationMode != operationModeOld) {
    switch (operationMode)
    {
    case MODE_CHECKFPS:
      modeCheckFpsSetup();
      break;
    case MODE_CLOCK:
      modeClockSetup();
      break;
    case MODE_CLOCKDEMO:
      modeClockDemoSetup();
      break;
    case MODE_DIGITSHOW:
      modeDigitShowSetup();
      break;
    case MODE_DIGITDANCE:
      modeDigitDanceSetup();
      break;
    case MODE_SLAVE:
      modeSlaveSetup();
      break;
    default:
      Println("Impossible operationMode in setup");
      break;
  }
  operationModeOld = operationMode;
  }
}
