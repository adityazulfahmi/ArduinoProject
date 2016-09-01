#include <NewPing.h>
#include <dht11.h>

const int buttonPin = 2;
const int infraPin = 10;
const int ledPin =  13; 
const int triggerPin =  12;  
const int echoPin = 11;
const int maxDistance = 200;

// variables will change:
int buttonState = 0;
int personState = 0;

NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);


  if (buttonState == LOW) {
    personState=digitalRead(infraPin);
    if(personState == HIGH){
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      Serial.print("Ping: ");
      Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
      Serial.println("cm");
    }else{
      Serial.println("no person");
    }
  } else {
    digitalWrite(ledPin, HIGH);
  }
  delay(200);
}
