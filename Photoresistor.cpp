int Photoresistor = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  Photoresistor = analogRead(A0);
  Serial.println(Photoresistor);
  if (Photoresistor < 450) {
    analogWrite(11, 255);
  } else {
    analogWrite(11, 0);
  }
  if (Photoresistor >= 450 && Photoresistor < 850) {
    analogWrite(10, 255);
  } else {
    analogWrite(10, 0);
  }
  if (Photoresistor >= 850 && Photoresistor < 1024) {
    analogWrite(9, 255);
  } else {
    analogWrite(9, 0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
