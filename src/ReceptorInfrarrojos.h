#include <Arduino.h>
#ifndef RECEPTORINFRARROJOS_H
#define RECEPTORINFRARROJOS_H

class ReceptorInfrarrojos {
private:
int RECVPIN;
IRrecv irrecv(RECVPIN); 
decode_results results;

public:
ReceptorInfrarrojos(int RECVPIN); //Constructor
void inicializacionRI();
void resultados();

};

#endif
