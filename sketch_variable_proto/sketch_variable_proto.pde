/*
  Calibration
 
 Demonstrates one techinque for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.
 
 The sensor minumum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything 
 lower, saving it as the new minumum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.
 
 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground
 
 created 29 Oct 2008
 By David A Mellis
 Modified 17 Jun 2009
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Calibration
 
 */

// These constants won't change:
const int sensorPin = 0;     // pin that the sensor is attached to
const int gPin = 10;
const int bPin = 9; 
const int rPin = 11;

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 0;  // minimum sensor value
int sensorMax = 1023;     // maximum sensor value
int rScale = 0;
int bScale = 0;

void setup() {
  // turn on LED to signal the start of the calibration period:
 // pinMode(bPin, OUTPUT);
 // digitalWrite(bPin, LOW);

  // calibrate 
 // while (millis() < 2000) {
   // sensorValue = analogRead(sensorPin);

  // record the maximum sensor value
   // if (sensorValue > sensorMax) {
    //  sensorMax = sensorValue;
   // }

    // record the minimum sensor value
   // if (sensorValue < sensorMin) {
   //   sensorMin = sensorValue;
   // }
  //}

  // signal the end of the calibration period
 // digitalWrite(bPin, HIGH);
}

void loop() {
  // read the sensor:
  sensorValue = ((abs(512 - analogRead(sensorPin)) + 1) * 2);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
  
  if (analogRead(sensorPin) < 512)
  {
    rScale = 255 - sensorValue;
  }
  else
  {
    rScale = 255;
  }
  if (analogRead(sensorPin) >= 512)
  {
    bScale = 255 - sensorValue;
  }
  else
  {
    bScale = 255;
  }
  // fade the LED using the calibrated value:
  analogWrite(gPin, sensorValue);
  analogWrite(rPin, rScale);
  analogWrite(bPin, bScale);
}
