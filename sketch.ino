#include <Servo.h>
#define PIN_TRIG 12
#define PIN_ECHO 11
Servo arm;
int pos = 0;
int distance = 5000;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  arm.attach(9);
  arm.write(pos);
}

void loop()
{
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  int distance = pulseIn(PIN_ECHO, HIGH)/58;
  if (distance < 100)  {
    pos = 90;
    arm.write(pos);
    delay(5000);
    pos = 0;
    arm.write(pos);
  }
}


