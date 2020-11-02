#include <DHT.h>
#define Type DHT11
int sensePin=2;
int setTime=500;
int dt=1000;
int red = 8; // red Temperature LED
int blue = 9; // Blue Humidity LED
int hum = 10; // Humidifier
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

if ((tempC) < 20.5) // Threshold for fan
{digitalWrite(red, HIGH);} // Turn on Red Tempurature LED, Fan command to be added later.
else 
  {digitalWrite(red, LOW);
}

if ((humidity) < 93) && running == false; // Humidifier threshold
{(digitalWrite(hum, HIGH)); // Press humidifier button through relay
delay(1000);
digitalWrite(hum, LOW); // Release humidifier button through relay
digitalWrite(blue,HIGH); // Turn on Blue humidifier LED
running == true;
else
digitalWrite(blue,LOW); // Turn off Humidifier LED

  
}
  


  
  

