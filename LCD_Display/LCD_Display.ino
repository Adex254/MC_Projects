#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

void setup() {
  Wire.begin(21, 22);
  lcd.begin(16, 2);
  lcd.print("Your OTP is:");
  lcd.setCursor(0, 1);
  lcd.print("Hello Adeoye");
}

void loop() {}
