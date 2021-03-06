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
uint8_t currentNr;  // What digit are we displaying?
// Current angle
int16_t angleBack[6];      
int16_t angleFront[6];
// Movement of next frame.  Even, Uneven: every other framenr we switch between both
uint16_t  moveEvenFront[6];  
uint16_t  moveUnEvFront[6];  
uint16_t  moveEvenBack[6];
uint16_t  moveUnEvBack[6];

// How fast is the movement
uint16_t moveFront;
uint16_t moveBack;
// Backlight
uint16_t backlight;

// timing
unsigned long myTime;
uint8_t cnt;

//////////////// LED ///////////////////////
boolean startupError;

//MovementModes
#define MOVEMENTMODEMIN 1   // as little movement as possible
#define MOVEMENTMODEMAX 2   // as much movement as possible
#define MOVEMENTMODEFUN 3   // balanced
int16_t movementMode = MOVEMENTMODEFUN;
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
const uint16_t   id_Kpup = 111;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Kpdo = 112; 
const uint16_t   id_Kpra = 113;  

const char* oms_Ki = "Ki Integraal";
const uint16_t   id_Kiup = 121;
const uint16_t   id_Kido = 122; 
const uint16_t   id_Kira = 123;  

const char* oms_Kd = "Kd Derivation";
const uint16_t   id_Kdup = 131;
const uint16_t   id_Kddo = 132; 
const uint16_t   id_Kdra = 133;  

const char* oms_An = "Balanceer Hoek";
const uint16_t   id_Anup = 141;
const uint16_t   id_Ando = 142; 
const uint16_t   id_Anra = 143;  

const char* oms_ShowAngle = "Gemeten Hoek=";
const uint16_t   id_ShowAngle = 21;

const char* oms_SaveConfig = "Save PID";
const uint16_t   id_SaveConfig = 22;

const char* oms_Restart = "Restart";
const uint16_t   id_Restart = 23;

const char* oms_MotorENA = "Motoren aan/uit";
const uint16_t   id_MotorENA = 24;

volatile float Kp_change = 1.0;      // Elke druk in wifi app, verhoogt/verlaagt met waarde
volatile float Ki_change = 1.0;
volatile float Kd_change = 1.0; 
volatile float An_change = 1.0; 
