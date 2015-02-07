//
//ultra-easy C-meter for small-caps (10-1000 pF?)
//no scheme at all! just put cap between pins
//http://wordpress.codewrite.co.uk/pic/2014/01/21/cap-meter-with-arduino-uno/
//
const int OUT_PIN = A2;
const int IN_PIN = A0;

//Capacitance between IN_PIN and Ground
//Stray capacitance is always present. Extra capacitance can be added to
//allow higher capacitance to be measured.
const float IN_STRAY_CAP_TO_GND = 24.48; //initially this was 30.00
const float IN_EXTRA_CAP_TO_GND = 0.0;
const float IN_CAP_TO_GND  = IN_STRAY_CAP_TO_GND + IN_EXTRA_CAP_TO_GND;
const int MAX_ADC_VALUE = 1023;

void setup()
{
  pinMode(OUT_PIN, OUTPUT);
  //digitalWrite(OUT_PIN, LOW);  //This is the default state for outputs
  pinMode(IN_PIN, OUTPUT);
  //digitalWrite(IN_PIN, LOW);

  Serial.begin(115200);
}

void loop()
{
  //Capacitor under test between OUT_PIN and IN_PIN
  //Rising high edge on OUT_PIN
  pinMode(IN_PIN, INPUT);
  digitalWrite(OUT_PIN, HIGH);
  int val = analogRead(IN_PIN);

  //Clear everything for next measurement
  digitalWrite(OUT_PIN, LOW);
  pinMode(IN_PIN, OUTPUT);

  //Calculate and print result

  float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);

  Serial.print(F("Capacitance Value = "));
  Serial.print(capacitance, 3);
  Serial.print(F(" pF ("));
  Serial.print(val);
  Serial.println(F(") "));

  while (millis() % 500 != 0)
    ;    
}
