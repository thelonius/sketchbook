
int sensorValue = 0;
int rScale = 0;
int bScale = 0;
int gScale = 0;

void setup() {
  sensorValue = analogRead(1);
  }

void loop() {
  sensorValue = 2.65*abs(747 - analogRead(1));
  sensorValue = constrain(sensorValue, 0, 255);
  gScale = sensorValue;
  
      if (analogRead(1) < 747)
      {
        rScale = 255 - sensorValue;
        bScale = 255;
      }
      else
      {
        bScale = 255 - sensorValue;
        rScale = 255;
      }
 
      analogWrite(7, gScale);
      analogWrite(5, rScale);
      analogWrite(6, bScale);
      delay(300);
  
      if (analogRead(1) < 635)
      {
      analogWrite(5, 0);
      delay(100);
      analogWrite(5, 255);
      delay(200);
      }
  }

