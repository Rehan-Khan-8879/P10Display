#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD. Replace '0x27' with the I2C address of your module if different.
LiquidCrystal_I2C lcd(0x27, 20, 4); // 20x4 LCD, I2C address is typically 0x27 or 0x3F

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight
  lcd.setCursor(0, 0); // Set cursor to column 0, row 0
  lcd.print("Hello, World!");
  
  lcd.setCursor(0, 1); // Set cursor to column 0, row 1
  lcd.print("4x20 LCD Display");

  lcd.setCursor(0, 2); // Set cursor to column 0, row 2
  lcd.print("Using I2C Module");

  lcd.setCursor(0, 3); // Set cursor to column 0, row 3
  lcd.print("Arduino Uno");
}

void loop() {
  // Your code here
}