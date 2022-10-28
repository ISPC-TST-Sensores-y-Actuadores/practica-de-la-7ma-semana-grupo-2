//Codigo para el remitente - arduino - loRa - DHT11

#include <SPI.h>
#include <LoRa.h> // Libreria comunicacion LoRa
#include <DHT.h>  // Sensor DHT11

#define DHTPIN A0 // pin conectado
#define TIPO DHT DHT11 // DHT11

DHT dht(DHTPIN, DHTTYPE);

int sonar;

float temp; //Almacena el valor de la temperatura

int contador = 0;

void setup() {  

  Serial.begin(9600);

  dht.begin();

  while (!Serial);
    Serial.println("LoRa Remitente");

    if (!LoRa.begin(433E6)) {

      Serial.println("Starting LoRa failed!");
      while (1);
   }
}

void loop() {
  temp = dht.readTemperature();
  sonar = dht.leerHumedad();

  Serial.print("Enviando paquete: ");
  Serial.println(contador);
  LoRa.beginPacket();
  LoRa.print("Humedad: ");
  LoRa.print(hum);
  LoRa.print("c");
  LoRa.print("Temperatura:");
  LoRa.print(temp);
  LoRa.endPacket();

  contador++;

  retraso (5000);

}
