#include <Arduino.h>
#ifndef SENSORTEMPHUM_H
#define SENSORTEMPHUM_H

class SensorTempHum {
private:
int DHpin;
byte dat[5];

public:
SensorTempHum(int DHpin); //Constructor
void inicializacionSTH();
byte readdata ();
byte start_test(byte result);
void humedad();
void temperatura();

};

#endif
