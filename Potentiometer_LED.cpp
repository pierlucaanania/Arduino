void setup()
{
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(6, map(analogRead(A0), 0, 1023, 0, 255));
  analogWrite(5, map(analogRead(A0), 0, 1023, 0, 255));
  analogWrite(9, map(analogRead(A0), 0, 1023, 0, 255));
  Serial.println(map(analogRead(A0), 0, 1023, 0, 255));
  delay(10); // Delay a little bit to improve simulation performance
}
