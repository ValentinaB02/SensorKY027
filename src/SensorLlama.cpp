#include "SensorLlama.h"
#include <Arduino.h>

SensorLlama::SensorLlama(int digitalPin, int analogPin, int led2){ //Constructor
    this->digitalPin = digitalPin;
    this->analogPin = analogPin;
    this->led2 = led2;
  }

  void SensorLlama::initialization(){
    Serial.begin(9600);
    pinMode(digitalPin, INPUT); 
    pinMode(led2, OUTPUT); 
  }

  void SensorLlama::detection(){
      int estado = digitalRead(digitalPin);
      if (estado == HIGH) {
      Serial.println("Alarma: Detección");
      }
      delay(1000);
  }

  int SensorLlama::measurement(){
      int lectura = analogRead(analogPin);
      Serial.println(lectura);
      delay (1000);
      return lectura;
  }

  int SensorLlama::LEDdetection(int lectura){
      if(lectura < 500) { // Detección de flama para rangos establecidos
      digitalWrite(led2, HIGH); // Enciende el LED a modo de alarma      
      } else {
          digitalWrite(led2, LOW); // Apaga el LED
          }
  }