#include "DHT.h"
#include "UbidotsMicroESP8266.h"
#define DHTPIN D2
#define TOKEN "BBFF-d6NzUdeSOeAifa6gfZ00BKqv6YRaxl"
#define ssid "Gazebo"
#define Psswd "juli2020"
DHT dht(DHTPIN, DHT11);
Ubidots client(TOKEN);
unsigned long last =0;

void setup() {

 
    Serial.println(9600);
    dht.begin();
    delay(1000);
    client.wifiConnection(ssid,Psswd);
    
}

void loop() {
    if (millis()-last>100){
    float hum = dht.readHumidity();

    float temp = dht.readTemperature();

    last=millis();

    client.add("kelembapan" ,hum);
    client.add("Temp",temp);
    client.sendAll(true);
    }
}
