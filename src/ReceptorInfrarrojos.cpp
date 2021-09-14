#include <IRremote.h>
#include "ReceptorInfrarrojos.h"
#include <Arduino.h>

ReceptorInfrarrojos::ReceptorInfrarrojos(int RECVPIN){ //Constructor
    this->RECVPIN = RECVPIN;
  }

  IRrecv ReceptorInfrarrojos::inicializacionRI(){
    Serial.begin(9600);   
    IRrecv irrecv(RECVPIN); 
    irrecv.enableIRIn(); // Inicia el receptor
    return irrecv;
  }
  
  IRrecv ReceptorInfrarrojos::resultados(IRrecv irrecv){
    if (irrecv.decode(&results)) {
		Serial.println(results.value, HEX); 
		irrecv.resume();
	}
	delay (100);
  }
