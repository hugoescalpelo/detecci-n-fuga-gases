/*
 * Autor: Hugo Escalpelo
 * Fecha: 14 de febrero de 2022
 * 
 * Este programa realiza la lecura del sensor MQ-6 y MLX90614
 * y envia dichas lecturas por serial desde el ESP32CAM. Este
 * se conectara por serial con la raspberry Pi, la cual enviará 
 * los datos por MQTT al servidor (maquina virtual), en donde
 * seran graficadas y en donde se encuentra la base de datos,
 * etc.
 * 
 * Circuito
 * 
 * MLX      MQ6     ESP32CAM
 * VCC--------------5V
 * GND--------------GND
 * SDA--------------14
 * SCL--------------15
 *          VCC-----5V
 *          GND-----GND
 *          A0------12
 *          
 */
//Bibliotecas
#include <Adafruit_MLX90614.h>

//Objetos
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Variables
int lecturaMQ6; //Aqui se guarda el dato del sensor mq6
int lecturaMLX; //Aqui se guarda el dato del sensor mlx
int mq6 = 12; //Aqui se conecta el sensor

void setup() {
  // Iniciar comunicacion serial
  Serial.begin (115200);
  // Serial.println ("Inicio"); //Desactivado a proposito, solo usamos los datos

  //Configuración del Pin analogico como entrada
  //pinMode (mq6, INPUT); // Desactivado a proposito

  //Iniciar comunicación con el sensor
  Wire.begin (14,15);
  if (!mlx.begin(0x5A, &Wire)) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
  
  //Espera (Opcional)
  delay (1000); //Espera de temperatura nominal del mq-6

}

void loop() {
  // Leer sensores
  lecturaMQ6 = analogRead (mq6);
  lecturaMLX = mlx.readObjectTempC();

  //Envio de datos
  Serial.print (lecturaMLX);
  Serial.print (",");
  Serial.println (lecturaMQ6);  
  delay (1000);

}
