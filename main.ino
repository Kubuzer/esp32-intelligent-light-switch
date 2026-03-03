int LDR_PIN = 34;

void setup() {
  Serial.begin(115200);
  Serial.println("LDR Test Starting...");
}

void loop() {
  int value = analogRead(LDR_PIN);
  Serial.print("Light Level: ");
  Serial.println(value);
  delay(500);
}
