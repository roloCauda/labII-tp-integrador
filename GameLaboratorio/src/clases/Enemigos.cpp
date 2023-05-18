#include "../headers/Enemigos.h"

Enemigos::Enemigos(sf::Vector2i posInicial, sf::Vector2i posFinal, bool isMovHorizontal)
{
    _texture->loadFromFile("./src/sprites/guardias.png");
    _sprite = new sf::Sprite(*_texture);
    _sprite->setTextureRect({0,0,31,32});
    _sprite->setPosition(posInicial.x,posInicial.y);
    _frame=0;
    _posInicial = posInicial;
    _posFinal = posFinal;
    _isMovHorizontal = isMovHorizontal;

    if(isMovHorizontal)  //va de izquierda a derecha
    {
        _velocidad = {1,0};
        _frameY=2;
    }

    if(!isMovHorizontal)
    {
        _velocidad = {0,1};
        _frameY=0;
    }
}

void Enemigos::update()
{

    _frame += 0.2;
    if (_frame>=3)
    {
        _frame = 0;
    }

    _sprite->setTextureRect({0 + int (_frame) * 31,  0 + int (_frameY) * 32, 31,32});
    _sprite->move(_velocidad);

    if(_isMovHorizontal)
    {
        if (_sprite->getPosition().x<_posInicial.x)
        {
            _velocidad.x= -_velocidad.x;
            _frameY= 2;
        }
        if (_sprite->getPosition().x + _sprite->getGlobalBounds().width > _posFinal.x )
        {
            _velocidad.x = -_velocidad.x;
            _frameY = 1;
        }
    }

    if(!_isMovHorizontal)
    {
        if (_sprite->getPosition().y<_posInicial.y)
        {
            _velocidad.y= -_velocidad.y;
            _frameY= 0;
        }
        if (_sprite->getPosition().y + _sprite->getGlobalBounds().width > _posFinal.y )
        {
            _velocidad.y = -_velocidad.y;
            _frameY = 3;
        }
    }
}
