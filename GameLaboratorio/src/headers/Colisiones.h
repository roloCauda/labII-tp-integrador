#ifndef COLISIONES_H
#define COLISIONES_H
#include <SFML/Graphics.hpp>

class Colisiones
{
public:
    virtual sf::FloatRect getBounds() const = 0;
    bool colisiono(Colisiones &col);
};

#endif // COLISIONES_H
