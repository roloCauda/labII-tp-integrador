#ifndef LLAVE_H
#define LLAVE_H
#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "Colisiones.h"

class Llave : public BaseObject
{
private:
    bool _visible = true;

public:
    Llave(sf::Vector2i posInicial);
    ~Llave();
    void update();
    void setNoVisible();
    bool isVisible();
};

#endif // LLAVE_H
