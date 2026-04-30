#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 4       // Connection for the 'out' pin on your sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp System");
  delay(2000);
  lcd.clear();
}

void loop() {
  float tempC = dht.readTemperature();
  
  if (isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error  ");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C  "); 

  lcd.setCursor(0, 1);
  if(tempC > 30) {
    lcd.print("Status: Warm   ");
  } else {
    lcd.print("Status: Normal ");
  }

  delay(2000); 
}
