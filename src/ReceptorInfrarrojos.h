#include <Arduino.h>
#ifndef RECEPTORINFRARROJOS_H
#define RECEPTORINFRARROJOS_H

class ReceptorInfrarrojos {
private:
int RECVPIN;
decode_results results;

public:
ReceptorInfrarrojos(int RECVPIN); //Constructor
IRrecv inicializacionRI();
IRrecv resultados(IRrecv irrecv);

};

#endif
