#include <virtuabotixRTC.h>

/*  Using DS1302
 * https://www.virtuabotix.com/virtuabotix-ds1302-real-time-clock-module-pin-out-coding-guide/?v=a284e24d5f46
 * VCC - +v
 * GND -GND
 * CLK - Pin 6
 * DAT - i/o 7
 * RST - CE Pin 8
 */


// Creation of the Real Time Clock Object
//SCLK -> 6, I/O -> 7, CE -> 8
virtuabotixRTC myRTC(6, 7, 8);

void setup() {
Serial.begin(9600);

// Set the current date, and time in the following format:
// seconds, minutes, hours, day of the week, day of the month, month, year
myRTC.setDS1302Time(00, 59, 23, 6, 10, 1, 2017);
}

void loop() {
// This allows for the update of variables for time or accessing the individual elements.
myRTC.updateTime();

// Start printing elements as individuals
Serial.print("Current Date / Time: ");
Serial.print(myRTC.dayofmonth);
Serial.print("/");
Serial.print(myRTC.month);
Serial.print("/");
Serial.print(myRTC.year);
Serial.print(" ");
Serial.print(myRTC.hours);
Serial.print(":");
Serial.print(myRTC.minutes);
Serial.print(":");
Serial.println(myRTC.seconds);

// Delay so the program doesn't print non-stop
delay( 5000);
}
