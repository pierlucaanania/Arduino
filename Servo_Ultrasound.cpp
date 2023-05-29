#include <Servo.h>
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

long a;
int potenziometro = 0;

Servo servo_3;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  servo_3.attach(3, 500, 2500);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  delay(10);
}

void loop()
{
  potenziometro = analogRead(A0);
  Serial.println("Resistance value: ");
  Serial.println(potenziometro);
  digitalWrite(5,HIGH);
  if (potenziometro <= 500) {
    digitalWrite(6, HIGH);
    servo_3.write(90);
  } else {
    digitalWrite(6, LOW);
    servo_3.write(180);
  }
  if (potenziometro <= 500) {
    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);
  }
  if (a < 100) {
    digitalWrite(2,HIGH);
  } else {
    digitalWrite(2,LOW);
  }
  delay(100); // Delay a little bit to improve simulation performance
  a=sr04.Distance();
  Serial.println("Distance value: ");
  Serial.print(a);
  Serial.println("cm");
  delay(100);
}
