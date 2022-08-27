///////////////// TFT  //////////////////////////////
uint8_t tft_cs[6] = {TFT0_CS, TFT1_CS, TFT2_CS, TFT3_CS, TFT4_CS, TFT5_CS };

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite needle1      = TFT_eSprite(&tft); // Sprite object for needle 1 deg
TFT_eSprite needle2      = TFT_eSprite(&tft); // Sprite object for needle 2 deg
TFT_eSprite needle3      = TFT_eSprite(&tft); // Sprite object for needle 3 deg
TFT_eSprite needle4      = TFT_eSprite(&tft); // Sprite object for needle 4 deg

TFT_eSprite needleAxis   = TFT_eSprite(&tft); // Sprite object for centre Axis

///////////////// Angles  /////////////////////////////
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
// Clock rotation
int16_t rotationTbl[] = {ROT_UP, ROT_RIGHT, ROT_DOWN, ROT_LEFT};
uint16_t clockRotation;
int16_t angleto1, angleto2, extraBack, extraFront; 
int16_t angleBTo, angleFTo, angleBFr, angleFFr;
// Time
uint16_t time_X000, time_0X00, time_00X0, time_000X;  //one digit of the time
String  timeString_hh, timeString_mm;
uint16_t time_hh, time_mm;
bool    flag_timeSetManually = false;


//////////////// OPERATION ///////////////////////
uint16_t backlight;     // Backlight level of tft (not yet used)

// timers
unsigned long myTime;
uint8_t fpsCnt;

//////////////// Preferences //////////////////////
Preferences pref_eeprom;

//////////////// MovementModes //////////////////////
uint16_t movementMode;
uint16_t randomMode;

//Mode (clock/clockdemo/...)
int8_t operationMode, operationModeOld = 99;             // On 99, checkStillSameMode gets launched
// communication
String incomingMessage;
String serialMessage;
bool   messageChanged;
uint8_t cmdClock, cmdCommand, cmdParam;
bool   cmdAction;
uint16_t waitDelay;       // default value, gets overwritten from eeprom
#define  WAITDELAYMAX 60  // max value in sec
uint8_t namePtr;  //pointer to nameTbl
String nameTbl[] = {NAME_MASTER, NAME_SLAVE1, NAME_SLAVE2, NAME_SLAVE3};
bool   flagWifiOn = false;


//////// Wifi //////////
// Create AsyncWebServer object on port 80
AsyncWebServer webserver(80);
//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken

// handles voor wifi paginas
#define hdlRoot       "/"                        // handle voor hoofdscherm.  Hier kom je standaard op terecht
#define hdlKnop       "/knop"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlUpdate     "/update"                  // Dit niet wijzigen: is voor OTA firmware 
#define hdlWifiPWD    "/wificfg"                 // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
//#define hdlWifiScan   "/wifiscan"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWifiSave   "/wifisave"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWebSerial  "/webserial"               // Dit is niet te wijzigen, is om Serial Monitor via web te hebben
#define hdlTimeSave   "/timesave"                // handle to submit time

// knoppen
const char* PARAM_output = "output";   // voor de asyncwebserver

const char* oms_mode = "Operation Mode";
const uint16_t   id_Modeup = 121;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Modedo = 122; 

const char* oms_namePtr = "Name mstr/slave";
const uint16_t   id_namePtrup = 131;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_namePtrdo = 132; 

const char* oms_waitDelay = "Delay between steps";
const uint16_t   id_waitDelayup = 141;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_waitDelaydo = 142; 

const char* oms_mvmt = "Movement Mode";
const uint16_t   id_Mvmtup = 151;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Mvmtdo = 152; 

const char* oms_rand = "Random Mode";
const uint16_t   id_Randup = 161;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Randdo = 162; 

const char* oms_Rot = "Rotation sc";
const uint16_t   id_Rotup = 201;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rotdo = 202; 

const char* oms_TimeSave = "Set time HH MM";
const char* PARAM_HH    = "hh";             // parameter for asyncwebserver
const char* PARAM_MM    = "mm";             // parameter for asyncwebserver

const char* oms_WifiSave = "SSID / Password";
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver

const char* oms_SaveConfig = "Save Config";
const uint16_t   id_SaveConfig = 22;

const char* oms_Restart = "Restart";
const uint16_t   id_Restart = 23;
