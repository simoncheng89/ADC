/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = LED_BUILTIN;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

double T, Temp;
double TT = 301.15;  
double lnR;
int16_t R;          
int16_t R0 = 8805;  
int16_t B  = 3950;
int16_t Pullup = 9930;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
   Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  
  // R / (Pullup + R)   = adc / 4096
  R = (Pullup * sensorValue) / (4096-sensorValue);
  // B = (log(R) -log(R0)) / (1/T -1/T0) 
  T = 1 / (1/TT + (log(R)-log(R0)) / B );
  Temp = T-273.15;
  
   Serial.println(Temp);
}


  
