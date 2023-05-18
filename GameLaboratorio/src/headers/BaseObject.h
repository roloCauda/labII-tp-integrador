#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <SFML/Graphics.hpp>
#include "Colisiones.h"

class BaseObject: public Colisiones, public sf::Drawable
{
    protected:
        sf::Texture *_texture = new sf::Texture();
        sf::Sprite *_sprite;
    public:
        sf::Texture getTexture() { return *_texture; }
        sf::Sprite getSprite() { return *_sprite; }
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds () const override;
        void setPosition(sf::Vector2i posicion);
};

#endif // BASEOBJECT_H
