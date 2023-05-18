#include "Map.h"

Map::Map()
{
    _texture = new sf::Texture;
    _texture->loadFromFile("./src/sprites/mapa.jpg");
    _spriteColision = "./src/sprites/mapa-colisiones.png";
    _sprite = new sf::Sprite(*_texture);
    _imagenColision.loadFromFile("./src/sprites/mapa-colisiones.png");
}

void Map::segundoMapa(){
    _texture->loadFromFile("./src/sprites/mapa_2.jpg");
    _imagenColision.loadFromFile("./src/sprites/mapa-colisiones_2.png");
    _sprite->setTexture(*_texture);
}

void Map::tercerMapa(){
    _texture->loadFromFile("./src/sprites/mapa_3.jpeg");
    _imagenColision.loadFromFile("./src/sprites/mapa-colisiones_3.png");
    _sprite->setTexture(*_texture);
}

bool Map::vaAColisionar(sf::Vector2i pos,flechas direccion)
{
    sf::Vector2i pixels;
    pixels.x=pos.x;
    pixels.y=pos.y;

    switch(direccion){
        case up: pixels.y=pos.y-4; break;
        case down: pixels.y=pos.y+49; break;
        case left : pixels.x=pos.x-3; break;
        case right: pixels.x=pos.x+33; break;
    }

    _colorPixel = _imagenColision.getPixel(pixels.x,pixels.y);

    return _colorPixel.toInteger()==255;
}
