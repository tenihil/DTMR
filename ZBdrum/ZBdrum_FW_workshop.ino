// Project JBdrum
// Jan 2016, TEAM "DTMR"
// Author : Jisoon Lim (tenihil), Minshik Sohn (surajang)

// Analog in port definition for each piezo drum pad
const int adcPortKick  = A0;
const int adcPortSnare = A1;

// ADC values read from ports
int sensorValueKick  = 0;        
int sensorValueSnare = 0;   

// Threshold value of piezo analog input
const int thrKick  = 100;
const int thrSnare = 100;

int debug = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensorValueKick  = analogRead(adcPortKick);
  sensorValueSnare = analogRead(adcPortSnare);

  if ( sensorValueKick >= thrKick ) {
    if ( debug == 0 ) {
      Serial.print("1");
    }
    else {
      Serial.print("1: KickADC: ");
      Serial.println(sensorValueKick);
    }
    delay(50);
  }
  else if ( sensorValueSnare >= thrSnare ) {
    if ( debug == 0 ) {
      Serial.print("2");
    }
    else {
      Serial.print("2: SnareADC: ");
      Serial.println(sensorValueSnare);
    }
    delay(50);
  }
}
