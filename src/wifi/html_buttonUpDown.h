String html_buttonUpDown( String omschrijving, uint16_t IDup, uint16_t IDdown, uint8_t Var, String VarLabel) {

  String ptr = "<tr><td>\n";
  ptr += omschrijving;
  ptr += "</td><td><do class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\""; 
  ptr += IDdown;
  ptr += "\"> - </do></td><td>\n" ;
  ptr += Var;
  ptr += "</td><td><up class=\"button button-of\" onclick=\"toggleCheckbox(this)\" id=\""; 
  ptr += IDup;
  ptr += "\"> + </up></td><td> Value= </td><td>" ;
  ptr += VarLabel;
  ptr += "</td></tr>\n" ;

  return ptr;
}
