/* Basic traffic light sequence for one side
 *  
 *  Mike De Borde, January 2017 
 */


/* Constants - these will not change */
const unsigned int GREEN_LED = 10;
const unsigned int YELLOW_LED = 11;
const unsigned int RED_LED = 12;
const unsigned int buttonPin = 2;

/* Variables - these will change */
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize LED outputs.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // initalise pushbutton ans an input
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // default state for lights
  digitalWrite(RED_LED, HIGH);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    traffic_sequence();
  } else {
    // turn LED off:
    
  }

}

void traffic_sequence(){

  activate_led(RED_LED,4000);
  activate_led(YELLOW_LED,2000);
  activate_led(GREEN_LED,2000);
  activate_led(YELLOW_LED,2000);
  
}

void activate_led(int thisLED, int delayTIME) {
  
  digitalWrite(thisLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTIME);                       // wait for a second
  digitalWrite(thisLED, LOW);    // turn the LED off by making the voltage LOW
   
}

