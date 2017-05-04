// https://github.com/markruys/arduino-Max72xxPanel
/* THis works with 1X4 Module
 *  Download the library zip files and Add Zip file
 */
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

/*   PIN Connections
 * _______|_______________|____
 * | VCC  |               | +5V
 * | CLK  | -CLOCK        | 13
 * | CE   |- CE /CS       | 10
 * | MOSI | - Data Input  | 11
 * | GND  |               | GND
 */

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )

int numberOfHorizontalDisplays = 1; // Horizontal
int numberOfVerticalDisplays = 1; // Vertical

// Set up the panel
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);


String tape = "DESIGN team"; // the string or message
int wait = 100; // the Scrolling speed in milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels


// can I draw a hearst with GFX?
/*byte array for heart
 * 
 */
static uint8_t heart[8] = {0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00};
/*byte array for face
 * 
 */
static uint8_t face[8] = {0x3C, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C};

void setup() {

  Serial.begin(9600); // for debugging

  matrix.setIntensity(1); // Use a value between 0 and 15 for brightness

// Adjust to your own needs
//  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
//  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
//  matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
//  matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>
//  ...
  matrix.setRotation(0, 1);    // The first display is position upside down
  matrix.setRotation(1, 1);    // The same hold for the last display
  matrix.setRotation(2, 1);    // The first display is position upside down
  matrix.setRotation(3, 1);    // The same hold for the last display
}

void loop() {
  ticker();
  drawHeart();  
  drawFace();
  moveHeart();
}

/*
 * Use http://www.binaryhexconverter.com/binary-to-hex-converter 
 * to convert binary 0 and 1 to hex
 */

// draw symbol of heart wuth a byte array
void drawHeart() {
  // methods from Adafruit_GFX
   
   matrix.drawBitmap(0, 0, heart, 8, 8, true);
   matrix.write(); // Send bitmap to display
    
   delay(2000);
   // turn all pixels off (takes effect after led->flush())
   matrix.fillScreen(false);

}



// draw symbol of face with a byte array
void drawFace() {
  // methods from Adafruit_GFX
   
   matrix.drawBitmap(0, 0, face, 8, 8, true);
   matrix.write(); // Send bitmap to display
    
   delay(2000);
   // turn all pixels off (takes effect after led->flush())
   matrix.fillScreen(false);

}
/* To animate, draw the bitmap in the first position
 *  draw another behind or following it offset to the width + a spacer
 *  write to the screen
 */

void moveHeart(){
         
         for(int x=0; x<=8; x++){
           matrix.fillScreen(LOW);
           Serial.println(x); // for debugging position of x
           
            matrix.drawBitmap(x, 0, heart, 8, 8, true); // leading image
            
            matrix.drawBitmap(x-9, 0, heart, 8, 8, true); // trailing image
            matrix.write(); // Send bitmap to display
        
           delay(100);
         }
         

   }

/*A ticker ot text across the display
 * 
 */

void ticker(){

  String tape = "The Message "; // the string or message
  
  for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ ) {

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < tape.length() ) {
        matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(wait);
  }
}
