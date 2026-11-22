const int LED_PIN = 5;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    int brightness = data.toInt();

    brightness = constrain(brightness, 0, 255);

    analogWrite(LED_PIN,255- brightness);
  }
}