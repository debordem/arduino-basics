/*
First Flashing Lights sketch
*/

const unsigned int GREEN_LED = 12;
const unsigned int YELLOW_LED = 11;
const unsigned int RED_LED = 10;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
 
}



// the loop function runs over and over again forever
void loop() {

  flash_function(GREEN_LED,1000);                      // wait for a second
  flash_function(YELLOW_LED,1000); 
  flash_function(GREEN_LED,1000); 

  
  
}

void flash_function( int led, int t_delay)
{
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t_delay);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(t_delay);                       // wait for a second

}



