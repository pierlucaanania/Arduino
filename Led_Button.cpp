int Button = 0;

void setup()
{
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  Button = digitalRead(11);
  if (Button == HIGH) {
    analogWrite(10, 255);
  } else {
    analogWrite(10, 0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
