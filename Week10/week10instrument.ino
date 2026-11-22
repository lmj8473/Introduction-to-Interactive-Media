
#include "pitches.h"

const int trigPin = A0;
const int echoPin = 2;
const int switchPin = 4;
const int buzzerPin = 9;

const int maxDistance = 40;

int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {

  // MEASURING DISTANCE
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.println(distance);

  int switchState = digitalRead(switchPin);

  // CHANGE THE NOTE DEPENDING ON THE DISTANCE
  int noteIndex = -1;

  if (distance <= maxDistance) {

    if (distance < 5) {
      noteIndex = 0;
    }
    else if (distance < 10) {
      noteIndex = 1;
    }
    else if (distance < 15) {
      noteIndex = 2;
    }
    else if (distance < 20) {
      noteIndex = 3;
    }
    else if (distance < 25) {
      noteIndex = 4;
    }
    else if (distance < 30) {
      noteIndex = 5;
    }
    else if (distance < 35) {
      noteIndex = 6;
    }
    else {
      noteIndex = 7;
    }
  }

  // PLAY THE MELODY IF THE SWITCH IS ON. IF SWITCH IS PRESSED ACT AS A MUSIC REST(PAUSE)
  if (switchState == HIGH && noteIndex != -1) {
    tone(buzzerPin, melody[noteIndex]);
  }
  else {
    noTone(buzzerPin);
  }

  delay(100);
}
