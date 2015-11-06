
int sensorValue = 0;
int rScale = 0;
int bScale = 0;
int gScale = 0;

void setup() {
  sensorValue = analogRead(1);
  }

void loop() {
  sensorValue = 1.95*abs(711 - analogRead(1));
  sensorValue = constrain(sensorValue, 0, 255);
  gScale = sensorValue;
  
      if (analogRead(1) < 711)
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
      delay(200);
  
      if (analogRead(1) < 615)
      {
      analogWrite(5, 0);
      delay(100);
      analogWrite(5, 255);
      delay(200);
      }
  }

