#include "SensorInclinacion.h"
#include <Arduino.h>

SensorInclinacion::SensorInclinacion(int led, int sensor){ //Constructor
    this->led = led;
    this->sensor = sensor;
  }

  void SensorInclinacion::inicializacion(){
    pinMode(led, OUTPUT); 
    pinMode(sensor, INPUT);
    digitalWrite(sensor, HIGH);
    digitalWrite(estadoSensor, LOW);    
  }

  void SensorInclinacion::deteccion(){
     estadoSensor = digitalRead(sensor);
     if (estadoSensor == HIGH){
       digitalWrite (led, HIGH); //Se enciende el LED cuando detecta inclinación alguna
       brightness = 255;
       } else {
         digitalWrite (led, LOW);
         brightness = 0;
         }
    }

  int SensorInclinacion::setBrightness(){
     estadoSensor = digitalRead(sensor);
      if (estadoSensor == HIGH && brightness != 0){
        brightness --;
      } else if (estadoSensor == LOW && brightness != 255){
        brightness ++;
      }
      return brightness;
    }

    int SensorInclinacion::setBrightnessLed(int brightness){
      analogWrite(led, brightness);      
    }