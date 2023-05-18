#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <SFML\Graphics.hpp>
#include "BaseObject.h"
#include "Colisiones.h"

class Enemigos : public BaseObject
{

private:
    sf::Vector2f _velocidad;
    sf::Vector2f _posicion;
    sf::Vector2i _posInicial;
    sf::Vector2i _posFinal;
    int _time;
    float _frame;
    int _frameY=0;
    bool _isMovHorizontal;

public:
    Enemigos(sf::Vector2i posInicial,sf::Vector2i posFinal, bool isMovHorizontal);
    void update ();
};

#endif // ENEMIGOS_H
