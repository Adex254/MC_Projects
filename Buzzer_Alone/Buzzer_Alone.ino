const int buzzerPin = 13; // Set to your GPIO pin

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  delay(100); 
  digitalWrite(buzzerPin, LOW);
  delay(1900); // 2 second total cycle
}
