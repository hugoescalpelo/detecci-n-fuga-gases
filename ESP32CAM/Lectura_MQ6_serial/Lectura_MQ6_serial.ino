/*
 * Autor: Hugo Vargas
 * Fecha: 11 de febrero de 2022
 * 
 * Este programa lee el sensor mq6, el cual es un sensor de gas LP
 * y funciona con una lectura analógica
 * 
 * MQ6      ESP32CAM      FTDI
 * VCC -------------------VCC
 * GND--------------------GND
 * A0-------GPIO12
 * 
 */

//Variables
int lectura; //Aqui se guarda el dato del sensor
int mq6 = 12; //Aqui se conecta el sensor

//Inicializacion del programa
void setup() {
  //se inicia comunicación serial
  Serial.begin (115200);
  Serial.println ("Programa iniciado");

  //Configuracinó del Pin analogico como entrada
  pinMode (mq6, INPUT);

  //Espera (Opcional)
  delay (1000);
}

//Cuerpo del programa
void loop() {
  // put your main code here, to run repeatedly:
  lectura = analogRead (mq6);
  //Serial.println (lectura);
  if (lectura > 600) {
    Serial.println ("1");
  } else {
    Serial.println ("0");
  }
  delay (2000); //Espera de 2 segundos
}
