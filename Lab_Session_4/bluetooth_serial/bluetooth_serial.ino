#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);
int stat = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Hello!");

  BTSerial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available()){
    if(stat==1){
      Serial.write(BTSerial.read());
    }else{
      Serial.println();
      Serial.print("Other : ");
      Serial.write(BTSerial.read());
      stat=1;
    }
  }else if(Serial.available()){
    char toSend = Serial.read();
    if(toSend!='\n'){
      if(stat==-1){
        BTSerial.write(toSend);
        Serial.write(toSend);
      }else{
        Serial.println();
        Serial.print("Me : ");
        BTSerial.write(toSend);
        Serial.write(toSend);
        stat=-1;
      }
    }
  } else {
  }
}
