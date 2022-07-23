void Print(String TXT){
#ifdef PRINTWEBSERIAL
  WebSerial.print(TXT);
#endif
#ifdef PRINTSERIAL
  Serial.print(TXT);
#endif
}

void Println(String TXT){
#ifdef PRINTWEBSERIAL
  WebSerial.println(TXT);
#endif
#ifdef PRINTSERIAL
  Serial.println(TXT);
#endif
}