//SAE RC-meter
//can measure from 1 nanoFarad
//internal capacity + timing = 0.38nF
//
//use internal comparator and interrupt
//http://www.leonardomiliani.com/2012/analogcomp-una-libreria-per-gestire-il-comparatore-analogico/?lang=en
//
//you need to connect charge pin via resistor 10K 
//to capacity then to groung
//AIN0 (pin D6 on UNO) connect to capacity and resistor
//analog A1 also conected to AIN0
//AIN1 (pin D7) connected to ref 3.3V

#include "analogComp.h"

#define analogPin      1          // analog pin for measuring capacitor voltage
#define chargePin      8         // pin to charge the capacitor - connected to one end of the charging resistor
#define led13 13 //led pin
#define resistorValue  10000.0F   // change this to whatever resistor value you are using
                                  // F formatter tells compliler it's a floating point value

unsigned long t0;//start time
unsigned long t1;//interrupt time
unsigned long elapsedTime;
float microFarads;                // floating point variable to preserve precision, make calculations
float nanoFarads;

void setup() {
  
  pinMode(chargePin, OUTPUT);     // set chargePin to output
  //pinMode(led13, OUTPUT);
  digitalWrite(chargePin, LOW);  
  while(analogRead(analogPin) > 0){         // wait until capacitor is completely discharged
  }
  Serial.begin(9600);             // initialize serial transmission for debugging

  //AIN1 connected to pin 3.3V
  analogComparator.setOn(AIN0, AIN1);//D6+,D7- 
}

void loop(){

  if (t0==0) { //if reay to start 
    analogComparator.enableInterrupt(comparatorInt,RISING); //RISING FALLING, CHANGE
    digitalWrite(chargePin, HIGH);  
    t0= micros();//  startTime;
  }
  
  //if no interrupt occured, wait
  if(t1<=t0) {
    delay(1000);
    return; 
  }
  
  analogComparator.disableInterrupt();
  //we have time from interrupt, calculate now
  elapsedTime=t1-t0;
 // convert microseconds to seconds ( 10^-6 ) and Farads to microFarads ( 10^6 ),  
  //63% from 5v is 3.15V, but reference is 3.3V
  //so we decrease elapsed time by 5%
  microFarads = ((float)elapsedTime*0.95 / resistorValue);// * 1000;   
  Serial.print(elapsedTime);       // print the value to serial port
  Serial.print(" mkS    ");         // print units and carriage return

  if (microFarads > 1){
    Serial.print(microFarads);       // print the value to serial port
    Serial.println(" mkF");         // print units and carriage return
  }
  else
  {
    // if value is smaller than one microFarad, convert to nanoFarads

    nanoFarads = microFarads * 1000.0;      // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
    Serial.print(nanoFarads);         // print the value to serial port
    Serial.println(" nF");          // print units and carriage return
  }

  digitalWrite(chargePin, LOW);//discharge  
  while(analogRead(analogPin) > 0){         // wait until capacitor is completely discharged
  }
  t0=0;//reset t0 - ready for next calulation
  
  delay (1000);//sleep for 1 sec
} 

void comparatorInt() {
  t1=micros();//set new time
}
