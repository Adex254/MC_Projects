#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

// If your screen stays blank after this, change 0x27 to 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int IR_RECEIVE_PIN = 15;
const int buzzerPin = 19;

void setup() {
  // Forces the ESP32 to use the correct I2C pins
  Wire.begin(21, 22); 
  
  lcd.init();
  lcd.backlight();
  
  pinMode(buzzerPin, OUTPUT);
  
  // STARTUP BEEP: If you don't hear this, the flash failed
  digitalWrite(buzzerPin, HIGH);
  delay(300);
  digitalWrite(buzzerPin, LOW);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  lcd.setCursor(0, 0);
  lcd.print("IR TEST READY");
}

void loop() {
  if (IrReceiver.decode()) {
    // Beep when you press a remote button
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);

    uint32_t received = IrReceiver.decodedIRData.decodedRawData;
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HEX CODE:");
    lcd.setCursor(0, 1);
    lcd.print(received, HEX);
    
    IrReceiver.resume();
  }
}
