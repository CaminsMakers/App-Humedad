#include <SoftwareSerial.h>

#define rxPin 1
#define txPin 2


SoftwareSerial BTSerial (rxPin, txPin);

int sensor = A5;
int valor_sensor = 0;
int mapeo = 0;
int humedad = 0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {
//Serial.println("Sensor value =");
valor_sensor = analogRead(sensor);
//Serial.println(valor_sensor);

if (valor_sensor>=160 && valor_sensor <=800){
mapeo=map(valor_sensor, 160, 800, 0, 100);
if (mapeo==0)  {humedad=0;}
else if (mapeo<5) {humedad=0;}
else if (mapeo>=5 && mapeo<=15) {humedad=10;}
else if (mapeo>15 && mapeo<=25) {humedad=20;}
else if (mapeo>25 && mapeo<=35) {humedad=30;}
else if (mapeo>35 && mapeo<=45) {humedad=40;}
else if (mapeo>45 && mapeo<=55) {humedad=50;}
else if (mapeo>55 && mapeo<=65) {humedad=60;}
else if (mapeo>65 && mapeo<=75) {humedad=70;}
else if (mapeo>75 && mapeo<=85) {humedad=80;}
else if (mapeo>85 && mapeo<=95) {humedad=90;}
else if (mapeo>95) {humedad=100;}
}
else humedad=0;


//Serial.println("Humedad =");
//Serial.println(valor_sensor);
//Serial.println(mapeo);
Serial.println(humedad);
//Serial.println("%");
//Serial.write(humedad);
delay(1000);

}
