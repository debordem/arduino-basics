/*
 


 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int redLED = 12;
const int yellowLED = 11;
const int greenLED = 10;

int sensorValue = 0;        // value read from the pot


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  //  Set up the Output LED's
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  if (sensorValue > 50){
     digitalWrite(redLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(redLED, LOW);   // turn the LED on (HIGH is the voltage level)
  }

  if (sensorValue > 35){
     digitalWrite(yellowLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(yellowLED, LOW);   // turn the LED on (HIGH is the voltage level)
  }

  if (sensorValue > 30){
     digitalWrite(greenLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(greenLED, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  

  
  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.println("\t");
 
 

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
