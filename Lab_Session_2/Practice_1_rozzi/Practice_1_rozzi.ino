#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int sensorPin = 10;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorVal =0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(sensorPin, INPUT);
//  Serial.begin (9600);
  Serial.begin(115200);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin, HIGH);
    sensorVal = digitalRead(sensorPin);
    if (sensorVal == HIGH) 
    {     
      delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      Serial.print("Ping: ");
      Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
      Serial.println(" cm");
//      digitalWrite(ledPin, HIGH);  
    } 
    else {
      Serial.println("no person");
//      digitalWrite(ledPin, LOW); 
    }
//    Serial.println(sensorVal);
    delay(200);
    
  }
}
