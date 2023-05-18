#include "../headers/Llave.h"

Llave::Llave(sf::Vector2i posInicial)
{
    _texture->loadFromFile("./src/sprites/key.png");
    _sprite = new sf::Sprite(*_texture);
    _sprite->setPosition(posInicial.x,posInicial.y);
}

void Llave::setNoVisible()
{
    _visible=false;
}

bool Llave::isVisible()
{
    return _visible;
}

Llave::~Llave() {}
