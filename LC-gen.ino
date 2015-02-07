/*
simplest LC-generator on arduino
can be used as lc-meter
(C)SAE762 07.feb.2015 @home

circuit diagramm will be placed here:


useful lc-calculators:
http://tel-spb.ru/lc.html  
 */

#include "analogComp.h"

#define ctl 12
#define led 13

int rise=0;
int fall=0;

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ctl, OUTPUT);
  digitalWrite(ctl, LOW);
  analogComparator.setOn(AIN0, AIN1);//D6+,D7- 
  analogComparator.enableInterrupt(comparatorInt,CHANGE);
}

void loop() {
  digitalWrite(led, HIGH);   
  rise=0;
  fall=0;
  delay(1000);              // wait for a second
  Serial.print(rise);
  Serial.print(";");
  Serial.print(fall);
  Serial.println(" pulses/sec");
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //if no pulses, make a start impulse
  if (rise==0) {
   digitalWrite(ctl, HIGH);
   rise++;//make something useless )
   digitalWrite(ctl, LOW);
  }
 delay(1000);              // wait for a second
}
