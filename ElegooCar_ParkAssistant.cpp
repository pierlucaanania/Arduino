/// ELEGOO CAR PARK ASSISTAN WITH ULTRASOUND

#include <HCSR04.h>

// define IO pin
#define PWMA 5    // Controls power to right motor
#define PWMB 6    // Controls power to left motor
#define AIN 7     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define BIN 8     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY 3    // Place H-Bridge in standby if LOW, Run if HIGH
#define modeSwitch 2 // Mode Switch input

HCSR04 hc(13, 12); //initialisation class HCSR04 (trig pin , echo pin)


//init the car
void setup() {
  pinMode(PWMA, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(PWMB, OUTPUT);
  pinMode(BIN, OUTPUT);
  pinMode(AIN, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);  //Enable Motors to run
  analogWrite(PWMA, 150);  // Fully on 
  Serial.begin(9600);
 // digitalWrite(PWMA, HIGH);  // Fully on
}


// Functions 
// stopTime: accepts the time in milli-Seconds to go into standby for
void stopTime(int mS){
  digitalWrite(STBY, LOW);   // Go into standby
  delay(mS);                //  Wait defined time
  digitalWrite(STBY, HIGH);  //  Come out of standby
}

void ultrasound(){
  distance = hc.dist()
  Serial.println(hc.dist()); // return current distance in serial
  delay(200);

}

// Loop

void loop() {

  ultrasound(); // print Ultrasound measure
  
  //Go forward for 2 seconds
  
  // RIGHT WHEELS
  // Drive Right Wheels forward for 2 second  
  digitalWrite(AIN, HIGH);    // Forward direction
  analogWrite(PWMA, 150);   // Medium power [0,255]
  delay(1000);              //delay 
  
  // DRIVE LEFT WHEELS
  // Drive LEFT Wheels forward for 2 second  
  digitalWrite(BIN, HIGH);    // Forward direction
  analogWrite(PWMB, 150);   // Medium power
  delay(1000);              //delay 
  
  if (distance >= 30){
  // Drive Left Wheels Backwards for 2 second  
  digitalWrite(BIN, LOW);    // Forward direction
  analogWrite(PWMB, 150);   // Medium power
  delay(1000);              //
  
  
  
  // Drive Right Wheels Backwards for 2 second  
  digitalWrite(AIN, LOW);    // Backwards direction
  analogWrite(PWMA, 150);   // Medium power
  delay(1000);              //
  
  // Drive car Forward for 1 second
  digitalWrite(AIN, HIGH);    // Forward direction on Right
  digitalWrite(BIN, HIGH);    // Forward direction on Left
  analogWrite(PWMA, 100);   // Power on Right
  analogWrite(PWMB, 100);   // Power on Left
  delay(1000);  
  }
}
