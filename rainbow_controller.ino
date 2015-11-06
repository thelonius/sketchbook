// These constants won't change:
int sensorPin = 1;     // pin that the sensor is attached to
int gPin = 6;
int bPin = 7; 
int rPin = 8;

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 640;  // minimum sensor value
int sensorMax = 840;     // maximum sensor value
int middle = (sensorMin + sensorMax) / 2;
int rScale = 0;
int bScale = 0;
int gScale = 0;

void setup() {
  // turn on LED to signal the start of the calibration period:
 // pinMode(bPin, OUTPUT);
 // digitalWrite(bPin, LOW);

  // calibrate 
 // while (millis() < 2000) {
      sensorValue = analogRead(sensorPin);

  // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorValue = sensorMax;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorValue = sensorMin;
    }
  //}

  // signal the end of the calibration period
 // digitalWrite(bPin, HIGH);
}

void loop() {
  // read the sensor:
  
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  
  sensorValue = ((abs(middle - analogRead(sensorPin)) + 1) * 2);

  // apply the calibration to the sensor reading


  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
  
  gScale = sensorValue;
  
  if (analogRead(sensorPin) < middle)
  {
    rScale = 255 - sensorValue;
  }
  else
  {
    rScale = 255;
  }
  if (analogRead(sensorPin) >= middle)
  {
    bScale = 255 - sensorValue;
  }
  else
  {
    bScale = 255;
  }
  // fade the LED using the calibrated value:
  analogWrite(gPin, gScale);
  analogWrite(rPin, rScale);
  analogWrite(bPin, bScale);
}
