
/* 4x4  MAtrix Keyboard
 *  from the website : http://www.learningaboutelectronics.com/Articles/Arduino-keypad-circuit.php
 * 
 *  install the library from Sketch->Include Library->Manage Libraries... Then search for Keypad.
 */

 /*
  *  Buzzer / tones tutorial
  *  https://programmingelectronics.com/an-easy-way-to-make-noise-with-arduino-using-tone/
  */

#include <Key.h>
#include <Keypad.h>

// the spec of the keypad
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

/// tones

//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int buzzerPin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)
{
  Serial.print(keypressed);


  // switch statement gives you the oprion to ouptout a different tone for each key
  switch(keypressed) {
      case '#':
      tone(buzzerPin, 4000, 100);
      break;
      
      default:
       tone(buzzerPin, 2000, 100);
      break;
    }


 
}
}
