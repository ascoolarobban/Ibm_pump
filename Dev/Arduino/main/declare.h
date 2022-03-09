
//PUMP
String city = "Kista";
int pump_id = 1001;


//DHT 
#define DHTTYPE DHT11  
#define DHTPIN A0 
float lastHumidity;
float lastTemperature;

float humidity;
float temperature;





//BUTTON
const byte button_A = 2; // INTERRUPT BUTTON 1(A)
const byte button_B = 3; // INTERRUPT BUTTON 2(B)

//SENSORS
int temp = random(5, 32);
int flow = random(5, 200);
int lastTemp;
int lastFlow;

//Interrupt triggers true/false switch.
int trigger_A = false;
int trigger_B = false;

//millis
unsigned long startMillis;
unsigned long startMillisB;

long debounceDelay = 200; 
unsigned long buttonAStartMillis = 0;
unsigned long buttonBStartMillis = 0;
