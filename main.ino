int LDR_PIN = 34;
int LED_PIN = 5;

void setup() {
  Serial.begin(115200);
  Serial.println("LDR Test Starting...");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(LDR_PIN);
  Serial.print("Light Level: ");
  Serial.println(value);
  delay(500);

  if (value > 2000) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
