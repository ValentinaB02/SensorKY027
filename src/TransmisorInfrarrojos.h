#include <Arduino.h>
#ifndef TRANSMISORINFRARROJOS_H
#define TRANSMISORINFRARROJOS_H

class TransmisorInfrarrojos {
private:
IRsend irsend;

public:
TransmisorInfrarrojos(IRsend irsend); //Constructor
IRsend inicializacionTI();
IRsend envio(IRsend irsend);

};

#endif
