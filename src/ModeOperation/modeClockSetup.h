void modeClockSetup(){
  startWifi();
  Println("Now in mode Clock");
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  delay(100);
}
