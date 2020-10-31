#include <DHT.h>
#define Type DHT11
int sensePin=2;
int setTime=500;
int dt=1000;
int red = 8;
int blue = 9;
int hum = 10;
int running;





DHT HT (sensePin,Type);
float humidity;
float tempC;
float tempF;

void setup() {
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(hum, OUTPUT);
  
Serial.begin(9600);
HT.begin();
delay(setTime);
}

void loop() {
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" Temperature " );
  Serial.print(tempC);
  Serial.println (" C ");
  delay(dt);

if ((tempC) < 20.5)
{digitalWrite(red, HIGH);}
else 
  {digitalWrite(red, LOW);
}

if ((humidity) < 93) && running == false;
{(digitalWrite(hum, HIGH));
delay(1000);
digitalWrite(hum, LOW);
digitalWrite(blue,HIGH);
running == true;
else
digitalWrite(blue,LOW);

  
}
  


  
  

  
  // put your main code here, to run repeatedly:
