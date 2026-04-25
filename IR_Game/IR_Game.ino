#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int IR_RECEIVE_PIN = 15;
const int buzzerPin = 19;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  lcd.setCursor(0, 0);
  lcd.print("GAME READY");
}

void loop() {
  if (IrReceiver.decode()) {
    // Just a simple test: beep when any button is pressed
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Code: ");
    lcd.print(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    IrReceiver.resume();
  }
}
