#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");

  BTSerial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available()){
      Serial.print("BTSerial available : ");
      Serial.write(BTSerial.read());
      Serial.println();
  }
  if(Serial.available()){
    char toSend = Serial.read();
    if(toSend!='\n'){
          BTSerial.write(toSend);
          Serial.print("Serial available : ");
          Serial.println(toSend);
    }
  }
}
