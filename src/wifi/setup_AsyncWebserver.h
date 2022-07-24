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
      modeNew = buttonChangeUp(modeNew, -1, "modeNew", 5);
      break;
    case id_Modeup:
      modeNew = buttonChangeUp(modeNew, +1, "modeNew", 5);
      break;
    case id_namePtrdo:  //name pointer
      namePtrNew = buttonChangeUp(namePtrNew, -1, "namePtrNew", 4);
      break;
    case id_namePtrup:
      namePtrNew = buttonChangeUp(namePtrNew, +1, "modePtrNew", 4);
      break;
    case id_Rot0do:  //name Rotation 0
      clockRotation[0] = buttonChangeUp(clockRotation[0], -1, "clockRotation[0]", 4);
      break;
    case id_Rot0up:
      clockRotation[0] = buttonChangeUp(clockRotation[0], +1, "clockRotation[0]", 4);
      break;
    case id_Rot1do:  //name Rotation 1
      clockRotation[1] = buttonChangeUp(clockRotation[1], -1, "clockRotation[0]", 4);
      break;
    case id_Rot1up:
      clockRotation[1] = buttonChangeUp(clockRotation[1], +1, "clockRotation[0]", 4);
      break;
    case id_Rot2do:  //name Rotation 2
      clockRotation[2] = buttonChangeUp(clockRotation[2], -1, "clockRotation[0]", 4);
      break;
    case id_Rot2up:
      clockRotation[2] = buttonChangeUp(clockRotation[2], +1, "clockRotation[0]", 4);
      break;
    case id_Rot3do:  //name Rotation 3
      clockRotation[3] = buttonChangeUp(clockRotation[3], -1, "clockRotation[0]", 4);
      break;
    case id_Rot3up:
      clockRotation[3] = buttonChangeUp(clockRotation[3], +1, "clockRotation[0]", 4);
      break;
    case id_Rot4do:  //name Rotation 4
      clockRotation[4] = buttonChangeUp(clockRotation[4], -1, "clockRotation[0]", 4);
      break;
    case id_Rot4up:
      clockRotation[4] = buttonChangeUp(clockRotation[4], +1, "clockRotation[0]", 4);
      break;
    case id_Rot5do:  //name Rotation 5
      clockRotation[5] = buttonChangeUp(clockRotation[5], -1, "clockRotation[0]", 4);
      break;
    case id_Rot5up:
      clockRotation[5] = buttonChangeUp(clockRotation[5], +1, "clockRotation[0]", 4);
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