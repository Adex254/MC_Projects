#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set address to 0x27 or 0x3F for a 16x2 I2C display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); // Start top-left
  lcd.print("Hello ADEOYE");
}

void loop() {
  // Static message, loop is empty
}
