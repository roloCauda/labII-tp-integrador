#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include <cstring>
enum flechas{ up,down,left,right};

class Map
{
public:
    Map();
    sf::Sprite getSprite()
    {
        return *_sprite;
    }
    void segundoMapa();
    void tercerMapa();
    std::string _spriteColision;
    bool vaAColisionar(sf::Vector2i pos,flechas direccion);

private:
    sf::Sprite *_sprite ;
    sf::Texture *_texture;
    sf::Image _imagenColision;
    sf::Color _colorPixel;
};
#endif // MAP_H
