
int redLED = 12;
int yellowLED = 11;
int greenLED = 10;

int delayTime = 10;
int pushButton =2;

int switchState;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  pinMode(pushButton, INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  
  switchState = digitalRead(pushButton);
  if (switchState == LOW)
    { delayTime = 100;}
  else
    { delayTime = 1000;}
  
  ledFlash(redLED);
  ledFlash(yellowLED);
  ledFlash(greenLED);
  
}

// Will flash an LED //
void ledFlash(int led)
{
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second
 
}


