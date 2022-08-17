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
uint16_t waitDelay;
uint8_t namePtr;  //pointer to nameTbl
String nameTbl[] = {NAME_MASTER, NAME_SLAVE1, NAME_SLAVE2, NAME_SLAVE3};
String incomingMessage;
String serialMessage;
bool   messageChanged;
uint8_t cmdClock, cmdCommand, cmdParam;
bool   cmdAction;
bool   flagWifiOn = false;

//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver
const char* PARAM_output = "output";   // voor de asyncwebserver

// Clock rotation
int16_t rotationTbl[] = {ROT_UP, ROT_RIGHT, ROT_DOWN, ROT_LEFT};
uint16_t clockRotation[6];
//Mode
int8_t mode, modeOld = 99;             // On 99, checkStillSameMode gets launched

// Time
uint8_t time_X000, time_0X00, time_00X0, time_000X;  //one digit of the time

// handles voor wifi paginas
#define hdlRoot       "/"                        // handle voor hoofdscherm.  Hier kom je standaard op terecht
#define hdlKnop       "/knop"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlUpdate     "/update"                  // Dit niet wijzigen: is voor OTA firmware 
#define hdlWifiPWD    "/wificfg"                 // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
//#define hdlWifiScan   "/wifiscan"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWifiSave   "/wifisave"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWebSerial  "/webserial"               // Dit is niet te wijzigen, is om Serial Monitor via web te hebben

// knoppen
const char* oms_mode = "Operation Mode";
const uint16_t   id_Modeup = 121;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Modedo = 122; 

const char* oms_namePtr = "Name mstr/slave";
const uint16_t   id_namePtrup = 131;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_namePtrdo = 132; 

const char* oms_waitDelay = "Delay between steps";
const uint16_t   id_waitDelayup = 141;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_waitDelaydo = 142; 

const char* oms_Rot0 = "Rotation sc0";
const uint16_t   id_Rot0up = 201;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rot0do = 202; 

const char* oms_Rot1 = "Rotation sc1";
const uint16_t   id_Rot1up = 211;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rot1do = 212; 

const char* oms_Rot2 = "Rotation sc2";
const uint16_t   id_Rot2up = 221;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rot2do = 222; 

const char* oms_Rot3 = "Rotation sc3";
const uint16_t   id_Rot3up = 231;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rot3do = 232; 

const char* oms_Rot4 = "Rotation sc4";
const uint16_t   id_Rot4up = 241;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rot4do = 242; 

const char* oms_Rot5 = "Rotation sc5";
const uint16_t   id_Rot5up = 251;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rot5do = 252; 

const char* oms_SaveConfig = "Save Config";
const uint16_t   id_SaveConfig = 22;

const char* oms_Restart = "Restart";
const uint16_t   id_Restart = 23;
