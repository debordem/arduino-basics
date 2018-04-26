/*  Improved* Thermistor program
 *
 *  from https://learn.adafruit.com/thermistor/using-a-thermistor
 *
 *  Uses the ARef to set the analog reference to the voltage,
 *  so 5v and 3.3v work the same with 1023 bring the ADC value
 *
 */

// which analog pin to connect
int ThermistorPin = A1;

// Input voltage
float Vo;

// the value of the 'other' resistor
float SERIESRESISTOR = 120;

// Calculated voltage
float R2;

// resistance at 25 degrees C
#define THERMISTORNOMINAL 10

// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25

// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950

void setup() {
Serial.begin(9600);

}

void loop() {
  // Read the input voltage
  Vo = analogRead(ThermistorPin);
  Serial.print("Input Voltage ");
  Serial.println(Vo);

  // Calculate the value of the thermistors resistance
  R2 = (1023 / Vo)  - 1;     // (1023/ADC - 1)
  R2 = SERIESRESISTOR / R2;  // 10K / (1023/ADC - 1)
  Serial.print("Thermistor resistance ");
  Serial.println(R2);

  // Use the Steinhart-HArt equation to calculate temperature
  float steinhart;
  steinhart = R2 / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C

  // Print put the output to the serial monitor
  Serial.print("Temperature ");
  Serial.print(steinhart);
  Serial.println(" *C");
  delay(1000);
}
