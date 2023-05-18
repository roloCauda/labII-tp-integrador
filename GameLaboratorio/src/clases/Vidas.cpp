#include "Vidas.h"

Vidas::Vidas()
{
    _texture = new sf::Texture;
    _texture->loadFromFile("./src/sprites/corazon.png");
    _sprite = new sf::Sprite(*_texture);
    _sprite->setPosition (50,13);

    cantidadVidas=3;
}


void Vidas::descontar()
{

    if (cantidadVidas>=0 && cantidadVidas<=3)
    {
        cantidadVidas--;
    }
}
int Vidas::getCantidadVidas()
{
    return cantidadVidas;
}

void Vidas::setVidas(int v)
{
    cantidadVidas = 3;
}

