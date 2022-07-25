void startWifi() {
  if (flagWifiOn == false) {
    setup_ConnectKnownWifi();  // Aan gekende wifi connecteren
    setup_AsyncWebserver();    // webserver om html te tonen 
    setup_CreateAccessPoint(); // Toch eigen AccessPoint opzetten als gekende wifi niet gelukt.
  }
  flagWifiOn = true;
}