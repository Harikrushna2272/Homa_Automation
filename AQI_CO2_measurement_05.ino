#include <Wire.h>
#include <LiquidCrystal_I2C.h>
delay(2000);
  lcd.clear();LiquidCrystal_I2C lcd(0x26, 16, 2); // Initialize the I2C display
MQ135 gasSensor(A0); // Initialize the MQ135 sensor

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init(); // Initialize the I2C display
  lcd.backlight(); // Turn on the backlight
}

void loop() {
  float co2 = gasSensor.getPPM(); // Read the CO2 value from the MQ135 sensor
  lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
  lcd.print("CO2 GAS: "); // Display the label
  lcd.print(co2); 
  lcd.print("PPM");
  Serial.println("co2");
  Serial.print(co2);
  delay(500);
}

/*
// Include the necessary libraries
#include <SoftwareSerial.h>

// Define the pins
#define SENSOR_PIN A0   // Analog input pin for sensor

// Define the CO2 threshold
#define CO2_THRESHOLD 1000   // Adjust this value according to your requirements

// Initialize the software serial for debugging (optional)
SoftwareSerial debugSerial(10, 11);  // RX, TX

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  debugSerial.begin(9600);
}

void loop() {
  // Read the sensor value
  int sensorValue = analogRead(SENSOR_PIN);
//  Serial.println(sensorValue);
  // Convert the sensor value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
//  Serial.println(voltage);
  // Calculate the CO2 concentration using a formula specific to the MQ-135 sensor
  float ppm = 500 * (voltage / 5.0 - 0.1);

  // Print the CO2 concentration
//  Serial.print("CO2 Level: ");
//  Serial.println(voltage);
  Serial.println(ppm);
//
  // Check if the CO2 level exceeds the threshold
  if (voltage > CO2_THRESHOLD) {
    // High CO2 level detected, take necessary actions
    Serial.println("High CO2 level detected!");

    // You can add your own code here to trigger alarms, send notifications, etc.

    // For debugging purposes (optional)
    debugSerial.println("High CO2 level detected!");
  }

  delay(2000);  // Delay between readings
}
*/
