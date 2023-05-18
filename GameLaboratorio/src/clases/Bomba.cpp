#include "Bomba.h"


Bomba::Bomba()
{
    _texture->loadFromFile("vacio.png");
    _sprite = new sf::Sprite(*_texture);
    _sprite->setTextureRect({0,0,32,48});
}

void Bomba::porExplotar()
{

    timePrevio--;

    _texture->loadFromFile("./src/sprites/bomba.png");
    _sprite->setTexture(*_texture);

    if(timePrevio==0)
    {
        timePrevio=120;
        _estado=explotar;
    }

}

void Bomba::bombaExplotando()
{

    timeExplotando--;

    if (timeExplotando>100)
    {
        _texture->loadFromFile("./src/sprites/explosion1.png");
        _sprite->setTexture(*_texture);
        _sprite->setTextureRect({0,0,38,42});
    }
    else if (timeExplotando>80)
    {
        _texture->loadFromFile("./src/sprites/explosion2.png");
        _sprite->setTexture(*_texture);
        _sprite->setTextureRect({0,0,45,49});
    }
    else if (timeExplotando>60)
    {
        _texture->loadFromFile("./src/sprites/explosion3.png");
        _sprite->setTexture(*_texture);
        _sprite->setTextureRect({0,0,41,42});
    }
    else if (timeExplotando>40)
    {
        _texture->loadFromFile("./src/sprites/explosion4.png");
        _sprite->setTexture(*_texture);
        _sprite->setTextureRect({0,0,41,42});
    }
    else if (timeExplotando>20)
    {
        _texture->loadFromFile("./src/sprites/explosion5.png");
        _sprite->setTexture(*_texture);
    }
    else if (timeExplotando>0)
    {
        _texture->loadFromFile("./src/sprites/explosion6.png");
        _sprite->setTexture(*_texture);
    }
    else if (timeExplotando==0)
    {
        _texture->loadFromFile("vacio.png");
        _sprite->setTexture(*_texture);
        _estado=vacio;
        timeExplotando=120;
    }
}
void Bomba::updateExplotion(){
    if(getEstado()==sinExplotar)
    {
        porExplotar();
    }
    if(getEstado()==explotar)
    {
        r.cargar("./src/sounds/explosion.ogg");
        r.reproducir();
        setEstado(explotando);
    }
    if(getEstado()==explotando)
    {
        bombaExplotando();
    }
}
