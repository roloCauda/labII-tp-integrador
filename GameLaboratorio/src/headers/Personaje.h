#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML\Graphics.hpp>
#include "Colisiones.h"
#include "Bomba.h"
#include "Map.h"
#include <SFML/Graphics/Color.hpp>

class Personaje : public BaseObject
{

private:
    float _velocity;
    float _frame;
    int _frameY;

public:
    Personaje();
    void update (Bomba *bomba, Map *mapa);
    sf::Vector2i getPosicion()
    {
        return sf::Vector2i(
            static_cast<int>(_sprite->getPosition().x),
            static_cast<int>(_sprite->getPosition().y)
        );
    }
    bool vaAColisionar();
};

#endif // PERSONAJE_H
