#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Standard address is 0x27. If it stays as blocks, change to 0x3F.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Forces I2C to start on the correct ESP32 pins
  Wire.begin(21, 22); 
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("LCD Test");
  
  lcd.setCursor(0, 1);
  lcd.print("Adeoye"); 
}

void loop() {
  // Heartbeat: Blink the backlight so we know the code is running
  lcd.backlight();
  delay(1000);
  lcd.noBacklight();
  delay(1000);
}
