/***************************************************
  Autor: Hugo Escalpelo
  Fecha: 14 de febrero de 2022

  Este programa hace una comunicacinó simple

  MLX   ESP32CAM
  VCC---5V
  GND---GND
  SDA---14
  SCL---15
 ****************************************************/
//Bliblioteca
#include <Adafruit_MLX90614.h>

//Objejos
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Inicialización del programa
void setup() {
  //Iniciar comunicacion serial
  Serial.begin(115200);
  while (!Serial);

  //Mensaje de prueba
  Serial.println("Adafruit MLX90614 test");

  //Iniciar comunicación con el sensor
  Wire.begin (14,15);
  if (!mlx.begin(0x5A, &Wire)) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
}

//Cuerpo del programa
void loop() {
  //Leer el sensor
  Serial.println(mlx.readObjectTempC());

  //Cada 500ms
  delay(500);
}
