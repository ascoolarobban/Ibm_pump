
//SERIAL NUMBER ARDUINO:
char SN[128] = "8573432363035131A052";

//PUMP
String city = "Kista";
int pump_id = 1001;

//BUTTON DEBOUNCE TRIGGERS
bool trigger_A = false;
bool trigger_B = false;
bool trigger_C = false;

//DHT 
#define DHTTYPE DHT11  
#define DHTPIN A0 
float lastHumidity;
float lastTemperature;

float humidity;
float temperature;





//BUTTON
#define button_A  2 // BUTTON 1(A)
#define button_B  13 // BUTTON 2(B)
#define button_C  4 // BUTTON 3(C)

//SENSORS
int temp = random(5, 32);
int flow = random(5, 200);
int lastTemp;
int lastFlow;

//RPM
int fan_speed = 0;
int pump_speed= 0;

//POTENTIOMETER VALUES
int pot_1 = 0;
int pot_2 = 0;
int pot_3 = 0;


//TIME
unsigned long startMillis;
unsigned long currentMillis;
char runTimeBuffer[21];

//LEDSHOW WAIT
long timeN = 0;
int waitPeriod = 10000;

long debounceDelay = 200; 
unsigned long buttonAStartMillis = 0;
unsigned long buttonBStartMillis = 0;
unsigned long buttonCStartMillis = 0;
