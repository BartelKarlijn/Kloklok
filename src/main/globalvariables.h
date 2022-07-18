///////////////// TFT  //////////////////////////////
uint8_t tft_cs[6] = {TFT0_CS, TFT1_CS, TFT2_CS, TFT3_CS, TFT4_CS, TFT5_CS };

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite needle1      = TFT_eSprite(&tft); // Sprite object for needle 1 deg
TFT_eSprite needle2      = TFT_eSprite(&tft); // Sprite object for needle 2 deg
TFT_eSprite needle3      = TFT_eSprite(&tft); // Sprite object for needle 3 deg
TFT_eSprite needle4      = TFT_eSprite(&tft); // Sprite object for needle 4 deg

TFT_eSprite needleAxis   = TFT_eSprite(&tft); // Sprite object for centre Axis

///////////////// Object sizes  //////////////////////////////
#define NEEDLE_WIDTH  NEEDLE_RADIUS * 2   // Width of needle
#define NEEDLE_LENGTH SCREEN_CENTER // Visible length without rounded corners
#define DIAL_WIDTH    SCREEN_CENTER * 2

// Angles
int16_t angleBack[6];      // Angle of back needle
int16_t angleFront[6];     
// How fast is the movement
int16_t moveFront;
int16_t moveBack;
// Backlight
int backlight;

// timing
unsigned long myTime;
int cnt;

//////////////// LED ///////////////////////
boolean startupError;

//////// Preferences //////////
Preferences pref_eeprom;

//////// Wifi //////////
// Create AsyncWebServer object on port 80
AsyncWebServer webserver(80);
//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver
const char* PARAM_output = "output";   // voor de asyncwebserver

// handles voor wifi paginas
#define hdlRoot       "/"                        // handle voor hoofdscherm.  Hier kom je standaard op terecht
#define hdlKnop       "/knop"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlUpdate     "/update"                  // Dit niet wijzigen: is voor OTA firmware 
#define hdlConfig     "/configuratie"            // handle voor wiebelrobot in te stellen
#define hdlWifiPWD    "/wificfg"                 // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
//#define hdlWifiScan   "/wifiscan"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWifiSave   "/wifisave"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWebSerial  "/webserial"               // Dit is niet te wijzigen, is om Serial Monitor via web te hebben

// knoppen
const char* oms_Kp = "Kp proportioneel";
const int   id_Kpup = 111;            // knop ID, moet uniek zijn, zie html_processor
const int   id_Kpdo = 112; 
const int   id_Kpra = 113;  

const char* oms_Ki = "Ki Integraal";
const int   id_Kiup = 121;
const int   id_Kido = 122; 
const int   id_Kira = 123;  

const char* oms_Kd = "Kd Derivation";
const int   id_Kdup = 131;
const int   id_Kddo = 132; 
const int   id_Kdra = 133;  

const char* oms_An = "Balanceer Hoek";
const int   id_Anup = 141;
const int   id_Ando = 142; 
const int   id_Anra = 143;  

const char* oms_ShowAngle = "Gemeten Hoek=";
const int   id_ShowAngle = 21;

const char* oms_SaveConfig = "Save PID";
const int   id_SaveConfig = 22;

const char* oms_Restart = "Restart";
const int   id_Restart = 23;

const char* oms_MotorENA = "Motoren aan/uit";
const int   id_MotorENA = 24;

volatile float Kp_change = 1.0;      // Elke druk in wifi app, verhoogt/verlaagt met waarde
volatile float Ki_change = 1.0;
volatile float Kd_change = 1.0; 
volatile float An_change = 1.0; 
