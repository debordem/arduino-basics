/*  Basic Common Anode (+) RGB LED 
 * 
 *  Simple set up fo the RGBA Common Anode LED
 *  ~ on pin indicated a PWM or analoge pin
 * 
 */

// Initialise the pins

int redPin=11;  //set red LED pin to 11
int greenPin=10; //set green LED pin to 10
int bluePin=9; //set blue LED pin to 9

// set default brightness
int blueBrightness=1; //Set Blue brightness to 100
 
void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600); //Turn on Serial port
  pinMode(redPin, OUTPUT); //Set redPin to be an output
  pinMode(greenPin, OUTPUT); //Set greenPin to be an output
  pinMode(bluePin, OUTPUT); //set bluePin to be an output
 
}
 
void loop() {
  // put your main code here, to run repeatedly: 

  Serial.println(blueBrightness); 
  
  analogWrite(redPin, 255 - 0); //turn off red pin
  analogWrite(greenPin, 255 - 0); //turn off green pin
  analogWrite(bluePin, 255 - blueBrightness); //write 100 (brightness) to blue pin
}
