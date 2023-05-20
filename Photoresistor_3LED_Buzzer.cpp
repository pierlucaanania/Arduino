int Photoresistor = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  Photoresistor = analogRead(A0);
  Serial.println(Photoresistor);
  if (Photoresistor >= 0 && Photoresistor < 450) {
    digitalWrite(9, HIGH);
    tone(6, 523, 1000); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(9, LOW);
    
  }
  if (Photoresistor >= 450 && Photoresistor < 850) {
    digitalWrite(11, HIGH);
    tone(6, 587, 1000); // play tone 60 (D5 = 523 Hz)
  } else {
    digitalWrite(11, LOW);
    
  }
  if (Photoresistor >= 850 && Photoresistor < 1024) {
    digitalWrite(10, HIGH);
    tone(6, 659, 1000); // play tone 60 (E5 = 523 Hz)
  } else {
    digitalWrite(10, LOW);
    
  }
  delay(10); // Delay a little bit to improve simulation performance
}
