#include <Arduino.h>
#ifndef SENSORTEMPHUM_H
#define SENSORTEMPHUM_H

class SensorTempHum {
private:
int DHpin;

public:
SensorTempHum(int DHpin); //Constructor
void inicializacionSTH();
byte readdata (byte result);
void humedad();
void temperatura();

};

#endif
