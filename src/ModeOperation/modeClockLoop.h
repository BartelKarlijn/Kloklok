void modeClockLoop(){
  checkStillSameMode ();
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Print("Failed to obtain time");
    return;
  }

  Println("Time variables");
  char timeHour[3];
  strftime(timeHour, 3, "%H", &timeinfo);
  Print("Hour: ");
  Println(String(timeHour));
  char timeMin[3];
  strftime(timeMin, 3, "%M", &timeinfo);
  Print("Minute: ");
  Println(String(timeMin));
  char timeFull[40];
  strftime(timeFull, 40, "%A, %d %B %Y %H:%M:%S", &timeinfo);
  Print("FullTime");
  Println(String(timeFull));
  Println("");
  delay(waitDelay * 1000 + 150);
}
