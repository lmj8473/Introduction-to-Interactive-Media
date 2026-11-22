int trigPin = A1;
int echoPin = 2;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration > 0) {
    // Calculate distance in cm
    float distance = duration * 0.0343 / 2;

    Serial.println(distance);
  }

  delay(100);
}