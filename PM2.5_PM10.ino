// #include <Wire.h>
#include <LiquidCrystal.h>
#include <MQ135.h>

LiquidCrystal lcd2(2, 3, 4, 5, 6, 7); // I2C address and dimensions of LCD

// define the pin numbers for the IR LED and analog input
const int IR_PIN = 8;
const int ANALOG_PIN = A0;
MQ135 gasSensor(A1); // Initialize the MQ135 sensor
// define the parameters for calculating PM2.5 concentration
const float K = 0.55;    // calibration factor

void setup() {
  Serial.begin(9600);
  lcd2.begin(16,2);
  // configure the IR LED pin as an output
  pinMode(IR_PIN, OUTPUT);
  // initialize the IR LED pin to be off
  digitalWrite(IR_PIN, HIGH);
  // initialize the serial port
  
}

void loop() {
  // turn on the IR LED by setting the pin to LOW
  digitalWrite(IR_PIN, LOW);
  // wait for 0.32 milliseconds (or adjust as necessary for your specific sensor)
  delayMicroseconds(320);
  // read the analog input value
  int analogValue = analogRead(ANALOG_PIN);
  // turn off the IR LED by setting the pin to HIGH
  digitalWrite(IR_PIN, HIGH);
  
  // convert the analog value to a voltage
  float voltage = analogValue * 5.0 / 1024.0;
  // calculate the dust concentration in ug/m3
  float concentration = K * (voltage - 0.1);
  
  float pm25 = concentration * 0.5;
  float pm10 = concentration * (1/0.5);
 
  lcd2.setCursor(0,0);
  lcd2.print("PM2.5:");
  lcd2.print(pm25);
  lcd2.print(" ug/m3");
 delay(2000);
  lcd2.clear();
  lcd2.setCursor(0,0);
  lcd2.print("PM10: ");
  lcd2.print(pm10);
  lcd2.print(" ug/m3");
  digitalWrite(4, HIGH);
  delay(2000);
  lcd2.clear();
//
 float co2 = gasSensor.getPPM(); // Read the CO2 value from the MQ135 sensor
 lcd2.setCursor(0, 0); // Set the cursor to the first column of the first row
 lcd2.print("CO2 GAS: "); // Display the label
 lcd2.print(co2); 
 lcd2.print("PPM");
 delay(2000);
  
  Serial.print("PM2.5: ");
  Serial.print(pm25);
  Serial.print(" ug/m3");
  Serial.print("\t");

  Serial.print("PM10: ");
  Serial.print(pm10);
  Serial.print(" ug/m3");
  Serial.println();
  delay(1000);
  
}
