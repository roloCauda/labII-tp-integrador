#include "Cajas.h"


Cajas::Cajas()
{
    _texture->loadFromFile("./src/sprites/cajas.png");
    _sprite = new sf::Sprite(*_texture);
}

