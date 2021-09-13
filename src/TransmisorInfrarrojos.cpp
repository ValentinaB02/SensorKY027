#include <IRremote.h>
#include <IRremoteInt.h>
#include "TransmisorInfrarrojos.h"
#include <Arduino.h>

TransmisorInfrarrojos::TransmisorInfrarrojos(IRsend irsend){ //Constructor
    this->irsend = irsend;
  }

  void TransmisorInfrarrojos::inicializacionTI(){
    Serial.begin(9600); 
  }
  
  void TransmisorInfrarrojos::envio()){
    for (int i = 0; i < 50; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     delay(40); 
  }
