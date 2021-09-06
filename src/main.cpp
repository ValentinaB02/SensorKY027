#include <Arduino.h>
#include <SensorInclinacion.h>

SensorInclinacion sensor1(9,8); //Creación objetos
SensorInclinacion sensor2(6,7);
int brightnessSensor1;
int brightnessSensor2;

void setup() {
  sensor1.inicializacion();
  sensor2.inicializacion();
  brightnessSensor1 = 0;
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
}