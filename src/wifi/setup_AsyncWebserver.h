void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  AsyncElegantOTA.begin(&webserver);

  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  WebSerial.begin(&webserver);

  // Route for Wifi Passwoord onderhoud
  webserver.on(hdlWifiPWD, HTTP_GET, [](AsyncWebServerRequest *request) {
    Print("Wifi config pagina");
    request->send_P(200, "text/html", config_html, html_processorWifi);
//    Print("webserver running on core ");
//    Println(String(xPortGetCoreID()));
  });

  // Opvangen als wifi data bewaard worden
  webserver.on(hdlWifiSave, HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    if (request->hasParam(PARAM_ssid)) {
      wifi_ssid = request->getParam(PARAM_ssid)->value();
    }
    else {
      wifi_ssid = "X";
    }
    if (request->hasParam(PARAM_pwd)) {
      wifi_pwd = request->getParam(PARAM_pwd)->value();
    }
    else {
      wifi_pwd = "X";
    }
    Print("ssid ");
    Println(wifi_ssid);
    Print("pwd ");
    Println(wifi_pwd);
    
    save_WIFIdatato_eeprom (); 
    Println("Wifi SSID and PWD saved; please reboot ESP32");
    request->send_P(200, "text/html", config_html, html_processorWifi);
  });


  // Route for root / web page (controller)
  webserver.on(hdlRoot, HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", config_html, html_processorRoot);
  });

  // Verwerk als er op een knop wordt gedrukt
  webserver.on(hdlKnop, HTTP_GET, [](AsyncWebServerRequest *request) {
    String IDknopString;
    uint16_t IDknop;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_output)) {
      IDknopString = request->getParam(PARAM_output)->value();
      IDknop = IDknopString.toInt();
    }
    else {
      IDknop = 0;
    }

    Print("knop= ");
    Println(String(IDknop));
    switch (IDknop) {
    case id_Modedo:  //mode
      mode = buttonChangeUp(mode, -1, "mode", MODEDESC_COUNT);
      break;
    case id_Modeup:
      mode = buttonChangeUp(mode, +1, "mode", MODEDESC_COUNT);
      break;
    case id_Mvmtdo:  //movement mode
      mode = buttonChangeUp(movementMode, -1, "Movement mode", MOVEMENTMODEDESCOUNT);
      break;
    case id_Mvmtup:
      mode = buttonChangeUp(movementMode, +1, "Movement mode", MOVEMENTMODEDESCOUNT);
      break;
    case id_namePtrdo:  //name pointer
      namePtr = buttonChangeUp(namePtr, -1, "namePtr", 4);
      break;
    case id_namePtrup:
      namePtr = buttonChangeUp(namePtr, +1, "namePtr", 4);
      break;
    case id_waitDelaydo:  //delay between movements
      waitDelay = buttonChangeUp(waitDelay, -1, "waitDelay", WAITDELAYMAX);
      break;
    case id_waitDelayup:
      waitDelay = buttonChangeUp(waitDelay, +1, "waitDelay", WAITDELAYMAX);
      break;
    case id_Rotdo:  //name Rotation 0
      clockRotation = buttonChangeUp(clockRotation, -1, "clockRotation", 4);
      break;
    case id_Rotup:
      clockRotation = buttonChangeUp(clockRotation, +1, "clockRotation", 4);
      break;
    //Save Config
    case id_SaveConfig:
      buttonChangeConfig();
      break;
    //Restart
    case id_Restart:
      buttonChangeRestart();
      break;

    default:
      Println("Impossible IDknop");
      break;
    }  // einde switch
    
    request->send(200, "text/plain", "OK");

  });

  // Start server
  webserver.begin();
}