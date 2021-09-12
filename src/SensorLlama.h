#include <Arduino.h>
#ifndef SENSORLLAMA_H
#define SENSORLLAMA_H

class SensorLlama {
private:
int led2;
int digitalPin;
int analogPin;
int estado;
int lectura;

public:
SensorLlama(int digitalPin, int analogPin, int led2); //Constructor
void initialization();
void detection();
int measurement();
int LEDdetection(int lectura);

};

#endif
