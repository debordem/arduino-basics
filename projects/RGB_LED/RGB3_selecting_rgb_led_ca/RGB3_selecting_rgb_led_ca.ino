/*  SELECTING Common Anode (+) RGB LED
 *
 *  Selecting the LED to vary set up fo the RGBA Common Anode LED
 *  ~ on pin indicated a PWM or analoge pin
 *
 *  Using a variable Resistor to cahnge the analog value of brightness
 */

// Initialise the pins
// OUTPUTS
int redPin=11;  //set red LED pin to 11
int greenPin=10; //set green LED pin to 10
int bluePin=9; //set blue LED pin to 9

// INPUTS
int redSwitch=7;  //set red SWITCH pin to 7
int greenSwitch=4; //set green SWITCH pin to 4
int blueSwitch=2; //set blue SWITCH pin to 2


// Initalise Variables
int sensorPin = A0;    // select the input pin for the potentiometer
int input = 0;        // variable for the value of the sensorPin


// set default brightness
int brightness = 0;
int redBrightness = 0; //Set Blue brightness to 0
int blueBrightness = 0; //Set Blue brightness to 0
int greenBrightness = 0; //Set Blue brightness to 0

// set default sensor values
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

// SETUP
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //Turn on Serial port
  pinMode(redPin, OUTPUT); //Set redPin to be an output
  pinMode(greenPin, OUTPUT); //Set greenPin to be an output
  pinMode(bluePin, OUTPUT); //set bluePin to be an output

  pinMode(redSwitch, INPUT); //Set redPin to be an output
  pinMode(greenSwitch, INPUT); //Set greenPin to be an output
  pinMode(blueSwitch, INPUT); //set bluePin to be an output

}

// LOOP
void loop() {

  input = analogRead(sensorPin); // resd the input
  brightness = map(input, 1023, 0, 0, 255); // map the brightness to the input between 0 255
  Serial.println(brightness);

  if (digitalRead(redSwitch) == HIGH){
        delay(15); // software debounce
        if (digitalRead(redSwitch) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            redBrightness = brightness;
            Serial.println("SET RED");
        }
    }

   if (digitalRead(greenSwitch) == HIGH){
        delay(15); // software debounce
        if (digitalRead(greenSwitch) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            greenBrightness = brightness;
            Serial.println("SET GREEN");
        }
    }

    if (digitalRead(blueSwitch) == HIGH){
        delay(15); // software debounce
        if (digitalRead(blueSwitch) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            blueBrightness = brightness;
            Serial.println("SET BLUE");
        }
    }



  delay(50);

  analogWrite(redPin, 255 - redBrightness); //turn off red pin
  analogWrite(greenPin, 255 - greenBrightness); //turn off green pin
  analogWrite(bluePin, 255 - blueBrightness); //write 100 (brightness) to blue pin

  Serial.println("R: " + String(redBrightness) + " G: "+ String(greenBrightness) + " B: "+ String(blueBrightness));
  
}
