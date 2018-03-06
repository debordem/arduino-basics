/*  Basic Common Anode (+) RGB LED 
 * 
 *  Advanced set up fo the RGBA Common Anode LED
 *  ~ on pin indicated a PWM or analoge pin
 * 
 *  Using a variable Resistor to cahnge the analog value of brightness
 */

// Initialise the pins

int redPin=11;  //set red LED pin to 11
int greenPin=10; //set green LED pin to 10
int bluePin=9; //set blue LED pin to 9

int sensorPin = A0;    // select the input pin for the potentiometer

// set default brightness
int blueBrightness = 0; //Set Blue brightness to 0

int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value
 
void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600); //Turn on Serial port
  pinMode(redPin, OUTPUT); //Set redPin to be an output
  pinMode(greenPin, OUTPUT); //Set greenPin to be an output
  pinMode(bluePin, OUTPUT); //set bluePin to be an output

  
 
}
 
void loop() {
  // put your main code here, to run repeatedly: 
  blueBrightness = analogRead(sensorPin);

  blueBrightness = map(blueBrightness, 1023, 0, 0, 255);
 
  Serial.println(blueBrightness); 
  
  delay(50);
  
  analogWrite(redPin, 255 - 0); //turn off red pin
  analogWrite(greenPin, 255 - 0); //turn off green pin
  analogWrite(bluePin, 255 - blueBrightness); //write 100 (brightness) to blue pin
}
