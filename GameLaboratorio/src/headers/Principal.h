#include "Personaje.h"
#include "Bomba.h"
#include "Vidas.h"

class Principal : public Personaje
{
public:
    int getCantidadLlavesObtenidas();
    void obenerLlave(int cant);
    Principal():Personaje() {};
    void controlAcciones(sf::RenderWindow *ventana);


private:
    int _llavesObtenidas=0;
};
