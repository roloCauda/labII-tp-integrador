#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "Reproductor.h"


class Menu: public BaseObject
{
    private:
        int _opcionMenu=1;
        Reproductor r;
    public:
        Menu();
        void update(int &_opcionesJuego, sf::Event* event);
        void gameOver(int &_opcionesJuego);
        void ganaste();
};

#endif // MENU_H
