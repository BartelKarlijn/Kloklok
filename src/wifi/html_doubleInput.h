String html_doubleInput(String txtVoorKnop, String param_fld1, String param_fld2, int fldlenght, String hdlaction) {
  String ptr = "</p><form method='get' action='";
  ptr += hdlaction + "'><label>";
  ptr += txtVoorKnop + ": </label><input name='";
  ptr += param_fld1  + "' length=";
  ptr += fldlenght;
  ptr +="><input name='";
  ptr += param_fld2  + "' length=";
  ptr += fldlenght;
  ptr += "><input type='submit'></form><br>";
  return ptr;
}

//    buttons += "</p><form method='get' action='wifisave'><label>SSID: </label><input name='ssid' length=32><input name='pwd' length=64><input type='submit'></form><br>";
