void stopWifi(){
  if (flagWifiOn = true) {
//    WiFi.mode(WIFI_OFF);
//    wait for master command to be sure he's there  
    flagWifiOn = false;
    startWifi();  // currensty still starting wifi to test
  }
}