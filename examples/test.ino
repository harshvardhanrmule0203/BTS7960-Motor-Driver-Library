#include "BTS7960.h"

#define lpwm 10
#define rpwm 11
#define renb 8
#define lenb 9
char data;

BTS7960 motor(lpwm, rpwm); // use when enable are provided with 5V external
BTS7960 motor(lpwm, rpwm, lenb, renb); // use when enalbe are not provided with 5V external

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setEnable(false);   // use when enalbe are provided with 5V external
  motor.setEnable(true);   // use when enalbe are not provided with 5V external
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      data = Serial.read();
  }

  if(data == '1'){
      motor.rotate(30);
      Serial.println("Fwd");
  }
  else if(data == '2'){
      motor.rotate(-30);
      Serial.println("Rev");
  }
  else{
      motor.stop();
  }
}
