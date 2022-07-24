String html_processorRoot(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>" + nameTbl[namePtr] + "</h1><table>";

    buttons += html_buttonUpDown(oms_Kp, id_Kpup, id_Kpdo, Kp, "Kp deleteme");
    buttons += html_buttonUpDown(oms_mode, id_Modeup, id_Modedo, modeNew, modeTbl[modeNew]);
    buttons += html_buttonUpDown(oms_namePtr, id_namePtrup, id_namePtrdo, namePtr, nameTbl[namePtr]);
    buttons += html_buttonUpDown(oms_Rot0, id_Rot0up, id_Rot0do, clockRotation[0], String(rotationTbl[clockRotation[0]]));
    buttons += html_buttonUpDown(oms_Rot1, id_Rot1up, id_Rot1do, clockRotation[1], String(rotationTbl[clockRotation[1]]));
    buttons += html_buttonUpDown(oms_Rot2, id_Rot2up, id_Rot2do, clockRotation[2], String(rotationTbl[clockRotation[2]]));
    buttons += html_buttonUpDown(oms_Rot3, id_Rot3up, id_Rot3do, clockRotation[3], String(rotationTbl[clockRotation[3]]));
    buttons += html_buttonUpDown(oms_Rot4, id_Rot4up, id_Rot4do, clockRotation[4], String(rotationTbl[clockRotation[4]]));
    buttons += html_buttonUpDown(oms_Rot5, id_Rot5up, id_Rot5do, clockRotation[5], String(rotationTbl[clockRotation[5]]));
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
