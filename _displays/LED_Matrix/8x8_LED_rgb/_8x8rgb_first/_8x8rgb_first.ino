// http://wiki.52pi.com/index.php/RPI-RGB-LED-Matrix_SKU:EP-0075#How_to_use_it

/*  LED MATRIX V1.0
 * VCC  +5V
 * CLK  -CLOCK - 13
 * CE - Chip Enable/Chip Select -10
 * MOSI - Data Input - 12
 * GND GND
 */


#include <SPI.h>

static uint8_t data[4] = {0x0, 0x0, 0x0, 0x0};
static uint8_t i = 1;
const int CE = 10;

#define RED_DATA 0
#define BLUE_DATA 1
#define GREEN_DATA 2
#define OFFSET 3

void heartbig()
{
  int j;
  int x = 2;
  static uint8_t heart[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

 
  for ( j = 0; j < 8; j++)
  {
    data[RED_DATA] = 0xFF; // RED Pixel data
    data[BLUE_DATA] = ~heart[j]; // GREEN Pixel data
    data[GREEN_DATA] = 0xFF; // BLUE Pixel data
    data[OFFSET] = 0x01 << j ; // vertical position

    digitalWrite(CE, LOW);
    
    SPI.transfer(data[RED_DATA]);
    SPI.transfer(data[BLUE_DATA]);
    SPI.transfer(data[GREEN_DATA]);
    SPI.transfer(data[OFFSET]);
    
    digitalWrite(CE, HIGH);

    

    
    delay(x);

  }
};

void heartsmall()
{
  int j;
  int x = 2;
  static uint8_t heart[8] = {0x00, 0x00, 0x24, 0x7E, 0x7E, 0x3C, 0x18, 0x00};
  for ( j = 0; j < 8; j++)
  {
    data[0] = ~heart[j];
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0x01 << j ;
    digitalWrite(CE, LOW);
    SPI.transfer(data[0]);
    SPI.transfer(data[1]);
    SPI.transfer(data[2]);
    SPI.transfer(data[3]);
    digitalWrite(CE, HIGH);
    delay(x);
  }
};

void matrixoff()
{
  int j;
  int x = 2;
  static uint8_t heart[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  for ( j = 0; j < 8; j++)
  {
    data[0] = ~heart[j];
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0x01 << j ;
    digitalWrite(CE, LOW);
    SPI.transfer(data[0]);
    SPI.transfer(data[1]);
    SPI.transfer(data[2]);
    SPI.transfer(data[3]);
    digitalWrite(CE, HIGH);
    delay(x);
  }
};

void setup() {
  pinMode(CE, OUTPUT);
  SPI.begin();
}

void loop()
{
  int m = 10;
  for ( m = 20; m > 0; m--) {
    heartbig();
  };
  matrixoff();
 delay(500);
 for ( m = 10; m > 0; m--) {
    heartsmall();
  };
  matrixoff();
  delay(500);
}
