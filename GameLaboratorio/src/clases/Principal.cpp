#include "Principal.h"
#include "Bomba.h"

void Principal::obenerLlave(int cant = 1)
{
    _llavesObtenidas+=cant;
}

int Principal::getCantidadLlavesObtenidas()
{
    return _llavesObtenidas;
}


