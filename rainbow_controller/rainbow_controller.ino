// These constants won't change:
//int sensorPin = 1;     // pin that the sensor is attached to
//int gPin = 7;
//int bPin = 6; 
//int rPin = 5;

// variables:
int sensorValue = 0;         // the sensor value
//int sensorMin = 640;  // minimum sensor value
//int sensorMax = 840;     // maximum sensor value
//int middle = (sensorMin + sensorMax) / 2;
int rScale = 0;
int bScale = 0;
int gScale = 0;

void setup() {
  
  //pinMode(1, INPUT);


  sensorValue = analogRead(1);

  // record the maximum sensor value
  //if (sensorValue > sensorMax) {
   // sensorValue = sensorMax;
  //}

  // record the minimum sensor value
  //if (sensorValue < sensorMin) {
   // sensorValue = sensorMin;
 // }

 }

void loop() {

  //sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  sensorValue = 3*abs(760 - analogRead(1));

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  gScale = sensorValue;
  
  if (analogRead(1) < 760)
  {
    rScale = 255 - sensorValue;
  }
  else
  {
    rScale = 255;
  }
  if (analogRead(1) >= 760)
  {
    bScale = 255 - sensorValue;
  }
  else
  {
    bScale = 255;
  }
  // fade the LED using the calibrated value:
  analogWrite(7, gScale);
  analogWrite(5, rScale);
  analogWrite(6, bScale);
  delay(2000);
}

