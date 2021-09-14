#include <Arduino.h>
#include <SensorInclinacion.h>
#include <SensorLlama.h>
#include <ReceptorInfrarrojos.h>
#include <TransmisorInfrarrojos.h>
#include <SensorTempHum.h>
#include <IRremote.h>

//APLICACIÓN: Laboratorio o fábrica cuyos procesos llevados a cabo o de manufactura requieren detectar
//temperaturas, humedad en el sistema, inclinaciones, detector de llama e infrarrojos.

int brightnessSensor1;
int brightnessSensor2;
int lecturaSensor3;
IRsend irsend1;
IRrecv irrecv1;
byte result1;
byte result2;
byte result3;
SensorInclinacion sensor1(9,8); //Creación objetos
SensorInclinacion sensor2(6,7);
SensorLlama sensor3(13,A0,10);
SensorInclinacion sensor4(11,12);
SensorInclinacion sensor5(3,4);
ReceptorInfrarrojos sensor6(5);
TransmisorInfrarrojos sensor7(irsend1);
SensorTempHum sensor8(11); //Debido a que se acabaron los pines del Arduino Uno repito
SensorTempHum sensor9(12); //Debido a que se acabaron los pines del Arduino Uno repito
SensorTempHum sensor10(13); //Debido a que se acabaron los pines del Arduino Uno repito

void setup() {
  sensor1.inicializacion();
  sensor2.inicializacion();
  brightnessSensor1 = 0;
  sensor3.initialization();  
  irsend1 = sensor7.inicializacionTI();
  irrecv1 = sensor6.inicializacionRI();
  sensor8.inicializacionSTH();
  sensor9.inicializacionSTH();
  sensor10.inicializacionSTH();
}

void loop() {
  //Código funcional magic cup light effect. Se evalúa la señal del sensor 1 y en base a esto
  //se modifica el brightness del sensor 2 para generar la ilusión de transmisión de luz de un sensor a otro.
  sensor1.deteccion();
  brightnessSensor1 = sensor1.setBrightness();
  sensor1.setBrightnessLed(brightnessSensor1);
  delay (2000);
  sensor2.setBrightnessLed(255- brightnessSensor1);
  delay (2000);
  //Otra aplicación puede emplear solo los métodos de deteccion con cada sensor para detectar las inclinaciones
  //en cada uno y encender o apagar sus LEDs  a modo de indicativo según corresponda.
  sensor3.detection();
  lecturaSensor3 = sensor3.measurement();
  sensor3.LEDdetection(lecturaSensor3);
  delay (1500);
  sensor4.deteccion();
  sensor5.deteccion();
  sensor7.envio(irsend1);
  sensor6.resultados(irrecv1);
  result1 = sensor8.readdata();
  result2 = sensor9.readdata();
  result3 = sensor10.readdata();
  sensor8.start_test(result1);
  sensor9.start_test(result2);
  sensor10.start_test(result3);
  sensor8.humedad();
  sensor9.humedad();
  sensor10.humedad();
  sensor8.temperatura();
  sensor9.temperatura();
  sensor10.temperatura();
  
}