#include <IRremote.h>
#include "TransmisorInfrarrojos.h"
#include <Arduino.h>

TransmisorInfrarrojos::TransmisorInfrarrojos(IRsend irsend){ //Constructor
    this->irsend = irsend; 
  }

  IRsend TransmisorInfrarrojos::inicializacionTI(){
    Serial.begin(9600);
    IRsend irsend;
    return irsend;
  }
  
  IRsend TransmisorInfrarrojos::envio(IRsend irsend) {
    for (int i = 0; i < 50; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     delay(40);
    }
  }
