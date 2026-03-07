int LDR_PIN = 34;
int LED_PIN = 5;

const int ON_THRESHOLD = 2500;
const int OFF_THRESHOLD = 1500;

void setup() {
  Serial.begin(115200);
  Serial.println("LDR Test Starting...");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(LDR_PIN);
  Serial.print("Light Level: ");
  Serial.println(value);
  
  if (value > ON_THRESHOLD) {
    int brightness = map(value, 2500, 4095, 0, 255);
    brightness = constrain(brightness, 0, 255);

    analogWrite(LED_PIN, brightness);
  }

  if (value < OFF_THRESHOLD) {
    analogWrite(LED_PIN, 0);
  }
  
  delay(50);
}
