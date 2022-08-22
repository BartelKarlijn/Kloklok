String html_processorRoot(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>" + nameTbl[namePtr] + "</h1><table>";

    buttons += html_buttonUpDown(oms_mode, id_Modeup, id_Modedo, mode, modeTbl[mode]);
    buttons += html_buttonUpDown(oms_namePtr, id_namePtrup, id_namePtrdo, namePtr, nameTbl[namePtr]);
    buttons += html_buttonUpDown(oms_waitDelay, id_waitDelayup, id_waitDelaydo, waitDelay, String(waitDelay) ) ;
    buttons += html_buttonUpDown(oms_Rot, id_Rotup, id_Rotdo, clockRotation, String(rotationTbl[clockRotation]));
    buttons += html_buttonUpDown(oms_mvmt, id_Mvmtup, id_Mvmtdo, movementMode, String(movementModeTbl[movementMode]));
    buttons += html_buttonSimple(id_SaveConfig, "SAVE", oms_SaveConfig);
    buttons += html_buttonSimple(id_Restart, "/!\\", oms_Restart);
    buttons += "</table>";
    buttons += html_doubleInput("HH MM", "pUUR", "pMIN", 2, "hdl_savetime");

    buttons += html_buttonLink("Wifi Management", hdlWifiPWD);
    buttons += html_buttonLink("WebSerial", hdlWebSerial);
    buttons += html_buttonLink("Firmware update", hdlUpdate);
    
    buttons += "<p>Build commit= " + String(AUTO_COMMITPT);
    buttons += ", Compilation date= " + String(__DATE__) ;
    buttons += ",  time= " + String(__TIME__) + "</p>";

    return buttons;
  }
  return String();
}

String html_processorWifi(const String& var){
// Replaces placeholder with wifi section
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>Wifi instellen</h1>";
//    buttons += "<form action=\"/scan\" method=\"POST\"><input type=\"submit\" value=\"scan\"></form>";
    buttons += wifi_scan;
    buttons += "</p><form method='get' action='wifisave'><label>SSID: </label><input name='ssid' length=32><input name='pwd' length=64><input type='submit'></form><br>";
    buttons += html_buttonSimple(id_Restart, "/!\\", oms_Restart);
    buttons += html_buttonLink("naar Root", hdlRoot);
    return buttons;
  }
  return String();
}
