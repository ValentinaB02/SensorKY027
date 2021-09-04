#include <Arduino.h>
#ifndef SENSORINCLINACION_H
#define SENSORINCLINACION_H

class SensorInclinacion {
private:
int led;
int sensor;
int estadoSensor;
int brightness;

public:
SensorInclinacion(int led, int sensor); //Constructor
void inicializacion();
void deteccion();
int setBrightness();
int setBrightnessLed(int brightness);

};

#endif
