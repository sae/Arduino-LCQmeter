//SAE RC-meter
//started from http://arduino.cc/en/Tutorial/CapacitanceMeter
//- remove discharge pin

#define analogPin      1          // analog pin for measuring capacitor voltage
#define chargePin      8         // pin to charge the capacitor - connected to one end of the charging resistor
//#define dischargePin   11         // pin to discharge the capacitor
#define led13 13 //led pin
#define resistorValue  10000.0F   // change this to whatever resistor value you are using
                                  // F formatter tells compliler it's a floating point value

unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                // floating point variable to preserve precision, make calculations
float nanoFarads;

void setup(){
  pinMode(chargePin, OUTPUT);     // set chargePin to output
  pinMode(led13, OUTPUT);
  digitalWrite(chargePin, LOW);  

  Serial.begin(9600);             // initialize serial transmission for debugging
}

void loop(){
  digitalWrite(led13, HIGH); 
  digitalWrite(chargePin, HIGH);  // set chargePin HIGH and capacitor charging
  startTime = millis();

  while(analogRead(analogPin) < 648){       // 647 is 63.2% of 1023, which corresponds to full-scale voltage 
  }
  digitalWrite(led13, LOW); 
  /* dicharge the capacitor  */
  digitalWrite(chargePin, LOW);             // set charge pin to  LOW 
  //pinMode(dischargePin, OUTPUT);            // set discharge pin to output 
  //digitalWrite(dischargePin, LOW);          // set discharge pin LOW 

  elapsedTime= millis() - startTime;
 // convert milliseconds to seconds ( 10^-3 ) and Farads to microFarads ( 10^6 ),  net 10^3 (1000)  
  microFarads = ((float)elapsedTime / resistorValue) * 1000;   
  Serial.print(elapsedTime);       // print the value to serial port
  Serial.print(" mS    ");         // print units and carriage return


  if (microFarads > 1){
    Serial.print((long)microFarads);       // print the value to serial port
    Serial.println(" microFarads");         // print units and carriage return
  }
  else
  {
    // if value is smaller than one microFarad, convert to nanoFarads (10^-9 Farad). 
    // This is  a workaround because Serial.print will not print floats

    nanoFarads = microFarads * 1000.0;      // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
    Serial.print((long)nanoFarads);         // print the value to serial port
    Serial.println(" nanoFarads");          // print units and carriage return
  }

  while(analogRead(analogPin) > 0){         // wait until capacitor is completely discharged
  }

  //pinMode(dischargePin, INPUT);            // set discharge pin back to input
  delay (1000);//sleep for 1 sec
} 
