#include <IRremote.h>
#include <IRremoteInt.h>
#include "ReceptorInfrarrojos.h"
#include <Arduino.h>

ReceptorInfrarrojos::ReceptorInfrarrojos(int RECVPIN){ //Constructor
    this->RECVPIN = RECVPIN;
  }

  void ReceptorInfrarrojos::inicializacionRI(){
    Serial.begin(9600);
    irrecv.enableIRIn(); // Inicia el receptor
  }
  
  void ReceptorInfrarrojos::resultados(){
    if (irrecv.decode(&results)) {
		Serial.println(results.value, HEX); 
		irrecv.resume();
	}
	delay (100);
  }
