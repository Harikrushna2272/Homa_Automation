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

