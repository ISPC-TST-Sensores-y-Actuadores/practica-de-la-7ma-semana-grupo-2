
//Receptor Arduino con LoRa y modulo LCD
#include <SPI.h>
#include <LoRa.h> // libreria comunicacion LoRa
#include <Cristal Liquido.h>

//numero de pin para la conexion LCD
const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 3; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);//metodo LCD

void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);

  while (!Serial);

  Serial.println("Receptor LoRa");
  if (!LoRa.begin(433E6)) {
    Serial.println("¡Error al iniciar LoRa!");
    while (1);
  }
}

void loop() {

  // analizar paquete
  int TamanoPaquete = LoRa.parsePacket();

  if (TamanoPaquete) {

    // se recibio el paquete
    Serial.print("se recibio el paquete '");

    // leo paquete
    while (LoRa.disponible()) {

      char entrante = (char)LoRa.read();
      if (entrante == 'c'){
        lcd.setCursor(0, 1);
      }
      else {
        lcd.print(entrante);
      }
    }
  }
