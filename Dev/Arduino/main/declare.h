
//PUMP
String city = "Stockholm";
int pump_id = 1;

//BUTTON
const byte button_A = 2; // interrupt pins are 2,3


//SENSORS
int temp = random(5, 32);
int flow = random(5, 200);
int lastTemp;
int lastFlow;

//Interrupt triggers true/false switch.
int trigger_A = false;
int trigger2 = false;

//millis
unsigned long startMillis;
long lastDebounceTime = 0; 
long debounceDelay = 200; 
unsigned long buttonAStartMillis = 0;
unsigned long buttonBStartMillis = 0;
