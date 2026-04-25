#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// I2C address is usually 0x27. For 16 chars and 2 lines.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); // Start top-left
  lcd.print("Hello ADEOYE");
}

void loop() {
  // Static message, so loop is empty
}
