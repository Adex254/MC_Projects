#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

// Using 0x27 because it worked in your Scanner code
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int IR_RECEIVE_PIN = 15;
const int buzzerPin = 19;

void setup() {
  // Setup the LCD exactly like the Scanner
  lcd.init();
  lcd.backlight();
  
  pinMode(buzzerPin, OUTPUT);
  
  // Beep once to confirm the code is running
  digitalWrite(buzzerPin, HIGH);
  delay(200);
  digitalWrite(buzzerPin, LOW);

  // Start the IR Receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  lcd.setCursor(0, 0);
  lcd.print("ADEOYE GAME");
  lcd.setCursor(0, 1);
  lcd.print("READY...");
}

void loop() {
  if (IrReceiver.decode()) {
    // Get the hex code
    uint32_t received = IrReceiver.decodedIRData.decodedRawData;

    // Beep briefly
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);

    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("REMOTE CODE:");
    lcd.setCursor(0, 1);
    lcd.print(received, HEX);

    // Resume for next press
    IrReceiver.resume();
  }
}
