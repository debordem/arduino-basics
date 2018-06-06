/* Simple sketch to demonstrate counting up to 100 
 *  on the clock face module
*/
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   100

TM1637Display display(CLK, DIO);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  display.setBrightness(0);

  for(int number = 200; number <= 500; number++) {
   display.showNumberDecEx(number,64,true);
   delay(TEST_DELAY);
    display.showNumberDecEx(number,128,true);
    delay(TEST_DELAY);
  }


  
  
}
