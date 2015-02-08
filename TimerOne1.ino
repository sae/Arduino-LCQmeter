/**
simplest pwm-generator
using TimerOne library
set frequency and duty in setup
interrupt code just for sample
*/

#include <TimerOne.h>

void setup() 
{
  // Initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  pinMode(13, OUTPUT);    
  Timer1.initialize(1000);//1000000ms=1s);
//  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
//  Timer1.pwm(9, 512, 100);//10kHz
  Timer1.pwm(9, 500);  //pin D9, 500/1024 - duty 
}
 
void loop()
{
  // Main code loop
  // TODO: Put your regular (non-ISR) logic here
}
 
/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------
void timerIsr()
{
    // Toggle LED
    digitalWrite( 13, digitalRead( 13 ) ^ 1 );
}
