
const int trigPin = A1;
const int echoPin = 2;
const int LED_PIN = 5;

unsigned long ledOnTime = 0;
bool ledOn = false;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, HIGH);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration > 0) {
    float distance = duration * 0.0343 / 2;
    Serial.println(distance);
  }

  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    if (data.toInt() == 1) {
      digitalWrite(LED_PIN, LOW);
      ledOn = true;
      ledOnTime = millis();
    }
  }
  if (ledOn && millis() - ledOnTime >= 200) {
    digitalWrite(LED_PIN, HIGH);
    ledOn = false;
  }

  delay(50);
}
