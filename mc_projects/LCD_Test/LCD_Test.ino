#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Try 0x27 first. If it stays as blocks, change this to 0x3F and re-flash.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(); 
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Hello,");
  lcd.setCursor(0, 1);
  lcd.print("Adeoye"); // Using your name from the project logs
}

void loop() {
  // Nothing here, just keeping the name on the screen
}
