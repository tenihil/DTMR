
// Analog in port definition for each piezo drum pad
const int padLL = A0;
const int padRL = A1;
const int padLH = A2;
const int padMH = A3;
const int padRH = A4;

// Threshold value of piezo analog input
const int thrLL = 250;
const int thrRL = 250;
const int thrLH = 100;
const int thrMH = 100;
const int thrRH = 100;

// ADC values read from ports
int sensorValueLL = 0;        
int sensorValueRL = 0;   
int sensorValueLH = 0;   
int sensorValueMH = 0;   
int sensorValueRH = 0;   

int sensorValueTempLL = 0;        
int sensorValueTempRL = 0;   
int sensorValueTempLH = 0;   
int sensorValueTempMH = 0;   
int sensorValueTempRH = 0;   

int hitFlag = 0;

int timer = 0;
int timerTemp = 0;

void setup() 
{
  Serial.begin(19200);
}

void loop() 
{
  hitFlag = 0;
  
  // read the analog in value:
  sensorValueLL = analogRead(padLL);
  sensorValueRL = analogRead(padRL);
  sensorValueLH = analogRead(padLH);
  sensorValueMH = analogRead(padMH);
  sensorValueRH = analogRead(padRH);

  // Threshold check
  if ( sensorValueLL >= thrLL ) hitFlag = 1;
  if ( sensorValueRL >= thrRL ) hitFlag = 1;
  if ( sensorValueLH >= thrLH ) hitFlag = 1;
  if ( sensorValueMH >= thrMH ) hitFlag = 1;
  if ( sensorValueRH >= thrRH ) hitFlag = 1;
  
  // (dev code) print the results to the serial monitor:
  if ( hitFlag == 1 )
  {
    //Serial.print("padLL: " ); Serial.print(sensorValueLL);
    //Serial.print("\tpadRL: " ); Serial.print(sensorValueRL);
    //Serial.print("\tpadLH: " ); Serial.print(sensorValueLH);
    //Serial.print("\tpadMH: " ); Serial.print(sensorValueMH);
    //Serial.print("\tpadRH: " ); Serial.println(sensorValueRH);

    timer = millis();
    while(1)
    {
      timerTemp = millis();
      if ( timerTemp - timer > 100 ) break;
    }
  }

  if ( sensorValueMH >= thrMH ) Serial.print("4");
  else if ( sensorValueLH >= thrLH ) Serial.print("3"); 
  else if ( sensorValueRH >= thrRH ) Serial.print("5");
  else if ( sensorValueLL >= thrLL ) Serial.print("1");
  else if ( sensorValueRL >= thrRL ) Serial.print("2");
  
  hitFlag = 0;
}
