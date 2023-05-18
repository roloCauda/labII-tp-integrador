#include "../headers/Personaje.h"
Personaje::Personaje()
{
    _texture->loadFromFile("./src/sprites/marine.png");
    _sprite = new sf::Sprite(*_texture);
    _velocity= 4;
    _sprite->setPosition(60,120);
    _sprite->setTextureRect({0,0,32,48});
    _frame = 0;
    _frameY = 0;
}

void Personaje::update(Bomba *bomba, Map *mapa)
{

    _frame += 0.2;

    sf::Vector2i pos = sf::Vector2i((int)_sprite->getPosition().x,(int)_sprite->getPosition().y);

    if (_frame>=4)
    {
        _frame = 0;
    }
    _sprite->setTextureRect({0 + int (_frame) * 32, 0 + int(_frameY)*48, 32,48});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(!mapa->vaAColisionar(pos,up))
        {
            _sprite->move (0,-_velocity);
        };
        _frameY = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(!mapa->vaAColisionar(pos,left))
        {
            _sprite->move (-_velocity, 0);
        };
        _frameY = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(!mapa->vaAColisionar(pos,down))
        {
            _sprite->move (0,_velocity);
        };
        _frameY = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(!mapa->vaAColisionar(pos,right))
        {
            _sprite->move (_velocity,0);
        };
        _frameY = 2;
    }

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _frame=0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bomba->getEstado()==vacio)
    {
        bomba->setEstado(sinExplotar);
    }
}
