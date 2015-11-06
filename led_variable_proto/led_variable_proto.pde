

int rPin = 12;  
int gPin = 11;  
int bPin = 10;  

int analogInput = 0;
int val = 0;


int umin = 471;
int umax = 961;


void setup(){};

void loop()
{
val = analogRead(analogInput) - 470 ;
analogWrite(gPin, 255 - (val / 2)) ;
}
