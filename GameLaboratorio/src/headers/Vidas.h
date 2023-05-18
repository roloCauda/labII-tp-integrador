#ifndef VIDAS_H
#define VIDAS_H
#include <SFML\Graphics.hpp>
#include "BaseObject.h"


class Vidas: public BaseObject
{
private:
    int cantidadVidas;
public:
    Vidas();
    void descontar();
    int getCantidadVidas();
    void setVidas(int v);
};

#endif // VIDAS_H
