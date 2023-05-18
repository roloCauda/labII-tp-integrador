#include "BaseObject.h"

void BaseObject::setPosition(sf::Vector2i posicion)
{
    _sprite->setPosition(posicion.x,posicion.y);
}

sf::FloatRect BaseObject::getBounds() const
{
    return _sprite->getGlobalBounds();
}

void BaseObject::draw (sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(*_sprite, states);
}
