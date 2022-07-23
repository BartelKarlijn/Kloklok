String html_processorRoot(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>" + String(AUTOCONNECTAP) + "</h1><table>";

    buttons += html_buttonUpDown(oms_Kp, id_Kpup, id_Kpdo, Kp, "Mode1=test");
    buttons += html_buttonUpDown(oms_Mode, id_Modeup, id_Modedo, Mode, "changeMode");
    buttons += html_buttonSimple(id_SaveConfig, "SAVE", oms_SaveConfig);
    buttons += html_buttonSimple(id_Restart, "/!\\", oms_Restart);
    buttons += "</table>";
    
    buttons += html_buttonLink("Wifi Management", hdlWifiPWD);
    buttons += html_buttonLink("WebSerial", hdlWebSerial);
    buttons += html_buttonLink("Firmware update", hdlUpdate);
    
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
